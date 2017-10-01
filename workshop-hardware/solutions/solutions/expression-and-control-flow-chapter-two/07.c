#include <stdio.h>
#include <stdlib.h>

/*
create a simple program which checks if the num is odd or even
*/

int main()
{
    int num;
    num = 13;

	switch (num%2 == 0) {
	case 1:
		printf("Even!");
		break;
	case !1:
		printf("Odd!");
		break;
	}

    return 0;
}