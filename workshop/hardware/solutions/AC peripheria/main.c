#include "AC_driver.h"
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

/*ISR(ANALOG_COMP_vect)
{
	printf("AC interrupt\r\n");
}*/
ISR(TIMER1_CAPT_vect)
{
	PINB |= 1 <<LED_PORT_POS;	//printf("T:%d\r\n",TIFR1);	printf("T:%u\r\n",timer1_Read16());	//TCNT1 =0;	//TCNT1L =0;

}

void SystemInit() {
	//TODO
	// Call the TWI driver init function
	TWIInit();
	//TODO
	//Init the uart
	UART_Init();
}

int main(void) {

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

	sei();

	// Infinite loop
	while (1) {
		//TODO
		//Write the temperature frequently.
		//TODO
		//Advanced: Don't use delay, use timer.
		_delay_ms(1000);
		//printf("temp: %d [�C]\r\n",55);
		//TODO
		//Blink the led to make sure the code is running
		PINB |= 1 <<LED_PORT_POS;
	}
}
