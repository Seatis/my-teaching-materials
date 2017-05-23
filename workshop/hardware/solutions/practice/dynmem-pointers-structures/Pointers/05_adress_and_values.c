#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Print out the addresses with and without pointer
print out the values with and without pointer

 */


int main()
{

    int number = 2017;
    float Pi = 3.14;
    char letter = 't';

    int *ptr1 = &number;
    float *ptr2 = &Pi;
    char *ptr3 = &letter;

    printf("\n\tAddresses without pointer\n");
    printf("\t\tthe address of number: %p\n", &number);
    printf("\t\tthe address of Pi: %p\n", &Pi);
    printf("\t\tthe address of letter: %p\n", &letter);

    printf("\n\tAddresses with pointer\n");
    printf("\t\tthe address of number: %p\n", ptr1);
    printf("\t\tthe address of Pi: %p\n", ptr2);
    printf("\t\tthe address of letter: %p\n", ptr3);

    printf("\n\tValue without pointer\n");
    printf("\t\tthe value of number: %d\n", number);
    printf("\t\tthe value of Pi: %f\n", Pi);
    printf("\t\tthe value of letter: %c\n", letter);

    printf("\n\tValue with pointers\n");
    printf("\t\tthe value of number: %d\n", *ptr1);
    printf("\t\tthe value of float: %f\n", *ptr2);
    printf("\t\tthe value of character: %c\n", *ptr3);

    return 0;
}