#include <avr/io.h>
#include "AC_driver.h"
#include "freq_meas.h"

void AC_driver_init()
{
	/*************
	 * AC CONFIG *
	 *************/
	// TODO:
	// Disable the digital input buffers on AN0 and AN1 to reduce power consumption.
	// See the DIDR1 register description for more info.

	// TODO:
	// Connect the AC output to the AC0 pin.
	// The datasheet if screwed up. It says "Analog Comparator Control and Status Register C", meanwhile the name of this register is "ACSR0",
	// but in the avr/io.g header this register can be reached with the "ACSRB" macro.

	// TODO:
	// Configure the rest settings properly :)
	// AC output connected to TC1 input capture
}

// TODO:
// Write this function. It returns the measured rotation speed in RPM
float get_rpm()
{

}
