#include <stdio.h>

typedef struct complex
{
    float real;
    float imag;
} complex;

complex add(complex n1, complex n2);

complex sub(complex n1, complex n2);

complex mul(complex n1, complex n2);

//TODO: create 3 functions, which calculates the sum, subtraction and multiplication of a complex number.
// you can read about complex number's operations here: https://www.mathsisfun.com/numbers/complex-numbers.html

int main()
{
    complex n1, n2, sum_result, sub_result, mul_result;
    n1.real = 5;
    n1.imag = 7.2;

    n2.real = 6;
    n2.imag = 8.1;

    sum_result = add(n1, n2);
    sub_result = sub(n1, n2);
    mul_result = mul(n1, n2);
    printf("Sum = %.1f + %.1fi\n", sum_result.real, sum_result.imag);
    printf("Subtraction = %.1f + %.1fi\n", sub_result.real, sub_result.imag);
    printf("Multiplication = %.1f + %.1fi\n", mul_result.real, mul_result.imag);

    return 0;
}

complex add(complex n1, complex n2)
{
    complex res;
    res.real = n1.real + n2.real;
    res.imag = n1.imag + n2.imag;
    return res;
}

complex sub(complex n1, complex n2)
{
    complex res;
    res.real = n1.real - n2.real;
    res.imag = n1.imag - n2.imag;
    return res;
}

complex mul(complex n1, complex n2)
{
    complex res;
    res.real = (n1.real * n2.real) + (-1)*(n1.imag * n2.imag);
    res.imag = (n1.real * n2.imag) + (n1.imag * n2.real);
    return res;
}