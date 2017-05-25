#include "ADC_driver.h"
#include "UART_driver.h"
#include "MCP4821_driver.h"
#include "sine_gen.h"

#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <string.h>


#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#include <avr/delay.h>

void system_init()
{
	// Call the ADC driver init function
	ADC_init();

	// Call the DAC driver init function
	MCP4821_init();

	// Call the UART driver init function
	// Keep in mind that the UART will run at 115200 baud/sec
	UART_init();

	// Initialize sina wave generator module
	sine_gen_init();

	// Enable interrupts globally, UART uses interrupts
	sei();
}

void parse_string(char *str)
{
	char *pch;
	pch = strtok(str, ",");
	float voltage = atof(pch);
	pch = strtok(NULL, "-");
	uint16_t freq = atoi(pch);

	if (voltage < U_MIN)
		voltage = U_MIN;

	if (voltage > U_MAX)
		voltage = U_MAX;

	if (freq < FREQ_MIN)
		freq = FREQ_MIN;

	if (freq > FREQ_MAX)
		freq = FREQ_MAX;

	set_vpp(voltage);
	set_freq(freq);
};


int main(void)
{
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

		// Check if something is in the UART rx buffer
		if (!UART_is_buffer_empty()) {
			char str[32];
			gets(str);
			parse_string(str);
		}
	}
}
