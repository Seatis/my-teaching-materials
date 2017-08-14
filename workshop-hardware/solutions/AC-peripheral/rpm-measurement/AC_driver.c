#include <avr/io.h>
#include <float.h>
#include "AC_driver.h"
#include "freq_meas.h"

float prev_valid_rpm = 0;

void AC_driver_init()
{
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
}

float get_rpm()
{
	float freq = get_freq();
	float rpm = freq * FREQ_TO_RPM_CONST;

	// Check if freq is invalid
	if (freq < 0) {
		return prev_valid_rpm;
	} else {
		prev_valid_rpm = rpm;
		return rpm;
	}
}