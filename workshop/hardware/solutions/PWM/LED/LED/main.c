#include <avr/io.h>
#include "TC0_PWM_driver.h"

#define F_CPU	16000000
#include <avr/delay.h>

void system_init()
{
	// This will initialize the LED pin also!
	TCO_fast_pwm_init();
}

int main(void)
{
	system_init();
	uint8_t cntr = 0;
	while (1) {
		for (cntr = 0; cntr < 100; cntr++) {
			TC0_set_duty(cntr);
			_delay_ms(5);
		}
		for (; cntr > 0; cntr--) {
			TC0_set_duty(cntr);
			_delay_ms(5);
		}
	}
}
