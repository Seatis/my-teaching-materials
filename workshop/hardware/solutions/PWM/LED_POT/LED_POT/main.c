#include <avr/io.h>
#include "TC0_PWM_driver.h"
#include "ADC_driver.h"

#define F_CPU	16000000
#include <avr/delay.h>

void SystemInit() {
    // This will initialize the LED pin also!
    TCO_FastPwmInit();

    ADC_Init();
}

int main(void) {
    SystemInit();
    while (1) {
        float adc_data = ADC_Read();
        SetDuty(adc_data/ADC_DATA_MAX * 100);
    }
}

