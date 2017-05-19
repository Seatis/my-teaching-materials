#ifndef TC0_PWM_DRIVER_H_
#define TC0_PWM_DRIVER_H_

#include <stdint.h>

void TCO_FastPwmInit();
void SetDuty(uint8_t);

#endif /* TC0_PWM_DRIVER_H_ */