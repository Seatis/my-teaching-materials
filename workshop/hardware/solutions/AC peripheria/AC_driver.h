// Multiple inclusion guard
#ifndef _TC74_DRIVER_H
#define _TC74_DRIVER_H

#include <stdint.h>

#define TC_WRITE	0
#define TC_READ		1
#define TC_ADDRESS	0b1001000	//TC74A0 address


uint16_t timer1_Read16( void );
uint8_t read_temp (uint8_t address);
void TWIInit(void);
void TWIStart(void);
void TWIWrite(uint8_t u8data);
void TWIStop(void);
uint8_t TWIReadNACK(void);
uint8_t TWIReadACK(void);

#endif // _TC74_DRIVER_H