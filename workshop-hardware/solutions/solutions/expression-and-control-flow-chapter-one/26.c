#include <stdio.h>
#include <stdlib.h>

/*
swap the values of the to number
print out first the original values then print out the swaped values
*/

int main()
{
    int x = 32;
    int y = 20;
    int temp = 0;

    printf("%d\n", x);
    printf("%d\n", y);

    temp = x;
    x = y;
    y = temp;

    printf("%d\n", x);
    printf("%d\n", y);

}
