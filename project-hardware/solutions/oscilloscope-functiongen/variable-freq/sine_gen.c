#include "sine_gen.h"
#include "MCP4821_driver.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <math.h>

volatile uint8_t cntr;
volatile float vpp;				// peak-to-peak voltage in V

ISR(TIMER1_COMPA_vect)
{
	float angle = (float)cntr * PI / SAMPLES * 2;
	if (cntr < (SAMPLES - 1))
		cntr ++;
	else
		cntr = 0;
	float data_in_volts = sin(angle) * vpp / 2 + OFFSET;
	dac_data.data = MCP4821_DATA_MAX * data_in_volts / 4.096;
	MCP4821_send_data(&dac_data);
}

void set_freq(uint16_t freq_to_set)
{
	uint16_t compare_to = 1 / ((float)freq_to_set * SAMPLES * PRESCALER) * F_CPU;
	OCR1A = compare_to;
}

void set_vpp(float voltage)
{
	vpp = voltage;
}

void sine_gen_init()
{
	// Initialize variables
	cntr = 0;
	vpp = 1.0;
	set_freq(1);

	// Initialize dac_data
	dac_data.start_zero = 0;
	dac_data.dont_care = 0;
	dac_data.gain = 0;		//2x
	dac_data.shutdown = 1;	// not shutdown
	dac_data.data = 0x000;

	// With the TC0 timer we can not generate too slow sine waves
	// Hence we will use the TC1 timer, which is a 16-bit wide timer
	// It can count between 0-65535 (2^16 - 1), and it's prescaler can be set to 1,8,64,256,1024
	// The minimum overflow interval can be calculated by:
	// interval = time_of_one_count * 65536
	// time_of_one_count = CPU_clock_period * prescaler
	// time_of_one_count = (1/CPU_clock_frequency) * prescaler = 1/16e6 * 1024 = 64us
	// interval = 64us * 65536 = 4194304us = 4.194304 sec
	// So we can easily make 1Hz sine waves :)

	// Set CTC mode
	TCCR1B |= 1 << WGM12;	// WGM13=WGM11=WGM10=0 by deafult

	// Prescaler setup	to 256
	TCCR1B |= 1 << CS12;	//CS11 and CS10 is 0 by default

	// Enable OCR1A interrupt
	TIMSK1 |= 1 << OCIE1A;
}

