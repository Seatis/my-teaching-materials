# Expressions and Control flow
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
| [switch statement](https://www.youtube.com/watch?v=qZRP5hKGHrs) | 7:30 |
| [switch statement](http://www.w3schools.in/c-tutorial/decision-making/switch/) | - |
| [switch vs if](http://www.geeksforgeeks.org/switch-vs-else/) | - |
| Logical operators |
| [Basics](https://www.youtube.com/watch?v=PO3BibcbkK8) | 5:44 |
| [Or](https://www.youtube.com/watch?v=brC8O7AeCFA) | 5:44 |
| [List of operators](http://www.w3schools.in/c-tutorial/operators/) | - |
| Loops |
| [while loop](https://www.youtube.com/watch?v=7pAXm7WEA2I) | 8:28 |
| [while loop](http://www.w3schools.in/c-tutorial/loops/while/) | - |
| [do-while loop](https://www.youtube.com/watch?v=eU6no0EEJM0) | 10:42 |
| [do-while loop](http://www.w3schools.in/c-tutorial/loops/do-while/) | - |
| [for loop](https://www.youtube.com/watch?v=FPjLbPu5BsQ) | 5:19 |
| [for loop](http://www.w3schools.in/c-tutorial/loops/for/) | - |
| [break](https://www.youtube.com/watch?v=JKVc02-GmGs) | 6:26 |
| [continue](https://www.youtube.com/watch?v=4XaaIGBdhaw) | 4:47 |
| [Loop control statements](http://www.w3schools.in/c-tutorial/loops/) | - |
| [Why never use goto](https://tr1.cbsistatic.com/hub/i/2015/05/07/294fc704-f487-11e4-940f-14feb5cc3d2a/goto.png) | - |

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
- switch
- while loop
- do while loop
- for loop

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

The size of these objects is also machine-dependent. There are also arrays, structures and unions of these basic types, pointers to them, and functions that return them, all of which we will meet in due course.

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
if (a == 2) {
    printf("%d\n", a);
}

if (a < 16) {
    printf("%d\n", a + 1);
}
else if ( a <= 40) {
    printf("%d\n", a - 1);
}
else {
    printf("%d\n", a);
}

if (a <= 40) {
    if (a < 16) {
        printf("%d\n", a + 1);
    }
    else {
        printf("%d\n", a - 1);
    }
    else {
        printf("%d\n", a);
}
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


### While / Do - While / For
```c_cpp
int a = 0;
while (a < 5) {
    a += 1;
    printf("%d\n", a);
}

do {
    a += 1;
    printf("%d\n", a);
} while (a < 5);

for (a = 0; a < 5; a++) {
    printf("%d\n", a);
}
```

#### Excercises
Please do the excercises with while && do-while && for
 - [23.c](Workshop/23.c)
 - [24.c](Workshop/24.c)
 - [25.c](Workshop/25.c)
 - [26.c](Workshop/26.c)

 ### Switch

 ```
 switch(expressions){

 case(condition_1):
     execute your code;
 case(condition_2):
     execute your code;
 ...
 defaul:
     execute your code;
 }
 ```

 #### Excercises

 - [27.c](Workshop/27.c)
 - [28.c](Workshop/28.c)
 - [29.c](Workshop/29.c)
 - [30.c](Workshop/30.c)
 - [31.c](Workshop/31.c)

 ### If vs. Switch
 Programming languages provide various constructs to support this
 requirement, e.g., the if-statement (which often supports checking against a single value) and the switchstatement
 (which supports the checking against a set of values). Measurements show that approximately
 every fifth statement is a selection statement. The last sentence sums up great why should we talk about it.

 You can already tell that switch is unnecessary, there is not such a task or problem where you have to use switch-statement. One of the main reasons using switch-statement is compiler optimalization. Right now it might not be such a big deal, but it is an important skill to know how to optimalize a code or what can you do to lower the run time. I have to mention that switch-statement also requiers less developer effort in certain situations.

 Common constraints on the use of the switch-statements include:
 - the value must be known at translation time
 - and that value must be representable as an integer type

 #### Excercises

 - [32.c](Workshop/32.c)


##### Advanced Excercises

- [33.c](Workshop/33.c)
- [34.c](Workshop/34.c)
- [35.c](Workshop/35.c)
- [36.c](Workshop/36.c)
- [37.c](Workshop/37.c)
- [38.c](Workshop/38.c)
- [39.c](Workshop/39.c)
- [40.c](Workshop/40.c)
