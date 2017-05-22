#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdlib.h>
#include "TC0_PWM_driver.h"
#include "ADC_driver.h"
#include "UART_driver.h"

#define F_CPU	16000000
#include <avr/delay.h>

void SystemInit() {
    // This will initialize the LED pin also!
    TCO_FastPwmInit();

    UART_Init();

    ADC_Init();

    sei();
}

int main(void) {
    SystemInit();

    // Setting up STDIO input and output buffer
    // You don't have to understand this!
    //----- START OF STDIO IO BUFFER SETUP
    FILE UART_output = FDEV_SETUP_STREAM(UART_SendCharacter, NULL, _FDEV_SETUP_WRITE);
    stdout = &UART_output;
    FILE UART_input = FDEV_SETUP_STREAM(NULL, UART_GetCharacter, _FDEV_SETUP_READ);
    stdin = &UART_input;
    //----- END OF STDIO IO BUFFER SETUP

    while (1) {
        if(!UART_IsBufferEmpty()) {
            char command[64];
            gets(command);
            uint8_t duty = atoi(command);
            SetDuty(duty);
        }
    }
}

