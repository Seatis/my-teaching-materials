#include <stdio.h>

int main()
{
	int a = 1;
	while (a <= 100) {
        switch (a % 15) {
        case 0:
            printf("Fizzbuzz\n");
            break;
        case 5:
        case 10:
            printf("Buzz\n");
            break;
        case 3:
        case 6:
        case 9:
        case 12:
            printf("Fizz\n");
            break;
        default:
            printf("%d\n", a);
            break;
        }
		a++;
	}
	return 0;
}