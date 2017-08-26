#include <stdio.h>
#include <math.h>

// This program should work correctly with the following input: 20, 400

#define FLOAT_COMPARE_CONST     0.001

int main()
{
	float number, result;
	printf("Please enter a number: ");
	fflush(stdin);
	scanf("%f", &number);

	printf("Please enter the square of that number: ");
	fflush(stdin);
	scanf("%f", &result);

	// Never compare two float or double variable with ==
	// Instead check if the variable is in a range
	float result_calc = pow(number, 2);
	float range_min = result_calc * (1 - FLOAT_COMPARE_CONST);
	float range_max = result_calc * (1 + FLOAT_COMPARE_CONST);

	if (result > range_min && result < range_max)
		printf(":)\n");
	else
		printf(":(\n");
	return 0;
}
