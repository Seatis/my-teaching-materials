#include <stdio.h>
#include <stdlib.h>

/*
swap the values of the to number
print out first the original values then print out the swaped values
but this time use bitwise operators only
*/

int main() {
    int x = 53;
    int y = 123;

    printf("%d\n", x);
    printf("%d\n", y);

    x = x ^ y;
    y = x ^ y;
    x = x ^ y;

    printf("Numbers after Exchange : \n");
    printf("%d\n", x);
    printf("%d\n", y);

    return(0);
}
