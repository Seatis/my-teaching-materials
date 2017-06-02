#ifndef _RPM_CNTR_DRIVER_H
#define _RPM_CNTR_DRIVER_H

#include <stdint.h>

#define TC1_MAX				(0xFFFF)
#define TC1_STEP_TIME_US	(4.0)
#define TC1_STEP_TIME_MS	(TC1_STEP_TIME_US / 1000.0)
#define TC1_STEP_TIME_S		(TC1_STEP_TIME_MS / 1000.0)
#define IMPULSES_PER_ROT	(7)
#define FREQ_TO_RPM_CONST	(60 / IMPULSES_PER_ROT)

void RPM_cntr_init();
float get_rpm();

#endif // _RPM_CNTR_DRIVER_H