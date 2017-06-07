#include "freq_meas.h"
#include "UART_driver.h"
#include "AC_driver.h"
#include "TC2_PWM_driver.h"
#include "ADC_driver.h"
#include "control.h"
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

void system_init()
{
	LED_DDR |= 1 << LED_DDR_POS;
	AC_driver_init();
	freq_meas_init();
	TC2_fast_pwm_init();
	ADC_init();
	UART_init();
	sei();
	_delay_ms(1000);
}

int main(void)
{

	// Don't forget to call the init function :)
	system_init();

	// Setting up STDIO input and output buffer
	// You don't have to understand this!
	//----- START OF STDIO IO BUFFER SETUP
	FILE UART_output = FDEV_SETUP_STREAM((void *)UART_send_character, NULL, _FDEV_SETUP_WRITE);
	stdout = &UART_output;
	FILE UART_input = FDEV_SETUP_STREAM(NULL, (void *)UART_get_character, _FDEV_SETUP_READ);
	stdin = &UART_input;
	//----- END OF STDIO IO BUFFER SETUP

	// Try printf
	printf("Startup...\r\n");

	volatile float rpm = 0;
	volatile uint16_t averages = 0;
	volatile const uint16_t averages_max = 20;

	// Infinite loop
	while (1) {
		if (averages < averages_max) {
			rpm = rpm + get_rpm();
			averages++;
		} else {
			LED_PIN |= 1 << LED_PIN_POS;
			rpm = rpm / averages;
			float ref_rpm = (float)ADC_read() / ADC_DATA_MAX * 4500;
			pi_control(ref_rpm, rpm);
			averages = 0;
			rpm = 0;
		}
		_delay_ms(1);
	}
}
