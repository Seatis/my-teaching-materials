#include <stdio.h>
#include <string.h>

/*
Write a program which receives a number between 0-10 from the user.
It prints out the english word for that number on the screen.
For example if the user enters 8, the program prints out "Eight".
Use switch-case in this task!
Handle the invalid user input!
*/

int main()
{

	int print_number = 5;

	switch (print_number) {
	case 0:
		printf("Zero");
		break;
	case 1:
		printf("One");
		break;
	case 2:
		printf("Two");
		break;
	case 3:
		printf("Three");
		break;
	case 4:
		printf("Four");
		break;
	case 5:
		printf("Five");
		break;
	case 6:
		printf("Six");
		break;
	case 7:
		printf("Seven");
		break;
	case 8:
		printf("Eight");
		break;
	case 9:
		printf("Nine");
		break;
	case 10:
		printf("Ten");
		break;
	default:
		break;
	}

	return 0;
}