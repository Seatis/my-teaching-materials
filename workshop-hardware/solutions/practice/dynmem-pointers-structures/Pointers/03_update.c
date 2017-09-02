#include <stdio.h>

int main()
{
	int number = 1234;
	int *number_pointer = &number;
	//TODO:
	// update the value of number variable to 42 using the "number_pointer"
	*number_pointer = 42;
	printf("%d", number);


	return 0;
}