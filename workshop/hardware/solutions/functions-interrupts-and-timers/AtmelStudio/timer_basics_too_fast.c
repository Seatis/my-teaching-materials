#include <avr/io.h>

void init()
{
    // Set the prescaler to 1024 division. See at the TC0 control register in the datasheet!
    // With this you also set the clock source to CLK_io and you will also turn on the timer!
    TCCR0B |= 1 << CS02;
    TCCR0B |= 1 << CS00;

    // Set the PB5 LED pin to output
    DDRB = 1 << DDB5;
}

int main(void)
{
    // Don't forget to call the init function!
    init();

    while (1)
    {
        // If TC0 counter overflow occurred (TOV0 flag is set) toggle the LED and write "1" to that flag (this will clear it, i know, it's confusing, but this is how does it work)
        if (TIFR0 & (1<<TOV0))
        {
            PORTB ^= 1<<PB5;
            TIFR0 |= 1<<TOV0;
        }
    }
}