#ifndef TC0_PWM_DRIVER_H_
#define TC0_PWM_DRIVER_H_

#include <stdint.h>

void TC2_fast_pwm_init();
void TC2_set_duty(uint8_t);

#endif /* TC0_PWM_DRIVER_H_ */
