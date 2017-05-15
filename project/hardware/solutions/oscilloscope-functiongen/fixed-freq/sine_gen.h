#ifndef _SINE_GEN_H_
#define _SINE_GEN_H_

#include "MCP4821_driver.h"

#define PI	3.14159265
#define SAMPLES	20
#define OFFSET	2.0

volatile MCP4821_Data_t dac_data;	// DAC data
float vpp;							// peak-to-peak voltage

void SineGenInit();

#endif /* _SINE_GEN_H_ */