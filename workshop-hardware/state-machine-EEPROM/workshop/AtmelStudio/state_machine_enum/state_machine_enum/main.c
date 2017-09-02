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

void Init() {
    // Initialize the UART interface with 115200 baud/sec
    UART_Init();

    // Initialize the LED pin
    DDRB |= 1 << DDRB5;

    // Enable interrupts globally
    sei();
}

int main(void) {
    // Don't forget to call the Init() function :)
    Init();

    // Setting up STDIO input and output buffer
    // You don't have to understand this!
    //----- START OF STDIO IO BUFFER SETUP
    FILE UART_output = FDEV_SETUP_STREAM(UART_SendCharacter, NULL, _FDEV_SETUP_WRITE);
    stdout = &UART_output;
    FILE UART_input = FDEV_SETUP_STREAM(NULL, UART_GetCharacter, _FDEV_SETUP_READ);
    stdin = &UART_input;
    //----- END OF STDIO IO BUFFER SETUP

    // TODO:
    // Create a variable with your custom program state type enum

    // TODO:
    // Initialize the state to LED blinker mode

    // Infinite loop
    while (1) {
        // TODO:
        // Check the UART input buffer. If it's not empty process the string in it,
        // maybe it is a command!

        // TODO:
        // Do the tasks based on the state, hint: use switch-case

    }
}
