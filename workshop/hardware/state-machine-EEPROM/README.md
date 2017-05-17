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
- solution with function pointers

### EEPROM
- how does it work
- write count
    - be aware not to write it too much
    - typical problem is an unintentional fast infinite loop
- usage in ATmega168PB
    - `avr/eeprom.h`
    - `eeprom_write/read/update_byte/word/dword/float/block`

## Workshop
- eeprom functions
- eeprom with EEMEM
    - usage
    - default values
- enum state machine
- UART command change state

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
