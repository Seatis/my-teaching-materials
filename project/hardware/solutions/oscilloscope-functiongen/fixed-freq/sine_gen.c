#include "sine_gen.h"
#include "MCP4821_driver.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <math.h>

uint8_t cntr;

ISR(TIMER0_COMPA_vect) {
    float angle = (float)cntr * PI / SAMPLES * 2;
    if(cntr < (SAMPLES-1)) {
        cntr ++;
    } else {
        cntr = 0;
    }
    float data_in_volts = sin(angle) * vpp / 2 + OFFSET;
    dac_data.data = MCP4821_DATA_MAX * data_in_volts / 4.096;
    MCP4821_SendData(&dac_data);
}

void SineGenInit() {
    // Initialize variables
    cntr = 0;
    vpp = 1.0;
    // Initialize dac_data
    dac_data.start_zero = 0;
    dac_data.dont_care = 0;
    dac_data.gain = 0;		//2x
    dac_data.shutdown = 1;	// not shutdown
    dac_data.data = 0x000;

    // Clock init
    // TCCR0B |= 0b00000101;
    // TCCR0B |= 0x05;
    TCCR0B |= 1 << CS02;
    TCCR0B &= ~(1 << CS01);
    TCCR0B |= 1 << CS00;

    // Set OC register to a default value
    TCCR0A |= 1 << WGM01;
    OCR0A = 255;

    // Enable OCR0A interrupt
    TIMSK0 |= 1 << OCIE0A;
}

