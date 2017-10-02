# Arrays and user input
*Learn how to use user input in C programs with arrays*

## Objectives
- Know how to use arrays in C language
- Understanding how functions associated with user input works

## Materials & Resources
### Environment
  - Make sure that Code::Blocks is installed on your machine

### Training
#### C programming language
##### Arrays
| Material | Duration |
|:---------|-----:|
| [Introduction to arrays](https://www.youtube.com/watch?v=LEHaSSYreeo) | 5:21 |
| [char arrays](https://www.youtube.com/watch?v=7F-Q2oVBYKk) | 5:46 |
| [int and float arrays](https://www.youtube.com/watch?v=IPYA3b3_nyk) | 8:08 |
| [Arrays](http://www.w3schools.in/c-tutorial/arrays/) | - |
| [Strings](http://www.w3schools.in/c-tutorial/strings/) | - |
| [`strcat` and `strcpy`](https://www.youtube.com/watch?v=-SSsm0gVu3o) | 9:05 |
| [string.h function reference](http://www.cplusplus.com/reference/cstring/) | - |

##### User input
| Material | Duration |
|:---------|-----:|
| [`scanf` usage](https://www.youtube.com/watch?v=hSHFjPvqFjw) | 5:21 |
| [`puts` and `gets` usage](https://www.youtube.com/watch?v=yvpCxgV3AZo) | 6:15 |
| [stdio.h function reference](http://www.cplusplus.com/reference/cstdio/) | - |
| A little bit [fun](https://www.youtube.com/watch?v=nKlKYYMCXc8) | 13:43 |

#### Computer Science

| Material | Duration |
|:---------|-----:|
| [Early programming](https://www.youtube.com/watch?v=nwDq4adJwzM&index=11&list=PL8dPuuaLjXtNlUrzyH5r6jN9ulIgZBpdo) | 9:25 |
| [The First Programming Languages ](https://www.youtube.com/watch?v=RU1u-js7db8&index=12&list=PL8dPuuaLjXtNlUrzyH5r6jN9ulIgZBpdo) | 11:51 |
| [Statements and  Functions](https://www.youtube.com/watch?v=l26oaHV7D40&list=PL8dPuuaLjXtNlUrzyH5r6jN9ulIgZBpdo&index=13) | 11:56 |

## Material Review
- arrays
    - syntax
    - char arrays = strings
    - int, float
    - `string.h` functions
    - why it it good?
    - why we use it?

- user input
    - syntax
    - `scanf`, `gets`
    - `stdio.h` other functions
    - why it it good?
    - why we use it?

### C programming language
#### Arrays
- char arrays = strings
- int, float
- `string.h` functions (`strcpy` and others)

#### User input
- `stdio.h` functions (`gets`, `scanf` and others)


### Computer Science
- Early Programming
	- Programmable textile run
		- by punch card
	- Hollerith tabulating machine
		- not really computers
	- evolution of plugboards
	- stored-program computers
		- stores program instructions in electronic memory
	- Von Neumann architecture
	- Panel programming

- The First Programming Languages
	- Pseudo-code: high-level description of the operating principle of a program
	- Assembler: reusable helper programs in binary
		- text-based intructions
	- first compiler: transforms source code into a low-level language like assembly
	- Fortran: Formula Translation
		- made easier to write programs
	- Cobol: COmmon Business Oriented Language
		- worked in every computers
	- 60s: ALGOL, LISP, BASIC
	- 70s: Pascal, C, Smalltalk
	- 80s: C++, Objective-C, Perl
	- 90s: Python, Ruby, Java
	- 2000s: Swift, C#, Go

- Statements & Functions
	- syntax: the set of rules that govern the structure and composition of statements in a language
	- variable
		- initializing and assigning a value to a variable
	- conditional statements
	- loops
	- functions, methods, subroutin
		- to hide complexity (function can call another functions)
		- return statement
	- libraries: huge bundles of pre-written functions

## Workshop
### Arrays
- [Arrays/1.c](Workshop/arrays_1.c)
- [Arrays/2.c](Workshop/arrays_2.c)
- [Arrays/3.c](Workshop/arrays_3.c)

### User input
- [UserInput/1.c](Workshop/input_1.c)
- [UserInput/2.c](Workshop/input_2.c)

### Advanced Excercises

- [Advanced/1.c](Workshop/advanced_1.c)
- [Advanced/2.c](Workshop/advanced_2.c)
- [Advanced/3.c](Workshop/advanced_3.c)

#### The sieve of Eratosthenes

Implement The sieve of Eratosthenes using arrays and functions.


> The sieve of Eratosthenes is one of the most efficient ways to find all primes smaller than n when n is smaller than 10 million
> *[for more detail check [The sieve of Eratosthenes](https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes) on Wikipedia]*

### Examples



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
