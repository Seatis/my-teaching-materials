#include "ADC_driver.h"
#include "UART_driver.h"
#include "MCP4821_driver.h"

#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include <stdlib.h>


#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#include <avr/delay.h>

void SystemInit() {
    // Call the ADC driver init function
    ADC_Init();

    // Call the DAC driver init function
    MCP4821_Init();

    // Call the UART driver init function
    // Keep in mind that the UART will run at 115200 baud/sec
    UART_Init();

    // Enable interrupts globally, UART uses interrupts
    sei();
}

int main(void) {
    uint16_t adc_data;
    MCP4821_Data_t dac_data;
    // Initialize dac_data
    dac_data.start_zero = 0;
    dac_data.dont_care = 0;
    dac_data.gain = 0;		//2x
    dac_data.shutdown = 1;	// not shutdown
    dac_data.data = 0x000;
    // Initialize mode state machine

    // Don't forget to call the init function :)
    SystemInit();

    // Setting up STDIO input and output buffer
    // You don't have to understand this!
    //----- START OF STDIO IO BUFFER SETUP
    FILE UART_output = FDEV_SETUP_STREAM(UART_SendCharacter, NULL, _FDEV_SETUP_WRITE);
    stdout = &UART_output;
    FILE UART_input = FDEV_SETUP_STREAM(NULL, UART_GetCharacter, _FDEV_SETUP_READ);
    stdin = &UART_input;
    //----- END OF STDIO IO BUFFER SETUP

    // Try printf
    printf("Startup...\r\n");

    // Infinite loop
    while (1) {

        // ADC tester code
        adc_data = ADC_Read();
        //printf("%d\r\n", adc_data);

        // Send data as a number, not as a string.
        // The ADC result has 10bits, but we can only send 8bits at one on UART
        // If we want to display the result on the oscilloscope of the Data Visualizer plugin
        // we have to send the result on 8bits. If we shift down 2 times, we will get the top 8
        // bits of the data.
        UART_SendCharacter(adc_data >> 2);

        // Check if something is in the UART rx buffer
        if(!UART_IsBufferEmpty()) {
            char str[32];
            gets(str);
            float voltage = atof(str);
            // Check min/max borders
            if(voltage < U_MIN) {
                voltage = U_MIN;
            }
            if(voltage > U_MAX) {
                voltage = U_MAX;
            }
            // voltage * DATA_MAX / refvoltage / gain
            dac_data.data = (uint16_t)(MCP4821_DATA_MAX * voltage / 4.096);
            MCP4821_SendData(&dac_data);
        }
    }
}
