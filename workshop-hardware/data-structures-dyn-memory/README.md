# Data structures, dynamically allocated memory and custom types in C
*Get familiar with data structures, dynamically allocated memory and custom types in C language*

## Objectives
- Know the different data structures in C language
- Learn how to define custom data types in C language
- Learn how to allocate memory during runtime

## Materials & Resources
### Environment
- Make sure that Code::Blocks is installed on your machine

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

#### Dynamic memory allocation
| Material | Duration |
|:---------|-----:|
| [C Dynamic Memory Allocation](https://www.programiz.com/c-programming/c-dynamic-memory-allocation) | - |
| [Pointers and memory leaks in C](https://www.ibm.com/developerworks/aix/library/au-toughgame/) | - |

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
    - **ALWAYS** use include guards!

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
- Enumerations
    - why is it useful
    - syntax
        - using with enum tag
        - using without enum tag (instant enum variable)
        - mixing
    - automatic number assignment
    - forced number assignment
    - when to use
        - state machines
- Bit Fields
    - why is it useful
    - syntax
    - when to use

### Dynamic memory allocation
- `malloc()`
    - returns `void*`
    - reserves given number of bytes (`sizeof()`!)
- `calloc()`
    - returns `void*`
    - reserves given number of given sized blocks
    - fills memory with zeros
    - useful for arrays
- `free()`
    - **ALWAYS** free dynamically allocated memory pointers
    - memory leak
- `realloc()`
    - previously allocated memory size change
- why don't we allocate dynamically memory in embedded systems
    - slow
    - long running code
        - memory leak is dangerous
        - fragmentation
    - not really required

### Custom types
- why is it useful
    - typical usage with structures, unions, enums
    - see the stdint.h

## Workshop
### Creating .h and .c files
- [1](workshop/CodeBlocks/MultipleFiles)

### Dynamic memory allocation
- [1](workshop/CodeBlocks/DynamicMemory/01.c)
- [2](workshop/CodeBlocks/DynamicMemory/02.c)
- [3](workshop/CodeBlocks/DynamicMemory/03.c)
- [4](workshop/CodeBlocks/DynamicMemory/04.c)

### Data structures
- [0](workshop/CodeBlocks/DataStructures/00.c)
- [1](workshop/CodeBlocks/DataStructures/01.c)
- [2](workshop/CodeBlocks/DataStructures/02.c)
- [3](workshop/CodeBlocks/DataStructures/03.c)
- [4](workshop/CodeBlocks/DataStructures/04.c)
- [5](workshop/CodeBlocks/DataStructures/05.c)
- [6](workshop/CodeBlocks/DataStructures/06.c)
- [7](workshop/CodeBlocks/DataStructures/07.c)

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
[Solutions](https://github.com/greenfox-academy/teaching-materials/tree/master/workshop/hardware/solutions/data-structures-dyn-memory/CodeBlocks)
