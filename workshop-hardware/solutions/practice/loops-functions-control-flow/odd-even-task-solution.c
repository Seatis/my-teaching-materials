#include <stdio.h>
#include <string.h>

/*
Write a program that reads a number form the standard input,
than prints "Odd" if the number is odd, or "Even" it it is even.
*/

int main()
{

	int number;

	printf("please enter an integer: ");
	scanf("%d", &number);

	if (number % 2 == 1) {
		printf("Your number %d is an odd number", number);
	} else {
		printf("Your number %d is an even number", number);
	}

	return 0;
}
