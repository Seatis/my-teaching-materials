# Data structures and custom types in C
*Get familiar with data structures in C language*

## Objectives
- Know the different data structures (struct, union, bit fields) in C language
- Learn how to define custom data types in C language with typedef
- Learn what is enum, and what is it used for

## Materials & Resources
### Environment
- Make sure that Code::Blocks is installed on your machine

### Training

#### Data structures

| Material | Duration |
|:---------|-----:|
| [Structures](https://www.youtube.com/watch?v=VMFKz7Klx7I) | 10:28 |
| [C - Structures](https://www.tutorialspoint.com/cprogramming/c_structures.htm) | - |
| [C - Bit Fields](https://www.tutorialspoint.com/cprogramming/c_bit_fields.htm) | - |
| [C - Unions](https://www.tutorialspoint.com/cprogramming/c_unions.htm) | - |
| [Struct vs union](https://www.youtube.com/watch?v=WpvNOv-xvnY) | 5:41 |
| [C - Enum](http://www.c4learn.com/c-programming/c-enum/) | - |
| [Passing a structure to a function](https://www.programiz.com/c-programming/c-structure-function) | - |
| [Array of structures](http://fresh2refresh.com/c-programming/c-array-of-structures/)| - |

#### Custom types
| Material | Duration |
|:---------|-----:|
| [C - typedef](https://www.tutorialspoint.com/cprogramming/c_typedef.htm) | - |
| [Passing a typedef structure to a function](http://www.how2lab.com/programming/c/structure-function.php) | - |

#### Summary
| Material | Duration |
|:---------|-----:|
| [A good summary of struct, union and typedef](https://www.codingunit.com/c-tutorial-structures-unions-typedef) | - |
| [Struct member access and typedef](https://www.programiz.com/c-programming/c-structures) | - |

#### Computer Science

| Material | Duration |
|:---------|-----:|
| [Memory and Storage](https://www.youtube.com/watch?v=TQCr9RV7twk&list=PL8dPuuaLjXtNlUrzyH5r6jN9ulIgZBpdo&index=20) | 12:16 |
| [Files and File Systems](https://www.youtube.com/watch?v=KN8YgJnShPM&index=21&list=PL8dPuuaLjXtNlUrzyH5r6jN9ulIgZBpdo) | 12:02 |
| [Compression](https://www.youtube.com/watch?v=OtDxDvCpPL4&index=22&list=PL8dPuuaLjXtNlUrzyH5r6jN9ulIgZBpdo) | 12:47 |


## Material Review

### Data structures
- Structures
    - why is it useful
    - syntax
        - using with structure tag
        - using without structure tag (instant structure variable)
        - mixing
    - arrays of structures
    - arrays as data members
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
    	- sometimes useful when using struct and unions together
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
        - speaking return values
- Bit Fields
    - why is it useful
    - syntax
    - when to use
- Structures and functions
	- different ways of returning structs
		- with return statement
		- as output parameters
	- different ways of passing structs to function
		- by value
		- by reference

### Custom types
- why is it useful
    - typical usage with structures, unions, enums
    - see the stdint.h

## Workshop

### Data structures
- [00.c](Workshop/00.c)
- [01.c](Workshop/01.c)
- [02.c](Workshop/02.c)
- [03.c](Workshop/03.c)
- [04.c](Workshop/04.c)
- [05.c](Workshop/05.c)
- [06.c](Workshop/06.c)
- [07.c](Workshop/07.c)
- [08.c](Workshop/08.c)
- [09.c](Workshop/09.c)
- [10.c](Workshop/10.c)
- [11.c](Workshop/11.c)

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
[Solutions](https://github.com/greenfox-academy/teaching-materials/tree/master/workshop-hardware/solutions/solutions/struct-union-enum-typedef)