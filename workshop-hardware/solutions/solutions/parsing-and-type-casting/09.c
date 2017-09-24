#include <stdio.h>
#include <stdlib.h>

void binary_adder (char *bin_op_1, char *bin_op_2);

//TODO: write a program which asks for two binary numbers.
//write a function, which prints out the sum of the 2 binary numbers.

int main()
{

    char a[20];
    char b[20];
    printf("Give me a binary number: ");
    scanf("%s", &a);
    printf("Give me another binary number: ");
    scanf("%s", &b);

    binary_adder(a, b);

    return(0);
}

void binary_adder (char *bin_op_1, char *bin_op_2)
{
    long num_1 = strtol(bin_op_1, NULL, 2);
    long num_2 = strtol(bin_op_2, NULL, 2);

    char buffer[20];
    long res = num_1 + num_2;
    itoa(res, buffer, 2);
    printf("%s", buffer);
}