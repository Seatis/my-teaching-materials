#include <stdio.h>
#include <string.h>

//make it work

void memory_address(int x);
void current_value(int x);
void double_value(int x);

int main()
{
	int number = 2017;
	char choice = '1';

	printf("\t**********\n\tHello User\n\t**********\nYou have an integer named 'number'\n");
	printf("- for it's memory address please press 1\n");
	printf("- for it's current value please press 2\n");
	printf("- to double it's value please press 3\n");

	while ('1' < choice < '3') {
		printf("Please enter your choice: ");
		choice = getchar();
		getchar();

		if (choice == '0')
			break;
		else if (choice == '1')
			memory_address(number);
		else if (choice == '2')
			current_value(number);
		else if (choice == '3')
			double_value(number);
		else
			printf("Please choose from the given numbers\n");
	}

	return 0;
}

void memory_address(int x)
{

	printf("The asked memory address is: %x\n", &x);

}

void current_value(int x)
{

	printf("The value of your number is: %d\n", x);

}

void double_value(int x)
{

	x = x * 2;
	printf("The double of your number is: %d\n", x);

}
