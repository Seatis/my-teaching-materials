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
simply write a JUMP instruction to the program's first instruction's memory address.

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

The vector name is usually the same as in the datasheet vector table "Source"
column (just replace the spaces with the \_ underscore character ).

To use interrupts you also have to enable it. In most MCUs there is a global interrupt enable bit (somewhere in a register :)) which has to be set to "1" to enable the interrupts globally, then you have to enable the one you would like to use (somewhere in another register :)).

In AVR MCUs the global interrupt can be enabled or disabled with specific
assembly instructions. Fortunately there are two functions in the interrupt.h header
which will do this job for us. The `sei()` function (SetEnableInterrupt) will enable the interrupts globally. The `cli()` function (CLearInterrupt) will disable the interrupts globally.
They are useful because you can disable/enable all of the interrupts with only one  
function call!

The individual interrupts can be enabled by writing to specific registers. Usually each
peripheral has specific registers for this purpose. In the datasheet you can always find them,
just search for the peripheral that you want to use and read through the register description of the peripheral.

In summary, to enable an interrupt source you have to:
- find the interrupt enable bit for the specific interrupt source you would like to use
- enable this interrupt
- if you have to enable other interrupt sources do the previous steps again
- enable the interrupts globally (`sei()`)

Please read more about AVR specific interrupt handling in the following document:

| Material | Time |
|:---------|-----:|
| [Interrupts in AVR](http://www.github.com/abcminiuser/avr-tutorials/blob/master/Interrupts/Output/Interrupts.pdf?raw=true) | - |

Another important thing about interrupts is volatile variables. They look like this:
```c_cpp
volatile uint8_t variable;
// generally:
// volatile TYPE VARIABLE_NAME
```
This volatile qualifier prevents the compiler from optimizing out this variable.

When do we need to use volatile variables? The thumb rule is that every variable
which is used in an interrupt handler have to be volatile.

Why? The interrupt handler is seen as a simple function for the compiler, but this
function is never called implicitly from the other parts of the code. So the compiler thinks, that the variables which are only used in interrupt handlers are never used, hence
the compiler wants to delete them. The volatile qualifier prevents this.

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

You can calculate how frequently a timer counter overflow occurs with the following formula:
overflow_frequency = CPU_freq / prescaler_value / maximum_value_of_timer_counter

For example if the CPU frequency is 16MHz, the prescaler is set to 256 and the timer
has 16bits, than:
overflow_frequency = 16000000 / 256 / 65536 = 0.95Hz

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
            - global interrupt enable/disable (sei/cli)
            - peripheral interrupt enable bits
                - where can we find them
                - datasheet!4444!!!!!!4444!
    - volatile qualifier
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
- start the workshop

## Workshop
Today we are going to learn how to use functions in C language.
After we mastered this new "thing", we are moving forward by using the external
interrupts and timers of the ATmega168PB devboard.

### Functions
#### Example
Here is a function as an example.

```c_cpp
int FruitManipulator(int oranges, int apples, unsigned int what_to_do){
    int to_return = 0;

    if(what_to_do == 0){
        to_return = oranges + apples;
    } else {
        to_return = oranges - apples;
    }

    retunr to_return;
}
```
What does this function do? Find out by calling it from the main function!
Try it out with different numbers and print out the returned value in the main function!

#### Tasks
- void function with no parameters
    - [1.c](workshop/CodeBlocks/1.c)
- void function with params
    - [2.c](workshop/CodeBlocks/2.c)
- non void function no params
    - [3.c](workshop/CodeBlocks/3.c)
- non void function with params
    - [4.c](workshop/CodeBlocks/4.c)

### Interrupt
Let's use the interrupt-on-change functionality of the ATmega168PB!

There is a button on the devboard, which is connected to PB7. This pin is also called
PCINT7 (PinChangeINTerrupt7). We can set up an interrupt which will be fired
on every state change of PB7. So if you push or release the button that interrupt will run.

#### Tasks
[Turning on LED with interrupts](workshop/AtmelStudio/utton_interrupt.c)

### Timer
#### 1. Timer, timer, too fast timer
The timers. Thay are a little bit complex, but don't be afraid.

At first do the first task. You will configure the TC0 timer to work in normal
operation, than you will turn the LED on/off depending of the counter register
value.

[Turning on/off LED depending on counter value](workshop/AtmelStudio/timer_basics_too_fast.c)

You are now confused, why does the LED not flashing??!! It's just vibrating!
Turn on the camera on your smartphone and watch the devboard on the screen.

Now start to shake the board! You can notice two things:
    - the green LED makes a continuous line on the screen
    - the orange LED makes a dashed line on the screen

This is because the green LED is emitting light continuously, while the orange one
is switched off sometimes. You see? The LED is flashing just your eyes can't notice it
because the human eyes is little bit slow.

Let's calculate the flashing frequency of the LED!
The I/O clock frequency is 16MHz, which we devide by 1024, so the timer gets an
effective clock frequency of 15.625kHz. The counter overflows after every 256th
clock cycle (because the timer counter register is 8-bit wide), so the counter
overflows with a frequency of approximately 60Hz. So, we toggle the LED
in 60 times in every second, hence it flashes with 30Hz. It looks to our eyes
as a vibration.

What is the solution?

Well, we could
- Lower the clock frequency of the timer by lowering the system
clock frequency.
    - On this devboard this is not possible.
- Lower the timer's clock frequency by setting the prescaler to a
higher value.
    - The prescaler is already set to the maximal 1024 value.
- Change the bit number of the counter
    - We can not change that, it is in the MCU :), so it will remain 8-bit wide.

So it looks like this timer is in it's slowest mode. What to do?

We will be tricky :), do the next task.

#### 2. Timer, timer, tricky timer
[Turning on/off LED depending on counter value, this time slower](workshop/AtmelStudio/timer_basics_speed_okay.c)

See? Now you created a counter from a variable, which counts the overflow of the
timer's counter register. 

#### 3. Timer interrupts
The timer can generate various interrupts.

Now let's see the overflow interrupt. Instead of polling the TOV0 flag we can setup
the MCU to fire az interrupt request when the TOV0 flag is set to 1 by the TC0 timer
peripheral.

[Using timer overflow interrupt](workshop/AtmelStudio/timer_overflow_interrupt.c)

#### 17812371328. Bonus tasks
The TC0 timer has other interrupt capabilities. Play with them!

## Individual Workshop Review
Please follow the styleguide: [Our C styleguide](../../../styleguide/c.md)

- Is the directory structure and the name of the files correct?
- Are the includes placed on the top of the files?
- Is the indentation good in each file?
- Is there unnecessary code?
- Can you find unnecessary code in comments?
- Is there unnecessary code duplication?
- Are there unnecessary empty blocks?
- Can you spot unused variables?
- Is the commit message meaningful?
