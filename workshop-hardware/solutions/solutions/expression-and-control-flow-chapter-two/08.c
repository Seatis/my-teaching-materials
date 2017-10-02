#include <stdio.h>
#include <stdlib.h>

/*
create a program which generates numbers from 0 to 100
for each number write if the number is odd or even (don't print out the numbers)
*/

int main()
{
	int i;
	for (i = 0; i < 100; i++) {
        switch (i%2==0) {
        case 1:
            printf("Even!\n");
            break;
        case !1:
            printf("Odd!\n");
            break;
        }
	}
    return 0;
}
