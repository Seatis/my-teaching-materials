#include "TC2_PWM_driver.h"
#include <avr/io.h>
#include <stdint.h>

void TC2_fast_pwm_init()
{
	// Set FAST PWM mode, with comparison of OCRA
	TCCR2A |= 1 << WGM21;
	TCCR2A |= 1 << WGM20;

	// Set OC2A pin to high when compare match occures, clear OC0A when counter overflows
	TCCR2A |= 1 << COM2A1;

	// Enable OC2A pin as output
	DDRB |= 1 << DDRB3;

	// Set clock speed to minimum, Tcnt will be 16MHz/1024 / 255 ~ 61Hz (1024 prescaler)
	TCCR2B |= 1 << CS20;
	TCCR2B |= 1 << CS21;
	TCCR2B |= 1 << CS22;

	// Set OCR0A register to generate 50% duty cycle
	OCR2A = 127;	// 255 is max duty cycle
}

void TC2_set_duty(uint8_t duty)
{
	OCR2A = 255 * (float)(duty) / 100;
}
