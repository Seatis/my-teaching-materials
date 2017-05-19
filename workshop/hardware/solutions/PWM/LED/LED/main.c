#include <avr/io.h>
#include "TC0_PWM_driver.h"

#define F_CPU	16000000
#include <avr/delay.h>

void SystemInit() {
    // This will initialize the LED pin also!
    TCO_FastPwmInit();
}

int main(void) {
    SystemInit();
    uint8_t cntr = 0;
    while (1) {
        for(cntr = 0; cntr < 100; cntr++) {
            SetDuty(cntr);
            _delay_ms(5);
        }
        for(; cntr > 0; cntr--) {
            SetDuty(cntr);
            _delay_ms(5);
        }
    }
}

