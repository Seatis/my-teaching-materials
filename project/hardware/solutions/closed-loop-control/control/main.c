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

#define DEFAULT_DELAY		10
#define REF_MAX				4500	// 4500RPM if the potentiometer is at maximal voltage positition

enum {
	USE_PI = 0,
	USE_P = 1,
	USE_OPEN_LOOP = 2
} ctrler_state;

// Create controller variables
p_ctrler_t p_ctrler;
pi_ctrler_t pi_ctrler;

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

void handle_user_input()
{
	TC2_set_duty(0);	// Stop the fan before handling user input!
	uint8_t mode;
	float p;
	float i;
	float rpm;
	uint8_t valid_command = 0;
	char command = 0;
	command = getchar();
	if (command == 'r') {
		printf("Enter desired reference RPM value!\r\n");
		UART_clear_buffer();
		if (scanf("%f", &rpm) > 0) {
			printf("ref:%f RPM\r\n", rpm);
			switch (ctrler_state) {
			case USE_OPEN_LOOP:
				break;
			case USE_P:
				p_ctrler.ref = rpm;
				break;
			case USE_PI:
				pi_ctrler.ref = rpm;
				break;
			default:
				printf("Unknown control type, using open loop.\r\n");
				ctrler_state = USE_OPEN_LOOP;
				break;
			}
		}
	} else if (command == 's') {
		printf("Enter settings: mode p i\r\n");
		UART_clear_buffer();
		if (scanf("%u %f %f\r\n", &mode, &p, &i) > 0) {
			printf("mode:%u p:%f i:%f\r\n", mode, p, i);
			ctrler_state = mode;
			switch (ctrler_state) {
			case USE_OPEN_LOOP:
				break;
			case USE_P:
				p_ctrler.p = p;
				break;
			case USE_PI:
				pi_ctrler.p = p;
				pi_ctrler.i = i;
				break;
			default:
				printf("Unknown control type, using open loop.\r\n");
				ctrler_state = USE_OPEN_LOOP;
				break;
			}
		}
	}
	UART_clear_buffer();
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

	// Init variables
	p_init(&p_ctrler);
	pi_init(&pi_ctrler);
	p_ctrler->out_max = 100;	// Duty cycle max
	p_ctrler->out_min = 0;		// Duty cycle min
	pi_ctrler->out_max = 100;	// Duty cycle max
	pi_ctrler->out_min = 0;		// Duty cycle min
	ctrler_state = USE_OPEN_LOOP;

	// Infinite loop
	while (1) {
		// Get command from the user
		if (!UART_is_buffer_empty()) {
			handle_user_input();
		}

		uint8_t duty;
		switch (ctrler_state) {
		case USE_OPEN_LOOP:
			duty = (uint8_t)((float)ADC_read() / ADC_DATA_MAX * 100);	// Duty max is 100
			break;
		case USE_P:
			p_ctrler->ref = (float)ADC_read() / ADC_DATA_MAX * REF_MAX;
			p_ctrler->sense = get_rpm();
			duty = (uint8_t)(p_control(&p_ctrler));
			break;
		case USE_PI:
			p_ctrler->ref = (float)ADC_read() / ADC_DATA_MAX * REF_MAX;
			p_ctrler->sense = get_rpm();
			duty = (uint8_t)(pi_control(&pi_ctrler));
			break;
		default:
			printf("Unknown control type!\r\n");
			break;
		}

		TC2_set_duty(duty);

		_delay_ms(DEFAULT_DELAY);
	}
}
