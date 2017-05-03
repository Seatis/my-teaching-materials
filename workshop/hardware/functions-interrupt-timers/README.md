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

TODO

timers
    wtf?
    counter
    capture

interrupts basics
interrupt datasheet pages
    - ext
    - peripheral
        - timer

## Material Review
 - Array
 - Index
 - Function
 - Function paramerter
 - Function prototype
 - `return`
 - Inline function
 - Scope
 - Local variable
 - `break`
 - `continue`
 - `switch`
 - `sizeof`
 - Recursion

## Workshop
### Arrays and sizeof
```cpp
int myArray = {1, 2, 3, 4, 5, 6};

cout << myArray[3]; // 4

myArray[1] = 15;

double myDouble = 4.5;

cout << sizeof(myDouble) // 8

```
 - [01.cpp](workshop/01.cpp)
 - [02.cpp](workshop/02.cpp)
 - [03.cpp](workshop/03.cpp)
 - [04.cpp](workshop/04.cpp)
 - [05.cpp](workshop/05.cpp)
 - [06.cpp](workshop/06.cpp)
 - [07.cpp](workshop/07.cpp)
 - [08.cpp](workshop/08.cpp)

### Functions
```cpp
void greet() {
  cout << "Hello!";
}

int main() {
  greet();
}
```

```cpp
void sayNumber(int number) {
  cout << number;
}

int main() {
  sayNumber(15);
}
```

```cpp
int add(int a, int b) {
  return a + b;
}

int main() {
  cout << add(1, 2);
}
```
 - [09.cpp](workshop/09.cpp)
 - [10.cpp](workshop/10.cpp)
 - [11.cpp](workshop/11.cpp)
 - [12.cpp](workshop/12.cpp)
 - [13.cpp](workshop/13.cpp)
 - [14.cpp](workshop/14.cpp)
 - [15.cpp](workshop/15.cpp)
 - [16.cpp](workshop/16.cpp)
 - [17.cpp](workshop/17.cpp)
 - [18.cpp](workshop/18.cpp)
 - [19.cpp](workshop/19.cpp)
 - [20.cpp](workshop/20.cpp)
 - [21.cpp](workshop/21.cpp)
 - [22.cpp](workshop/22.cpp)
 - [23.cpp](workshop/23.cpp)

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
