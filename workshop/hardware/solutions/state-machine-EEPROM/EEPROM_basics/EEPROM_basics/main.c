#include <avr/io.h>
#include <avr/eeprom.h>
#include <stdint.h>
#include <stdio.h>
#include "UART_driver.h"

// TODO:
/*
	1) leave everything uncommented! Write the other TODOs first, then run the program.
		On the serial port you can see the default values of the variables
	2) now uncomment the "READ_FROM_EEPROM" definition. This will enable EEPROM read at startup.
		you will see random numbers on UART, because you just read uninitialized data from the EEPROM
	3) now comment out the READ_FROM_EEPROM definition, and uncomment the other one
		On the serial port you can see the default values of the variables
	4) now uncomment the "READ_FROM_EEPROM" definition, and comment out the other one
		you will see the defaults numbers, which were loaded from the EEPROM
*/
//#define READ_FROM_EEPROM
//#define WRITE_DEFAULTS_TO_EEPROM

uint8_t var_8bit = 8;
uint16_t var_16bit = 16;
uint32_t var_32bit = 32;
float var_float = 3.14;
uint8_t array[] = {1,2,3,4,5,6};

// TODO:
// Define the EEPROM memory addresses for the variables
#define VAR_8BIT_ADDR	0	// start address
#define VAR_16BIT_ADDR	1	// previous+1B
#define VAR_32BIT_ADDR	3	// previous+2B
#define VAR_FLOAT_ADDR	7	// previous+4B
#define ARRAY_ADDR		11	// previous+4B

void Init() {
    // Initialize the UART interface with 115200 baud/sec
    UART_Init();

#ifdef WRITE_DEFAULTS_TO_EEPROM
    // TODO: write the default values of the variables to the EEPROM
    eeprom_update_byte(VAR_8BIT_ADDR, var_8bit);
    eeprom_update_word(VAR_16BIT_ADDR, var_16bit);
    eeprom_update_dword(VAR_32BIT_ADDR, var_32bit);
    eeprom_update_float(VAR_FLOAT_ADDR, var_float);
    eeprom_update_block(array, ARRAY_ADDR, 6);
#endif

#ifdef READ_FROM_EEPROM
    // TODO: read the values from the EEPROM to the variables
    var_8bit = eeprom_read_byte(VAR_8BIT_ADDR);
    var_16bit = eeprom_read_word(VAR_16BIT_ADDR);
    var_32bit = eeprom_read_dword(VAR_32BIT_ADDR);
    var_float = eeprom_read_float(VAR_FLOAT_ADDR);
    eeprom_read_block(array, ARRAY_ADDR, 6);
#endif
}

int main(void) {
    // TODO:
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

    // Print out the variables
    // printf can't print out floating point numbers (float) by deafault :(
    // Just don't care, it's okay
    printf("var_8bit\t%d\r\n", var_8bit);
    printf("var_16bit\t%d\r\n", var_16bit);
    printf("var_32bit\t%d\r\n", var_32bit);
    printf("var_float\t%f\r\n", var_float);
    printf("array\t");
    for(uint8_t i = 0; i < sizeof(array); i++) {
        printf("%d ", array[i]);
    }
    printf("\r\n");

    // Infinite loop
    while (1) {

    }
}

