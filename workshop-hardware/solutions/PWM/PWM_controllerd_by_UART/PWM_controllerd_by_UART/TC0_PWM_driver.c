#include "TC0_PWM_driver.h"
#include <avr/io.h>
#include <stdint.h>

void TCO_fast_pwm_init()
{
	// Set FAST PWM mode, with comparison of OCRA
	TCCR0A |= 1 << WGM01;
	TCCR0A |= 1 << WGM00;

	// Set OC0A pin to high when compare match occures, clear OC0A when counter overflows
	TCCR0A |= 1 << COM0A1;

	// Enable OC0A pin as output
	DDRD |= 1 << DDRD6;

	// Set clock speed to minimum, Tcnt will be 16MHz/1024 / 255 ~ 61Hz (1024 prescaler)
	TCCR0B |= 1 << CS00;
	TCCR0B |= 1 << CS02;

	// Set OCR0A register to generate 50% duty cycle
	OCR0A = 10;	// 255 is max duty cycle
}

void TC0_set_duty(uint8_t duty)
{
	OCR0A = 255 * (float)(duty) / 100;
}
