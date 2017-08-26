#include <stdio.h>
#include <stdlib.h>

/*
find the greatest common divisor of the two given variables
use Euclid's algorithm, if you don't know it look it up on the internet
*/

int main()
{
    int x = 32;
    int y = 20;
    int temp = 0;

    while (x > 0) {
        if (x < y) {
            temp = x;
            x = y;
            y = temp;
        }
        x = x - y;
    }

    printf("%d\n", y);

    return 0;
}
