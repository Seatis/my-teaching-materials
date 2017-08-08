# Functions in C programming

## Objectives

## Materials & Resources
### Environment
- Make sure that Code::Blocks is installed on your machine

### Training
#### Functions in C
Watch and read the following materials on C functions:

| Material | Time |
|:---------|-----:|
| [Introduction to Functions](https://www.youtube.com/watch?v=lv5IDF7dmBk) | 8:22 |
| [Local, Global Variable Scopes](https://www.youtube.com/watch?v=sAj_Jrqrg5g) | 3:36 |
| [Local, Global Variable Scopes](http://www.w3schools.in/c-tutorial/variable-scope/) | - |
| [Function Parameters](https://www.youtube.com/watch?v=_oyuKw3vBf8) | 6:19 |
| [Return Values](https://www.youtube.com/watch?v=ye2tvFir65g) | 7:13 |
| [Summary of Functions](http://www.w3schools.in/c-tutorial/functions/) | - |
|[Recursion](https://www.youtube.com/watch?v=KEEKn7Me-ms&t=76s)|5:40|
|[Memoization](https://en.wikipedia.org/wiki/Memoization)|-|
|[Header file](https://www.youtube.com/watch?v=1EeetMPACMI)|9:51|
|[C Header file](https://www.tutorialspoint.com/cprogramming/c_header_files.htm)|-|

#### Fibonacci sequence with recursion

> What is a Fibonacci sequence? In mathematics a number is a Fibonacci number if it is equal to the sum of the two number before it. This is a sequence it's first element is 1. the second is 1. so the thrid element must be 2. Here is the beginning of the Fibonacci sequence:
`1, 1, 2, 3, 5, 8, 13`
> *[for more detail check [Fibonacci Number](https://en.wikipedia.org/wiki/Fibonacci_number) on Wikipedia]*

We can say a number is a Fibonacci number if `Fn = Fn-1 + Fn-2` and `F1 = 1` and `F2 = 1`

Let's have a look at this implemention of the Fibonacci sequence:

```c_cpp
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("%d", fibonacci(12));
    return 0;
}

int fibonacci(int number)
{
    if (number == 1)
        return 1;
    else if (number == 2)
        return 1;
    else
        return fibonacci(number - 1) + fibonacci(number - 2);
}
```

In this code we have created our own function which returns the asked Fibonacci number. As you can see it has one parameter (an integer) which stands for the number of element we want to access. Because we have declared this integer in our function parameter we can call that function with an integer written in it.

For the first two element we made two simple statements, we don't need to count those (also with this method we can't), simply we tell our code that is the parameter is one or two it should return one! There is one more interesting thing, which is we can have multiple return values in one function. That will be useful for *error handling*.

## Material Review
- Functions
    - syntax
    - what do we use it
    - why it is good
    - how does it look like
    - parameters
        - syntax
        - why it is good
    - return values
        - syntax
        - why it is good
        - multiple return statements in functions
            - recursion
            - memoization
    - variable scopes
        - global
            - it can be evil
        - local
    - standard library functions
        - printf
        - sizeof
            - play with it with different types
            - char, short, int, long, longlong
            - uint8_t, int8_t, float, double

- Indcluses
    - syntax
    - why do we use it
    why it is good



## Workshop
Today we are going to learn how to use functions in C language.

### Creating .h and .c files

- [includes](MultipleFiles)

### Functions

 - [sum.c](Workshop/sum.c)
 - [printer.c](Workshop/printer.c)
 - [greet.c](Workshop/greet.c)
 - [factorio.c](Workshop/factorio.c)
 - [double.c](Workshop/double.c)


### Advanced exercises

 - [memoization.c](Workshop/memoization.c)
 - [gcd.c](Workshop/gcd.c)
 - [factorial.c](Workshop/factorial.c)
 - [power.c](Workshop/power.c)

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
