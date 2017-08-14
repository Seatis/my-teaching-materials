#include <stdio.h>

// TODO: Include needed header files
#include "another_file.h"

int main()
{
	// Set the default state of the variable
	an_example_number = 10;

	// Create variables
	char str[] = "Multiple file inclusion example project string";
	int number = 10;

	// Manipulate numbers
	string_manipulator(str);
	integer_manipulator(&number);

	// See the results
	printf("Result of string_manipulator(): %s\n", str);
	printf("Result of integer_manipulator(): %d\n", number);

	return 0;
}
