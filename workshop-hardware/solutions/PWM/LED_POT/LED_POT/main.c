#include <avr/io.h>
#include "TC0_PWM_driver.h"
#include "ADC_driver.h"

#define F_CPU	16000000
#include <avr/delay.h>

void system_init()
{
	// This will initialize the LED pin also!
	TCO_fast_pwm_init();

	ADC_init();
}

int main(void)
{
	system_init();
	while (1) {
		float adc_data = ADC_read();
		TC0_set_duty(adc_data / ADC_DATA_MAX * 100);
	}
}
