#include <avr/io.h>
#include <stdint.h>
#include <avr/interrupt.h>
#include "RPM_cntr_driver.h"

volatile uint16_t last_reg_value;
volatile uint16_t prev_reg_value;
volatile uint16_t ovf_value;
volatile uint16_t ovf_cntr;

ISR(TIMER1_CAPT_vect)
{
	ovf_value = ovf_cntr;
	ovf_cntr = 0;
	prev_reg_value = last_reg_value;
	last_reg_value = ICR1;
}

ISR(TIMER1_OVF_vect)
{
	ovf_cntr++;
}

void RPM_cntr_init()
{
	prev_reg_value = last_reg_value = ovf_cntr = 0;
	/*************
	 * AC CONFIG *
	 *************/
	// TODO:
	// Disable the digital input buffers on AN0 and AN1 to reduce power consumption.
	// See the DIDR1 register description for more info.
	DIDR1 = (1 << AIN1D) | (1 << AIN0D);

	// TODO:
	// Connect the AC output to the AC0 pin.
	// The datasheet if screwed up. It says "Analog Comparator Control and Status Register C", meanwhile the name of this register is "ACSR0",
	// but in the avr/io.g header this register can be reached with the "ACSRB" macro.
	ACSRB |= 1 << ACOE;

	// TODO:
	// Configure the rest settings properly :)

	// AC output connected to TC1 input capture
	ACSR = 0;
	ACSR |= 1 << ACIC;

	/**************
	 * TC1 CONFIG *
	 **************/
	// TODO:
	// Configure the rest settings properly :)

	// TC1 Input capture interrupt enable
	TIMSK1 |= 1 << ICIE1;
	// TC1 overflow interrupt enable
	TIMSK1 |= 1 << TOIE1;
	// TC1 clock select, this will also start the timer!
	TCCR1B &= ~(1 << CS12);
	TCCR1B |= 1 << CS11;
	TCCR1B |= 1 << CS10;
}

float get_rpm()
{
	// The interrupts must be disabled while accessing variables which are used in interrupt handlers
	cli();
	// Copy the used variables as fast as possible.
	uint16_t last = last_reg_value;
	uint16_t prev = prev_reg_value;
	uint16_t ovf = ovf_value;
	sei();

	// This difference can be negative, that is why int32_t is used!
	int32_t diff = last - prev;

	// Steps will be always positive, so uint32_t can be used.
	uint32_t steps = ovf * TC1_MAX + diff;

	float period = TC1_STEP_TIME_S * (float)steps;
	float rpm = 1 / period * FREQ_TO_RPM_CONST;
	return rpm;
}