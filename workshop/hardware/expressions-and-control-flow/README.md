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
 - Writing your first embedded C program :)

## Materials & Resources
### Environment
  - Make sure that Code::Blocks is installed on your machine
  - Make sure that Atmel Studio is installed on your machine

### Training

#### Electronics
We are going to use the ATmega168PB microcontroller's GPIO peripheral
for the first time. Read the corresponding pages from the datasheet!
It can be difficult to read, but you do not have to understand every little
bit of information. Just focus on global understanding. Try to find answers to
the following questions:
  - Which register determines the direction of the port (input or output)?
  - Which register is used to turn on or off an output pin?
  - Which register can be used to toggle a pin's state?
  - Which register can be used to read a pin's state?
  - How can be a pull-up turned on a specific pin?

| Material | Duration |
|:---------|-----:|
| [ATmega168PB I/O-Ports](http://www.atmel.com/Images/Atmel-42176-ATmega48PB-88PB-168PB_Datasheet.pdf) (pages 105-108) | - |

What the hack is a pull-up resistor? Why on earth do we need current limiting resistors
with LEDs? Watch these videos to find the answers:

| Material | Duration |
|:---------|-----:|
| [Pull Up Resistors and Buttons](https://www.youtube.com/watch?v=wxjerCHCEMg)| 3:51 |
| [Everything about LEDs and current limiting resistors](https://www.youtube.com/watch?v=Qlayua3yjuE)| 6:27 |

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
| [Nesting if statement](https://www.youtube.com/watch?v=PXwWoL0IG5A) | 4:45 |
| [if-else statement](https://www.youtube.com/watch?v=KgVzRmUPsdo) | 7:53 |
| [if-else statement](http://www.w3schools.in/c-tutorial/decision-making/if-else/) | - |
| [else-if statement](https://www.youtube.com/watch?v=DZ0ZXipUx-A) | 8:47 |
| [else-if statement](http://www.w3schools.in/c-tutorial/decision-making/else-if/) | - |
| [switch statement](https://www.youtube.com/watch?v=qZRP5hKGHrs) | 7:30 |
| [switch statement](http://www.w3schools.in/c-tutorial/decision-making/switch/) | - |
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

### Electronics
 - IDEs installed?
 - Which register determines the direction of the port (input or output)?
 - Which register is used to turn on or off an output pin?
 - Which register can be used to toggle a pin's state?
 - Which register can be used to read a pin's state?
 - How can be a pull-up turned on a specific pin?
 - pull-up/pull-down resistors
 - current limiting resistors

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
int a;
a = a + 1;
a += 1;
```

#### Excercises
 - [01.c](workshop/CodeBlocks/01.c)
 - [02.c](workshop/CodeBlocks/02.c)
 - [03.c](workshop/CodeBlocks/03.c)
 - [04.c](workshop/CodeBlocks/04.c)
 - [05.c](workshop/CodeBlocks/05.c)
 - [06.c](workshop/CodeBlocks/06.c)


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
 - [07.c](workshop/CodeBlocks/07.c)
 - [08.c](workshop/CodeBlocks/08.c)
 - [09.c](workshop/CodeBlocks/09.c)
 - [10.c](workshop/CodeBlocks/10.c)
 - [11.c](workshop/CodeBlocks/11.c)

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
 - [12.c](workshop/CodeBlocks/12.c)
 - [13.c](workshop/CodeBlocks/13.c)
 - [14.c](workshop/CodeBlocks/14.c)

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
 - [15.c](workshop/CodeBlocks/15.c)
 - [16.c](workshop/CodeBlocks/16.c)
 - [17.c](workshop/CodeBlocks/17.c)
 - [18.c](workshop/CodeBlocks/18.c)
 - [19.c](workshop/CodeBlocks/19.c)
 - [20.c](workshop/CodeBlocks/20.c)
 - [21.c](workshop/CodeBlocks/21.c)
 - [22.c](workshop/CodeBlocks/22.c)


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
 - [23.c](workshop/CodeBlocks/23.c)
 - [24.c](workshop/CodeBlocks/24.c)
 - [25.c](workshop/CodeBlocks/25.c)
 - [26.c](workshop/CodeBlocks/26.c)

### First embedded C program
You will program the Atmel development board for the first time. A mentor
will guide you through the usage of the Atmel Studio.

#### Programming the example code
- Load the example project
    - Connect the USB cable to your machine
    - Connect the USB cable's other end to the devboard
    - Start AtmelStudio
    - Click on File->New->Example project
    - In the search field type "ATmega168PB" (without the "" symbols)
    - Choose the "led example" from the list
    - Choose the location of the project
        - keep in mind that the code has to be pushed to your github repository
        - put the files in the week-x/day-y folder
            - x is the current week
            - y is the current day of the week
    - Click on OK
- Program the device
    - Click on Project->Properties
    - Choose Tools on the left
    - Select mEDBG from the "Selected debugger/programmer" list
    - Select debugWire from the "Interface" list
    - Save settings by hitting Ctrl+S
    - Click on Debug->Start without debugging
 - Check if it workshop
    - If you push the button, the LED is lit

#### Using a port as output
- Create a project
    - Click on New->project
    - Select GCC C Executable
    - Give a name to the project
    - Choose the location of the project
        - keep in mind that the code has to be pushed to your github repository
    - In the device selection window type "atmega168pb"
    - Now only one entry should be in the list
    - Select it and click on ok
- Copy the source code of LED_blinker.c into main.c
- Fill in the code where asked
- Program the device as described in the previous task

## Individual Workshop Review
Please follow the styleguide: [Our C styleguide](../../styleguide/c.md)

 - Is the directory structure and the name of the files correct?
 - Are the includes placed on the top of the files?
 - Is the indentation good in each file?
 - Is there unnecessary code?
 - Can you find unnecessary code in comments?
 - Is there unnecessary code duplication?
 - Are there unnecessary empty blocks?
 - Can you spot unused variables?
 - Is the commit message meaningful?
