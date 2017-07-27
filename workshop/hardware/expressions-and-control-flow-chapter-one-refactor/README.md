# Expressions and Control flow chapter one
*Meet the base elements of the C language by implementing small programs*

## Objectives
 - Understanding the Compiler
 - Using basic types
 - Creating and reading expressions
 - Declaring and defining variables
 - Using variables and mutate values
 - Understanding conditionals
 - Using while and for loops
 - Casting Types

## Materials & Resources
### Environment
  - Make sure that Code::Blocks is installed on your machine

### Training


#### C programming language

| Material | Duration |
|:---------|-----:|
| **Instruction** |
| [Instructions & Programs](https://www.youtube.com/watch?v=zltgXvg6r3k) | 10:35 |
| [Understanding C program Compilation Process](https://www.youtube.com/watch?v=VDslRumKvRA) | 6:03 |
| [Compilers, Assemblers, Linkers, Loaders: A Short Course](https://courses.cs.washington.edu/courses/cse378/97au/help/compilation.html) (only the "Compiling a Program" section)| - |
| [Setting Up Code Blocks](https://www.youtube.com/watch?v=3DeLiClDd04) | 6:37 |
| [How Computer Programs Work](https://www.youtube.com/watch?v=iWx3yyFMWQA) | 4:51 |
| [Comments](https://www.youtube.com/watch?v=oX2FpFYXE38) | 3:28 |
| [C program structure](http://www.w3schools.in/c-tutorial/program-structure/) | - |
| Printing text |
| [Print Text on the Screen](https://www.youtube.com/watch?v=oSpmApiUsHw) | 3:32 |
| [Conversion Characters](https://www.youtube.com/watch?v=To7WA4ijQQ0) | 6:46 |
| [Format specifiers](http://www.w3schools.in/c-tutorial/format-specifiers/) | - |
| Variables |
| [Variables](https://www.youtube.com/watch?v=k1ur8rX-DQQ) | 7:48 |
| [Data types](http://www.w3schools.in/c-tutorial/data-types/) | - |
| [More data types](https://www.tutorialspoint.com/cprogramming/c_data_types.htm) | - |
| [stdint.h types](https://developer.mbed.org/handbook/C-Data-Types)| - |
| [Variables](http://www.w3schools.in/c-tutorial/variables/) | - |
| [Constants](http://www.w3schools.in/c-tutorial/constants/) | - |
| [Keywords](http://www.w3schools.in/c-tutorial/keywords/) | - |
| Math operators |
| [Basic math operators](https://www.youtube.com/watch?v=T3sj5iTK_0M) | 5:11 |
| [Increment Operator](https://www.youtube.com/watch?v=nNSn1uVNyiU) | 5:11 |
| [List of operators](http://www.w3schools.in/c-tutorial/operators/) | - |
| [Using braces](https://www.youtube.com/watch?v=rubhV7Bu34E) | 4:58 |
| Decision making |
| [if statement](https://www.youtube.com/watch?v=PXwWoL0IG5A) | 7:53 |
| [if statement](http://www.w3schools.in/c-tutorial/decision-making/if/) | - |
| [Nesting if statement](https://www.youtube.com/watch?v=FtZ1YgSFqs0) | 4:45 |
| [if-else statement](https://www.youtube.com/watch?v=KgVzRmUPsdo) | 7:53 |
| [if-else statement](http://www.w3schools.in/c-tutorial/decision-making/if-else/) | - |
| [else-if statement](https://www.youtube.com/watch?v=DZ0ZXipUx-A) | 8:47 |
| [else-if statement](http://www.w3schools.in/c-tutorial/decision-making/else-if/) | - |

## Material Review


### C programming language
 - how compilation works
    - preprocessor
    - compiler
    - assembler
    - linker
 - printf basics
 - comments
 - variables
    - keywords
    - datatype
        - void, int, float, double, char
        - unsigned int and char
        - char, short, int, longlong
        - why do we use instead stdint.h types
            - `int8_t`, `int16_t`, `int32_t`, `int64_t`
            - `uint8_t`, `uint16_t`, `uint32_t`, `uint64_t`
    - constants
    - literals
        - integers
        - binary (0b011)
        - hexadecimal (0xFF)
        - floats (0.125f) vs. double (0.125)
 - math operators
    - `+`, `-`, `*`, `/`, `%`
    - `--i`/`++i` and `i--`/`i++`
    - `+=`, `-=`, `*=`, `/=`
 - logical operators
    - `==`, `>`, `>=`, `<`, `<=`, `!=`
    - `&&`, `||`, `!`
    - no boolean datatype by deafult

*Note that `=` and `==` are not the same thing. For assignment C uses `=`, for comparison `==`.*
*Let's have a quick look at the example below:*

```
if (x == y) {
    break;
}
```
*This program ends if the value of x and y are the same*

```
int a = 10;
int b = 20;
```
*These lines simply assign the given value to the declared variables*

- bitwise operators
   - `<<`, `>>`, `~`, `&`, `|`, `^`
   - `<<=`, `>>=`, `~=`, `&=`, `|=`, `^=`
- if statement
- nested if statement
- else
- else-if
- `?:` ternary operator

## Workshop

### Hello World
```c_cpp
#include <stdio.h>
void main{
    printf("Hello world!");
}
```

### Numbers
```c_cpp
1
0
123
-1
1.1
1.0
0b0011
0b11001100
0xFE
0x12

1 + 1
2 - 1
3 * 4
1 / 2
1 / 0
1 % 2
(1 + 3) * 4
```

### Variables
```c_cpp
int a = 1;
int b = 8;
a = a + 1;
a += 1;
float b = 3.14;
char c = 'g';
```


### Printing out Variables

| Method | Output |
|:---------|:-----|
| %d | print as a decimal integer|
| %6d | print as a decimal integer, at least 6 characters long |
|%f| print as a floating point|
|%6f| print as a floating point, at least 6 characters long|
|%.2f|print as a floating point, 2 characters after decimal point |
|%6.2f| print as a floating point, 6 decimal characters and 2 characters after decimal point|
| %o | for octal|
| %x | for hexadecimal|
| %c | for character|
| %s | for string|

#### Excercises
 - [01.c](Workshop/01.c)
 - [02.c](Workshop/02.c)
 - [03.c](Workshop/03.c)
 - [04.c](Workshop/04.c)
 - [05.c](Workshop/05.c)
 - [06.c](Workshop/06.c)


### Logical operators
```c_cpp
a == 2
1 < 2
1 > 2
1 == 2
1 != 2
a || b
b && c
!(d && c)
```

#### Excercises
 - [07.c](Workshop/07.c)
 - [08.c](Workshop/08.c)
 - [09.c](Workshop/09.c)
 - [10.c](Workshop/10.c)
 - [11.c](Workshop/11.c)

### Embedded related datatypes, literals, operators
```c_cpp
uint8_t a = 60;
uint8_t b = 0b00111010;
uint8_t c = 0x3C;
uint8_t d = 0x3c;
if(a == b && b == c && c == d){
    printf("Equal!"); // They are equal
}
```

#### Excercises
 - [12.c](Workshop/12.c)
 - [13.c](Workshop/13.c)
 - [14.c](Workshop/14.c)

### If
```c_cpp
if (a < 100)
    printf("small\n");
else if (a < 1000)
    printf("medium\n");
else
    printf("large\n");


```
#### Excercises
 - [15.c](Workshop/15.c)
 - [16.c](Workshop/16.c)
 - [17.c](Workshop/17.c)
 - [18.c](Workshop/18.c)
 - [19.c](Workshop/19.c)
 - [20.c](Workshop/20.c)
 - [21.c](Workshop/21.c)
 - [22.c](Workshop/22.c)
##### Advanced Excercises

- [23.c](Workshop/23.c)
- [24.c](Workshop/24.c)
- [27.c](Workshop/27.c)
- [28.c](Workshop/28.c)
- [29.c](Workshop/29.c)
