#include <stdio.h>

typedef struct complex
{
    float real;
    float imag;
} complex;


//TODO: create 3 functions, which calculates the sum, subtraction and multiplication of a complex number.
// you can read about complex number's operations here: https://www.mathsisfun.com/numbers/complex-numbers.html

int main()
{
    complex n1, n2;
    n1.real = 5;
    n1.imag = 7.2;

    n2.real = 6;
    n2.imag = 8.1;


    return 0;
}