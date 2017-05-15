#include "ADC_driver.h"
#include <avr/io.h>
#include <stdint.h>

void ADC_Init() {
    // TODO:
    // Set the reference voltage to AVcc.

    // TODO:
    // Set the data format to right adjusted, so the bottom 8bits will be in ADCL register

    // TODO:
    // Set the used channel. Use the definitions from ADC_driver.h!

    // TODO:
    // Set the prescaler. Use the definitions from ADC_driver.h!

    // TODO:
    // Enable the ADC peripheral
}

uint16_t ADC_Read() {
    // TODO:
    // Start a conversion with ADSC bit setup

    // TODO:
    // Wait for the conversion to finish by checking ADSC bit

    // TODO:
    // return with the read data, use the "ADC" register!
}
