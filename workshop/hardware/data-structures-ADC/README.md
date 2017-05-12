# Data structures and custom types in C, ADC
*Get familiar with data structures and custom data types in C language and
lear how to use analog-to-digital converters*

## Objectives
- Know the different data structures in C language
- Lear how to define custom data types in C language
- Use the ADC peripheral in the ATmega168PB

## Materials & Resources
### Environment
  - Make sure that Code::Blocks is installed on your machine
  - Make sure that Atmel Studio is installed on your machine

### Training
#### Creating .h and .c files

| Material | Duration |
|:---------|-----:|
| [Creating a Header File](https://www.youtube.com/watch?v=1EeetMPACMI&t=1s) | 9:51 |
| [C - Header Files](https://www.tutorialspoint.com/cprogramming/c_header_files.htm) | - |

#### Data structures

| Material | Duration |
|:---------|-----:|
| [Structures](https://www.youtube.com/watch?v=VMFKz7Klx7I) | 10:28 |
| [C - Structures](https://www.tutorialspoint.com/cprogramming/c_structures.htm) | - |
| [C - Unions](https://www.tutorialspoint.com/cprogramming/c_unions.htm) | - |
| [C - Enum](http://www.c4learn.com/c-programming/c-enum/) | - |
| [C - Bit Fields](https://www.tutorialspoint.com/cprogramming/c_bit_fields.htm) | - |

#### Custom types
| Material | Duration |
|:---------|-----:|
| [C - typedef](https://www.tutorialspoint.com/cprogramming/c_typedef.htm) | - |

## Material Review
### Creating .h and .c files
- why do we do this
- how this works
- `#include`
- include guards
    - `#ifndef/#define/#endif`
        - standard
    - `#pragma once`
        - non-standard, but usually works

### Data structures
- Structures
    - why is it useful
    - syntax
        - using with structure tag
        - using without structure tag (instant structure variable)
        - mixing
    - accessing members
        - if we have the structure variables
        - if we have a pointer to a structure variable
    - when to use
- Unions
    - why is it useful
    - syntax
        - using with union tag
        - using without union tag (instant union variable)
        - mixing
    - when to use
- Enum
    - why is it useful
    - syntax
        - using with union tag
        - using without union tag (instant union variable)
        - mixing
    - when to use
- Bit Fields
    - why is it useful
    - syntax
    - when to use

### Custom types
- why is it useful
    - typical usage with structures, unions, enums
    - see the stdint.h
- automatic number assignment
- forced number assignment
- when to use
    - state machines

## Workshop
TODO

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
