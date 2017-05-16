#ifndef _SINE_GEN_H_
#define _SINE_GEN_H_

#include "MCP4821_driver.h"

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#define PI	3.14159265
#define OFFSET		2.0
#define SAMPLES		20
#define PRESCALER	256.0

#define FREQ_MAX 100
#define FREQ_MIN 1

volatile MCP4821_Data_t dac_data;	// DAC data

void SineGenInit();
void SetVpp(float);
void SetFreq(uint16_t);

#endif /* _SINE_GEN_H_ */