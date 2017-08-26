#ifndef _AC_DRIVER_H
#define _AC_DRIVER_H

#define IMPULSE_PER_ROTATION	7
#define FREQ_TO_RPM_CONST		(60 / IMPULSE_PER_ROTATION)

void AC_driver_init();
float get_rpm();

#endif // _AC_DRIVER_H