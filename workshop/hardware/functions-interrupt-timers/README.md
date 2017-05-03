# Functions, interrupts and timers

*Meet the base elements of the C language by implementing small programs*

## Objectives
 - Defining and calling functions
 - Using the interrupts with ATmega168PB
 - Using the timers with ATmega168PB

## Materials & Resources
### Environment
- Make sure that Code::Blocks is installed on your machine
- Make sure that Atmel Studio is installed on your machine

### Training
#### Functions in C
Watch and read the following materials on C functions:

| Material | Time |
|:---------|-----:|
| [Introduction to Functions](https://www.youtube.com/watch?v=lv5IDF7dmBk) | 8:22 |
| [Local, Global Variable Scopes](https://www.youtube.com/watch?v=sAj_Jrqrg5g) | 3:36 |
| [Local, Global Variable Scopes](http://www.w3schools.in/c-tutorial/variable-scope/) | - |
| [Function Parameters](https://www.youtube.com/watch?v=_oyuKw3vBf8) | 6:19 |
| [Return Values](https://www.youtube.com/watch?v=ye2tvFir65g) | 7:13 |
| [Summary of Functions](http://www.w3schools.in/c-tutorial/functions/) | - |

#### Interrupts
It's time to move forward with our microcontroller! During the previous workshop
we played with the GPIO peripheral, now let's talk about the interrupts.

| Material | Time |
|:---------|-----:|
| [Polling vs. Interrupts](http://www.electronics-base.com/useful-info/software-related/90-polling-vs-interrupt) | - |
| [Interrupts in real life](https://www.youtube.com/watch?v=M3nXI_86uLE) | 0:34 |

So basically interrupts are event triggered rapid program executions on a CPU.
On an AVR MCU there are lot's of logic gates which are responsible for event detection.
When an event is detected (for example the level of a pin changed state) instead of
the next instruction execution the program jumps to a specific program memory location
which is called the vector table.

We does not want to program the AVR in assembly language, the compiler will give us
a much more easier interrupt handling tool in our hands, but it is useful to understand
what is going on in the MCU.

The ATmega168PB's interrupt vector table can be found on the pages 87. and 88. in
the [datasheet](http://www.atmel.com/Images/Atmel-42176-ATmega48PB-88PB-168PB_Datasheet.pdf).

In this vector table you can see which program memory address corresponds to which
interrupt source. For example if the state changes on INT0 pin, than the program will
jump to the 0x0002 memory address. You can see that the different interrupt vector
entries are only 2 memory away from each other. This means that we have only 2
instructions to handle an interrupt request.

How does it possible? With JUMP instructions! So we can write a long program in
the other part of the program memory and in the interrupt vector table we can
only write a JUMP instruction to the program's first instruction's memory address.

The compiler will do these things for us, but how can we use them? Simply we write
a special function for each interrupt sources we want to handle. It's looks like:

```c_cpp
# include < avr / interrupt.h >    //This file contains the names of the Vector Source
ISR ({ Vector Source } _vect )
{
    // ISR code to execute here
}
```
If we would like to do something when INT0 changes state we would write:

```c_cpp
# include < avr / interrupt.h >    //This file contains the names of the Vector Source
ISR (INT0_vect)
{
    // ISR code to execute here
}
```

TODO: link to vector name list?! It's the same as in vector table@datasheet???

To use interrupts you also have to enable it. In most MCUs there is a global interrupt enable bit (somewhere in a register :)) which has to be set to "1" to enable the interrupts globally, then you have to enable the one you would like to use (somewhere in another register :)).

Please read more about this topic in the following document:

| Material | Time |
|:---------|-----:|
| [Interrupts in AVR](http://www.github.com/abcminiuser/avr-tutorials/blob/master/Interrupts/Output/Interrupts.pdf?raw=true) | - |

#### Timers
A timer is a peripheral which can be found in every MCU. It is basically a counter
which increments (or decrements) it's value by a clock signal.

They have two basic "modes" of operation.

In capture mode the clock comes from a pin. So it counts the rising or falling edges
of a signal on a pin. This can be useful if you want to measure the frequency or the period
of a signal.

In timer mode the clock comes from inside the MCU, typically from the CPU clock.
Typically there is so called "prescaler" module in every MCU, which can devide the CPU clock
by an adjustable value (for example it can provide 4MHz clock from a 16MHz CPU clock).
This prescaler can be used to provide different clock frequencies for the timer peripheral.

The timers can generate different kind of interrupts. For example if the counter overflows, or when
the counter reaches a predefined value.

The timers also can generate PWM signals, but we will talk about it later.

Typically more than one timer can be found in an MCU, the ATmega168PB has:
- two 8-bit timer
- one 16-bit timer

We will only use the TC0 8-bit timer during the workshop.

Please read the corresponding pages of the ATmega168PB datasheet.
The needed parts are:
- pages 139-163
- only the following modes of operations needed now
    - normal mode (20.7.1)
    - clear timer on compare match (CTC, 20.7.2)
- so PWM modes **NOT** needed!

In the register description section try to find out the answer for the following questions
(only read about the following registers):
- TCCR0A
    - What can we set with this register?
    - Do we need to modify the default value in normal operation?
- TCCR0B
    - What can we set with this register?
    - How can we select the clock source?
    - Do we need to modify the default value in normal operation?
- TIMSK0
    - What can we set with this register?
- TCNT0
    - What does this register do?
- OCR0A
    - What does this register do?
- OCR0B
    - What does this register do?
- TIFR0
    - What does this register do?

| Material | Time |
|:---------|-----:|
| [ATmega168PB Datasheet - TC0 timer](http://www.atmel.com/Images/Atmel-42176-ATmega48PB-88PB-168PB_Datasheet.pdf) | - |

#### Optional Material
This article talks about the timers and it's capabilities. It's a litle bit long,
so read it only if you have enough time :).

| Material | Time |
|:---------|-----:|
| [Timers in AVR](http://www.github.com/abcminiuser/avr-tutorials/blob/master/Timers/Output/Timers.pdf?raw=true) | - |

## Material Review
- Functions
    - syntax
    - what do we use it
    - why it is good
    - how does it look like
    - parameters
        - syntax
        - why it is good
    - return values
        - syntax
        - why it is good
        - multiple return statements in functions
    - variable scopes
        - global
            - it can be evil
        - local
    - standard library functions
        - printf
        - sizeof
            - play with it with different types
            - char, short, int, long, longlong
            - uint8_t, int8_t, float, double
        - TODO input functions which are useful during UART project in the UART ws!
- Interrupts
    - what is it
    - why do we use it (vs. polling)
    - interrupt vectors (generally speaking)
    - ATmega168PB specific things
        - ATmega168PB interrupt vector
        - how can we use it in C with our compiler
            - interrupt.h
            - ISR(...) functions
            - list of vector names
        - interrupt enable bits
            - global interrupt enable/disable
            - peripheral interrupt enable bits
                - where can we find them
                - datasheet!4444!!!!!!4444!
    - Live coding
        - button interrupt turns on the LED

- Timers
    - what is it
    - why do we use it
    - for what do we use it
        - frequency and period measurement
        - timing applications
        - time measurement
        - PWM (we will talk about it later)
    - general block diagram
        - counter
        - clock source
            - prescaler
            - how to calculate timer overflow period
                - with prescaler
                - bit count dependent
                - TODO: put this method in material
        - compare registers
        - config registers
        - interrupt generation
    - block diagram of ATmega168PB TC0
    - TC0 related registers
        - what do they responsible for
        - TCCR0A
        - TCCR0B
        - TIMSK0
        - TCNT0
        - OCR0A
        - OCR0B
        - TIFR0
- take one deep breath
- take another deep breath, but this time much more deeper
- go on

## Workshop
Today we are going to learn how to use functions in C language.
After we mastered this new "thing", we are moving forward by using the external
interrupts and timers of the ATmega168PB devboard.

### Functions
- example
    - int fruitManipulator(int oranges, int apples, unsigned int what2do)
    - 0 means add
    - 1 means subtract
    - elso returns
- Practice
    - void function no params
        - something that is good because reusable
    - void function with params
    - non void function no params
        - ??
    - non void function with params
        - ??
        - error code return
### Interrupt
- preactice (with code template)
    - reproduce button turns on LED project

### Timer
- Practice
    - A
        - config timer as normal operation
            - human compatible freqency
            - the min tmr period is 60Hz so fucked up :(
        - in main poll the timer register value
        - if matches toggle the LED
            - effective freq is about 30Hz
    - B

TODO: DEBUGGER!!!!!!!! Start this whole shit with the debugger
TODO: clocks of this shitty mcu!


## Individual Workshop Review
Please follow the styleguide: [Our C styleguide](../../styleguide/c.md)

- Is the directory structure and the name of the files correct?
- Are the includes placed on the top of the files?
- Is the indentation good in each file?
- Is there unnecessary code?
- Can you find unnecessary code in comments?
- Is there unnecessary code duplication?
- Are there unnecessary empty blocks?
- Can you spot unused variables?
- Is the commit message meaningful?
