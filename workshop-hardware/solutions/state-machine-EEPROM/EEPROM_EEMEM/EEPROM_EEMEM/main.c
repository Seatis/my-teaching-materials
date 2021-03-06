#include <avr/io.h>
#include <avr/eeprom.h>
#include <stdint.h>
#include <stdio.h>
#include "UART_driver.h"

// TODO:
/*
	1) Do the other TODOs first!
	2) Run the code
		You will notice that memory garbage is shown on the serial port
	3) Try to give default values to the variables (in global scope)
		You will notie that this did not help
	4) The compiler makes a special file that contains the default values of the EEPROM variable's,
		you have to load it to the MCU manually

		At first you have to switch the programmer back to ISP mode from debugWIRE.
		To do this you have to enter debugging mode, so hit the "F5" button on your keyboard,
		this will start a debugging process.
		While in debugging mode pause the program (by pressing "Ctrl+F5", or by Debug->Break all)

		If the program is paused click on Debug->Disable debugWIRE and close. This will stop debugging
		and reverts the programmer back to ISP mode.

		Now follow the following steps:
		- Tools->Device programming
		- Click on "Apply"
		- Click on "Memories" on the right
		- In the EEPROM field you should give the location of the .eep file
			- Click on the "Browse" button to open a file picker window
			- Search for a file in your project folder with the extension of .eep
		- After you found this file and browsed it click on the "Program" button
		- After the programming finished you can close the Device programming windows and
		rerun the program.
		- Now if you run your program the correct values will be shown
*/

// TODO:
// Create a 8bit, 16bit, 32bit wide insigned interger variable in the EEPROM (using "EEMEM")
// Also create a float variable and also create an array which holds 6 8bit wide unsigned integers in the EEPROM
// Note that these can't be used as regular variables, but we can use them to get a pointer to them, which will point
// somewhere to a the EEPROM.
uint8_t EEMEM EEPROM_var_8bit = 128;
uint16_t EEMEM EEPROM_var_16bit = 123;
uint32_t EEMEM EEPROM_var_32bit = 321;
float EEMEM EEPROM_var_float = 3.14;
uint8_t EEMEM EEPROM_array[] = {1, 2, 3, 4, 5, 6};

void init()
{
	// Initialize the UART interface with 115200 baud/sec
	UART_init();
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

	// Create variables in the SRAM
	uint8_t var_8bit;
	uint16_t var_16bit;
	uint32_t var_32bit;
	float var_float;
	uint8_t array[6];

	// TODO:
	// Load the values from the EEPROM to the SRAM variables!
	// Use the eeprom_read_xxxxx functions with th EEMEM variables as pointers.
	var_8bit = eeprom_read_byte(&EEPROM_var_8bit);
	var_16bit = eeprom_read_word(&EEPROM_var_16bit);
	var_32bit = eeprom_read_dword(&EEPROM_var_32bit);
	var_float = eeprom_read_float(&EEPROM_var_float);
	eeprom_read_block(array, EEPROM_array, sizeof(array));

	// Print out the variables
	// printf can't print out floating point numbers (float) by deafault :(
	// Just don't care, it's okay
	printf("var_8bit\t%d\r\n", var_8bit);
	printf("var_16bit\t%d\r\n", var_16bit);
	printf("var_32bit\t%ld\r\n", var_32bit);
	printf("var_float\t%f\r\n", var_float);
	printf("array\t");
	for (uint8_t i = 0; i < sizeof(array); i++)
		printf("%d ", array[i]);

	printf("\r\n");

	// Infinite loop
	while (1) {

	}
}
