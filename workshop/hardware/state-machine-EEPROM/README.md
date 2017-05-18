# State machines and the EEPROM
*Learn how to implement state machines and how to use EEPROM with ATmega168PB*

## Objectives
- know how to implement a state machine
- understanding how does the EEPROM works in ATmega168PB

## Materials & Resources
### Environment
- Make sure that Code::Blocks is installed on your machine
- Make sure that Atmel Studio is installed on your machine

### Training
#### State machines
| Material | Duration |
|:---------|-----:|
| [Microcontroller state machine with enum tutorial](https://www.baldengineer.com/state-machine-with-enum-tutorial.html) | - |

#### EEPROM
| Material | Duration |
|:---------|-----:|
| [Using the EEPROM in AVR-GCC](http://www.github.com/abcminiuser/avr-tutorials/blob/master/EEPROM/Output/EEPROM.pdf?raw=true) | - |

## Material Review

### State machines
- why we use them
- for what we use them
- solution with enum
- UARTing

### EEPROM
- how does it work
- write count
    - be aware not to write it too much
    - typical problem is an unintentional fast infinite loop
- usage in ATmega168PB
    - `avr/eeprom.h`
    - `eeprom_write/read/update_byte/word/dword/float/block`

## Workshop
### Using the EEPROM in the ATmega168PB
This exercise's goal is to practice the usage of eeprom related library functions.
We are going to write something to the EEPROM and read it back from it.

[Exercise](workshop/AtmelStudio/EEPROM_basics)

### The EEMEM specifier
This exercise's goal is to practice the usage of the EEMEM specifier.
We are going to write something to the EEPROM in an other way than earlier.

[Exercise](workshop/AtmelStudio/EEPROM_EEMEM)

### State machines with enum
This exercise's goal is to learn how to implement a basic state machine on
the ATmega168PB MCU.
We are going to make a device, which can receive various commands through UART,
and these command will push the MCU into different states.

| Command string | State | What it does in this state |
|:---------------|:------|:---------------------------|
|LED_BLINKER|LED_BLINKER|It blinks the LED on PB5|
|LED_PUSHBUTTON|LED_PUSHBUTTON|The LED on PB5 is lit when the button on PB7 is pressed|
|TURN_LED_ON|TURN_LED_ON|The LED on PB5 is lit|
|TURN_LED_OFF|TURN_LED_OFF|The LED on PB5 is unlit|

[Exercise](workshop/AtmelStudio/state_machine_enum)

### State save/load to EEPROM
Complete the previous exercise:
- the program should read the state from the EEPROM at startup
- the program should save the new state to the EEPROM when the state changes (when a new valid command arrives)

## Individual Workshop Review
Please follow the styleguide: [Our C styleguide](https://github.com/greenfox-academy/teaching-materials/blob/master/styleguide/c.md)

 - Is the directory structure and the name of the files correct?
 - Are the includes placed on the top of the files?
 - Is the indentation good in each file?
 - Is there unnecessary code?
 - Can you find unwnecessary code in comments?
 - Is there unnecessary code duplication?
 - Are there unnecessary empty blocks?
 - Can you spot unused variables?
 - Is the commit message meaningful?

## Solutions
