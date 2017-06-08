#include "control.h"
#include "TC2_PWM_driver.h"
#include <stdio.h>

float integ = 0;
float p_const = 0.01;
float i_const = 0.01;

void pi_control(float ref_rpm, float rpm)
{
	float err = ref_rpm - rpm;
	integ += err;
	float duty = err * p_const + integ * i_const;

	if (duty < 0) {
		integ -= err;
		duty = 0;
	}

	if (duty > 100) {
		integ -= err;
		duty = 100;
	}

	TC2_set_duty(duty);

	printf("%.0f RPM \t", ref_rpm);
	printf("%.0f %% \t", duty);
	printf("%.0f RPM\r\n", rpm);
}