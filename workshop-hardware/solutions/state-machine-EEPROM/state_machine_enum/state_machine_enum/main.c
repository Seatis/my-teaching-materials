#include <avr/io.h>
#include <stdint.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include <string.h>
#include "UART_driver.h"

#define F_CPU 16000000
#include <avr/delay.h>

// TODO:
/* Create an enum type which represents the following program states:
	- LED blinker mode
	- LED-Pushbutton mode
	- LED on mode
	- LED off mode
*/
typedef enum {LED_BLINKER, LED_PUSHBUTTON, TURN_OFF_LED, TURN_ON_LED} program_state_t;

void init()
{
	// Initialize the UART interface with 115200 baud/sec
	UART_init();

	// Initialize the LED pin
	DDRB |= 1 << DDRB5;

	// Enable interrupts globally
	sei();
}

int main(void)
{
	// Don't forget to call the init() function :)
	init();

	// Setting up STDIO input and output buffer
	// You don't have to understand this!
	//----- START OF STDIO IO BUFFER SETUP
	FILE UART_output = FDEV_SETUP_STREAM(UART_send_character, NULL, _FDEV_SETUP_WRITE);
	stdout = &UART_output;
	FILE UART_input = FDEV_SETUP_STREAM(NULL, UART_get_character, _FDEV_SETUP_READ);
	stdin = &UART_input;
	//----- END OF STDIO IO BUFFER SETUP

	// TODO:
	// Create a variable with your custom program state type enum
	program_state_t state;

	// TODO:
	// Initialize the state to LED blinker mode
	state = LED_BLINKER;

	// Infinite loop
	while (1) {
		// TODO:
		// Check the UART input buffer. If it's not empty process the string in it,
		// maybe it is a command!
		if (!UART_is_buffer_empty()) {
			char command[64];
			gets(command);
			if (!strcmp(command, "LED_BLINKER\r"))
				state = LED_BLINKER;
			else if (!strcmp(command, "TURN_OFF_LED\r"))
				state = TURN_OFF_LED;
			else if (!strcmp(command, "TURN_ON_LED\r"))
				state = TURN_ON_LED;
			else if (!strcmp(command, "LED_PUSHBUTTON\r"))
				state = LED_PUSHBUTTON;
		}

		// TODO:
		// Do the tasks based on the state, hint: use switch-case
		switch (state) {
		case LED_BLINKER:
			PINB |= 1 << PINB5;
			_delay_ms(500);
			break;
		case LED_PUSHBUTTON:
			if (PINB & (1 << PINB))
				PORTB |= 1 << PORTB5;
			else
				PORTB &= ~(1 << PORTB5);
			break;
		case TURN_ON_LED:
			PORTB |= 1 << PORTB5;
			break;
		case TURN_OFF_LED:
			PORTB &= ~(1 << PORTB5);
			break;
		}
	}
}
