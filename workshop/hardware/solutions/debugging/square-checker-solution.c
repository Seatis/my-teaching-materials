#include <stdio.h>
#include <math.h>

// This program should work correctly with the following input: 20, 400

int main()
{
	float number, result;
	printf("Please enter a number: ");
	fflush(stdin);
	scanf("%.2f", &number);

	printf("Please enter the square of that number: ");
	fflush(stdin);
	scanf("%.2f", &result);

	if (result - 1 <= pow(number, 2) <= result+1)
		printf(":)\n");
	else
		printf(":(\n");

	return 0;
}
