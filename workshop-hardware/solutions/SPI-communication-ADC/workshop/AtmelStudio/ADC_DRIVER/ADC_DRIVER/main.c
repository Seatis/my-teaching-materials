#include "ADC_driver.h"
#include "UART_driver.h"
#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>

#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#include <avr/delay.h>

#define LED_DDR			DDRB
#define LED_DDR_POS		DDRB5
#define LED_PIN			PINB
#define LED_PIN_POS		PINB5
#define LED_PORT		PORTB
#define LED_PORT_POS	PORTB5

void system_init() {
    // Initialize the LED pin as output
    LED_DDR |= 1 << LED_DDR_POS;
    // Set the LED to off as deafault
    LED_PORT &= ~(1 << LED_PORT_POS);

    // Call the DAC driver init function
    ADC_init();

    // Call the UART driver init function
    // Keep in mind that the UART will run at 115200 baud/sec
    UART_init();

    // Enable interrupts globally, UART uses interrupts
    sei();
}

int main(void) {
    uint16_t adc_data;

    // Don't forget to call the init function :)
    system_init();

    // Setting up STDIO input and output buffer
    // You don't have to understand this!
    //----- START OF STDIO IO BUFFER SETUP
    FILE UART_output = FDEV_SETUP_STREAM(UART_send_character, NULL, _FDEV_SETUP_WRITE);
    stdout = &UART_output;
    FILE UART_input = FDEV_SETUP_STREAM(NULL, UART_get_character, _FDEV_SETUP_READ);
    stdin = &UART_input;
    //----- END OF STDIO IO BUFFER SETUP

    // Try printf
    printf("Startup...\r\n");

    // Infinite loop
    while (1) {
        // ADC tester code
        adc_data = ADC_read();
        //printf("%d\r\n", adc_data);

        // Send data as a number, not as a string.
        // The ADC result has 10bits, but we can only send 8bits at one on UART
        // If we want to display the result on the oscilloscope of the Data Visualizer plugin
        // we have to send the result on 8bits. If we shift down 2 times, we will get the top 8
        // bits of the data.
        UART_send_character(adc_data >> 2);
    }
}
