#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdlib.h>
#include "TC0_PWM_driver.h"
#include "ADC_driver.h"
#include "UART_driver.h"

#define F_CPU	16000000
#include <avr/delay.h>

void system_init()
{
	// This will initialize the LED pin also!
	TCO_fast_pwm_init();

	UART_init();

	ADC_init();

	sei();
}

int main(void)
{
	system_init();

	// Setting up STDIO input and output buffer
	// You don't have to understand this!
	//----- START OF STDIO IO BUFFER SETUP
	FILE UART_output = FDEV_SETUP_STREAM(UART_send_character, NULL, _FDEV_SETUP_WRITE);
	stdout = &UART_output;
	FILE UART_input = FDEV_SETUP_STREAM(NULL, UART_get_character, _FDEV_SETUP_READ);
	stdin = &UART_input;
	//----- END OF STDIO IO BUFFER SETUP

	while (1) {
		if (!UART_is_buffer_empty()) {
			char command[64];
			gets(command);
			uint8_t duty = atoi(command);
			TC0_set_duty(duty);
		}
	}
}
