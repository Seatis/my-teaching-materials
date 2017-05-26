// Multiple inclusion guard
#ifndef _TC74_DRIVER_H
#define _TC74_DRIVER_H

#include <stdint.h>

#define TC_WRITE	0
#define TC_READ		1
//TODO
//Define the TC74A0 address

void TWIInit(void);
void TWIStart(void);
void TWIWrite(uint8_t u8data);
void TWIStop(void);
uint8_t TWIReadNACK(void);
uint8_t TWIReadACK(void);

#endif // _TC74_DRIVER_H