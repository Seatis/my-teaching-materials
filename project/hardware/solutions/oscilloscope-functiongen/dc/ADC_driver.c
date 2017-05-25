#include "ADC_driver.h"
#include <avr/io.h>
#include <stdint.h>

void ADC_init()
{
	// Set the reference voltage to AVcc.
	ADMUX = (0x3F & ADMUX) | (0b01 << REFS0);

	// Set the data format to right adjusted, so the bottom 8bits will be in ADCL register

	// Set the used channel. Use the definitions from ADC_driver.h!
	ADMUX = (0xF0 & ADMUX) | ADC_CH;

	// Set the prescaler. Use the definitions from ADC_driver.h!
	ADCSRA = (0xF8 & ADMUX) | ADC_ADPS;

	// Enable the ADC peripheral
	ADCSRA |= 1 << ADEN;
}

uint16_t ADC_read()
{
	// Start a conversion with ADSC bit setup
	ADCSRA |= 1 << ADSC;

	// Wait for the conversion to finish by checking ADSC bit
	while (ADCSRA & (1 << ADSC));

	// return with the read data, use the "ADC" register!
	return (ADC);
}
