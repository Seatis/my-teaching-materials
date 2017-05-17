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
#### Function pointers
| Material | Duration |
|:---------|-----:|
| [How to declare a pointer to a function?](http://www.geeksforgeeks.org/how-to-declare-a-pointer-to-a-function/) | - |
| [Function Pointer in C](http://www.geeksforgeeks.org/function-pointer-in-c/) | - |

#### State machines
| Material | Duration |
|:---------|-----:|
| [State Machines with C Callbacks](http://codeandlife.com/2013/10/06/tutorial-state-machines-with-c-callbacks/) | - |

#### EEPROM
| Material | Duration |
|:---------|-----:|

#### Optional materials
*If you have more time and would like to know more about the topic*
TODO: eeprom advanced

## Material Review
### Function pointers
- why??!!
- syntax

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
- storing data in EEPROM
- reading data from EEPROM
- enum state machine
- function pointer wtfing
- state machine with function pointers

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
