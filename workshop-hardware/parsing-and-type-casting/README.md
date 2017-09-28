# Parsing and type casting
*Learn how to use parsing and type casting properly*

## Objectives
- Know the most common parsing techniques with string.h library
- Practice type-casting

## Materials & Resources
### Environment
  - Make sure that Code::Blocks is installed on your machine

### Training

#### Typecasting
| Material | Duration |
|:---------|-----:|
| [Typecasting](https://www.youtube.com/watch?v=ohVRskLlHqM) | 5:35 |
| [C Typecasting](https://www.tutorialspoint.com/cprogramming/c_type_casting.htm) | - |
| [C Typecasting](http://www.w3schools.in/c-tutorial/type-casting/) | - |


#### Transforming between number systems
| Material | Duration |
|:---------|-----:|
| [`atoi`](https://www.tutorialspoint.com/c_standard_library/c_function_atoi.htm) | - |
| [`strtol`](https://www.tutorialspoint.com/c_standard_library/c_function_strtol.htm) | - |
| [stdlib.h](http://www.cplusplus.com/reference/cstdlib/) | - |


#### Parsing
| Material | Duration |
|:---------|-----:|
| [How C strings work](https://www.programiz.com/c-programming/c-strings) | - |
| [`strstr`](https://www.tutorialspoint.com/c_standard_library/c_function_strstr.htm) | - |
| [`strcmp`](https://www.programiz.com/c-programming/library-function/string.h/strcmp) | - |
| [`strtok`](https://www.youtube.com/watch?v=LsWxVwCqVO4) | 3:33 |
| [string.h function reference](http://www.cplusplus.com/reference/cstring/) | - |

#### Computer Science
| Material | Duration |
|:---------|-----:|
| [Intro to Algorithms](https://www.youtube.com/watch?v=rL8X2mlNHPM&list=PL8dPuuaLjXtNlUrzyH5r6jN9ulIgZBpdo&index=14) | 11:43 |
| [Data Structures](https://www.youtube.com/watch?v=DuDz6B4cqVc&index=15&list=PL8dPuuaLjXtNlUrzyH5r6jN9ulIgZBpdo) | 10:06 |
| [Turing Machine](https://www.youtube.com/watch?v=7TycxwFmdB0&index=16&list=PL8dPuuaLjXtNlUrzyH5r6jN9ulIgZBpdo) | 13:04 |


## Material Review
### Type-casting
- any implicit type conversions made from a lower size type to a higher size type: `char -> int -> unsigned int -> long -> unsigned long -> long long -> unsigned long long -> float -> double -> long double`

### Transforming
- Inbuilt transforming functions in C: `atof(), atoi(), atol(), itoa(), ltoa(), strtod(), strtol()`

### Parsing
- `string.h` functions
- tokenizing strings
- checking if a string is contained by another string
- finding a character's position in a string
- comparing two strings

## Workshop
### Typecasting
- [01.c](Workshop/01.c)
- [02.c](Workshop/02.c)
- [03.c](Workshop/03.c)
- [04.c](Workshop/04.c)
- [05.c](Workshop/05.c)
- [06.c](Workshop/06.c)
- [07.c](Workshop/07.c)

### Transforming
- [08.c](Workshop/06.c)
- [09.c](Workshop/07.c)

### Parsing
- [10.c](Workshop/08.c)
- [11.c](Workshop/09.c)
- [12.c](Workshop/10.c)
- [13.c](Workshop/10.c)

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
[Solutions](https://github.com/greenfox-academy/teaching-materials/tree/master/workshop-hardware/solutions/solutions/parsing-and-type-casting)
