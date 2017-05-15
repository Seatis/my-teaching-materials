/*
 * TC0_CTC_test.c
 *
 * Created: 2017. 05. 11. 14:23:35
 * Author : kazy
 */

#include <avr/io.h>
#define F_CPU	16000000
#include <avr/delay.h>
#include <avr/interrupt.h>

volatile uint8_t cntr;
const uint8_t cntr_max = 32;

ISR(TIMER0_COMPA_vect) {
    if(cntr < cntr_max) {
        cntr++;
    } else {
        cntr = 0;
        PINB |= 1 << PINB5;
    }
}

void Init() {
    // Sat LED pin as output
    DDRB |= 1 << DDRB5;
    PORTB = 0;

    // TC0 INIT

    // Clock init
    // TCCR0B |= 0b00000101;
    // TCCR0B |= 0x05;
    TCCR0B |= 1 << CS02;
    TCCR0B &= ~(1 << CS01);
    TCCR0B |= 1 << CS00;

    // Set OC register to a default value
    TCCR0A |= 1 << WGM01;
    OCR0A = 255;

    // Enable OCR0A interrupt
    TIMSK0 |= 1 << OCIE0A;

    // Enable interrupts globally
    sei();
}

int main(void) {
    /* Replace with your application code */

    // Never forget to call Init function
    Init();

    while (1) {
        // Toggle LED
        _delay_ms(500);
    }
}

