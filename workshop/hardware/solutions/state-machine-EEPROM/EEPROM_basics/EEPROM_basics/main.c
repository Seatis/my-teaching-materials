#include <avr/io.h>
#include <avr/eeprom.h>
#include <stdint.h>
#include "UART_driver.h"

// TODO:
// Comment out the unnecessary functionality
#define READ_FROM_EEPROM
#define WRITE_DEFAULTS_TO_EEPROM

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
    // TODO: write the default values to the EEPROM
#endif

#ifdef READ_FROM_EEPROM
    // TODO: read the values from the EEPROM
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

