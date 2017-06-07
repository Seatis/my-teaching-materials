#include "freq_meas.h"
#include "UART_driver.h"
#include "AC_driver.h"
#include "TC2_PWM_driver.h"
#include "ADC_driver.h"
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

	float ref = 2500;
	float P = 0.05;
	float I = 0.02;
	float integ = 0;

	// Infinite loop
	while (1) {
		// Generating an about 1Hz signal on the LED pin.
		// The printf call will also take some time, so this won't be exactly 1Hz.
		LED_PORT |= 1 << LED_PORT_POS;
		_delay_ms(50);
		LED_PORT &= ~(1 << LED_PORT_POS);
		_delay_ms(50);

		float rpm = get_rpm();
		float err = ref - rpm;
		integ += err;
		float duty = err * P + integ * I;

		if (duty < 0) {
			integ -= err;
			duty = 0;
		}
		if (duty > 100) {
			integ -= err;
			duty = 100;
		}


		TC2_set_duty(duty);
		printf("%f \%\r\n", duty);
		printf("%f RPM\r\n", rpm);
	}
}
