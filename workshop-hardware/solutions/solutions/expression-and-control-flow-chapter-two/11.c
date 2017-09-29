#include <stdio.h>

/*
store your age, height(for example: 1.85 in meters) as different variables
print them out, using only one printf function
use correct variables for each
*/

int main()
{
	float height = 1.83;
	unsigned char age = 22;

	printf("My age is: %d.\n", age);
	printf("My age is: %.2f.", height);

	return 0;
}
