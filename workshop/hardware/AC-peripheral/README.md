# Analog comparator peripheral
*TODO*

## Objectives
- Learn how to measure the frequency of an analog signal with an MCU
- Know more about the input capture timer mode
- Learn how does the AC peripheral works

## Materials & Resources
### Environment
- Make sure that Atmel Studio is installed on your machine

### Training
#### Input capture unit of timers
Usually MCU timers have an "Input Capture unit".

Take a look at the [ATmega168PB's datasheet](http://www.atmel.com/Images/Atmel-42176-ATmega48PB-88PB-168PB_Datasheet.pdf) at page 170. You can see the TC1 timer's input capture unit. Let's talk about what
you can see on the diagram!

The timer has an input pin (ICP1), which is connected to an edge detector circuit.
This edge detector will emit an impulse on it's output if an edge (falling or rising, depending on the value of the ICES bit) is detected on the ICP1 pin. When this impulse is emitted, the value of the 16-bit wide TCNT1 register will be
copied to the 16-bit wide ICR1 register.

So basically the TC1 timer's counter register value is saved to an another register
if an edge is detected in the ICP1 pin's signal.

This feature could be very useful, for example you can measure the frequency of a
signal with it.

#### Measuring frequency with input capture unit
The basic idea behind this technique is to get a clock signal with a known period, then
count how many clock period will pass between two edges of the input signal. An
MCU timer can do the trick, basically it counts the periods of it's input clock frequency.
If we could save the timer counter register's value on the edge of the input signal, than based on the clock period and the last two register value we could determine the
signal's period, and with that, the frequency:

signal's period = clock period * (latest register value - previous register value)

signal's frequency = 1 / signal's period

The input capture unit works exactly this way, but in real life there is a problem
with it: if the counter overflows between two input signal edge, then the difference
of the register values won't give us the correct result, we have to count the overflows.

Take a look the following diagram as an example. With green you can see the signal
on the ICP1 pin, it's period is marked with "T". With blue you can see the TC1
counter register's value as the time passes by, the vertical lines are representing
the register overflows.

<img src="img/input_capture.png" width="50%"></img>

Let's say that the counter input clock frequency, Tclk is 1us. The T period can be
calculated if the Tclk and the counter steps between two neighboring rising edges are
multiplied.

How many counter steps are between the first two rising edges? At the first
rising edge the counter value is 48544, then the counter overflows twice, then
the at the next rising edge the counter value is 14563. This can be written like:

steps = (65535 - 48544) + 65535 + 14563 = 2 * 65535 + 14563 - 48544

In general:

steps = overflows * counter_max + latest_counter_value - previous_counter_value

Then the T period can be calculated:

T = Tclk * steps

In this example:

T = 1us * 194177 = 194.177ms

f = 1 / T = 5.15 Hz

#### AC peripheral
Read these articles on comparators.

Get a global understanding of the usage of the peripheral.

| Material | Duration |
|:---------|-----:|
| [Analog Comparator Explanation](https://www.youtube.com/watch?v=Xc9hmoGeiLE) | 3:10 |
| [Comparator](https://www.youtube.com/watch?v=Xc9hmoGeiLE) | - |

Also read the corresponding pages of the datasheet of ATmega168PB (315-321). Check the main things:
 - 28.1. AC - Analog Comparator overview
  - Figure 28-1. Analog Comparator Block Diagram

 - 28.2. Analog Comparator Multiplexed Input
 - 28.3. Register Description
  - ACSR
  - ACSR0
  - DIDR1
  - ADCSRB


## Material Review
### Analog comparator  
- Physical layer
    - Signals
        - -
        - +
        - ACO
 - Analog comparator vs. operational amplifiers
- AC of ATmega168PB
    - registers
        - ACSR Analog Comparator Control and Status Register
        - ACSR0 Analog Comparator Control and Status Register C
        - DIDR1 Digital Input Disable Register 1
        - ADCSRB ADC Control and Status Register B
    - typical init procedure
        - set master or slave mode
        - set slave address
        - set I2C mode
        - set bit rate
        - enable I2C interrupt if needed
        - enable I2C peripheral

## Workshop
### Analog Comparator
#### Setting up the hardware
Make the following connection between the reflective opto sensor and the ATmega168PB Xplained board:

<img src="img/GF-ATmega168PB-rotation-measurement.png" width="50%"></img>

[TCRT5000 datasheet](http://www.vishay.com/docs/83760/tcrt5000.pdf)

[ATmega168PB Xplained user manual](http://www.atmel.com/Images/Atmel-42381-ATmega168PB-Xplained-Mini_UserGuide.pdf)

#### Writing driver software
You are going to write a software which can measure time difference between two
impulses. This can be used to measure frequency.
It is useful to put all the hardware specific code in a separate .c and .h file, so it can be reused in another project just by copying those files.

Steps:
- create a new AtmelStudio project
- copy the [following files](#) to the project folder (next to the automatically generated main.c file)
- overwrite the files if asked
- add the files to the project
- write the code where asked (marked with "TODO")
    - always test the code after you wrote a few lines of code
    - write the needed functions in the following order
        - TODO
        - TODO
        - TODO
- test the driver with the FAN

## Individual Workshop Review
Please follow the styleguide: [Our C styleguide](https://github.com/greenfox-academy/teaching-materials/blob/master/styleguide/c.md)

 - Is the directory structure and the name of the files correct?
 - Are the includes placed on the top of the files?
 - Is the indentation good in each file?
 - Is there unnecessary code?
 - Can you find unnecessary code in comments?
 - Is there unnecessary code duplication?
 - Are there unnecessary empty blocks?
 - Can you spot unused variables?
 - Is the commit message meaningful?

## Solutions
[Solutions](#)
