#include <stdio.h>

void calc(int a, int b, int *p_sum, int *p_mul);

int main()
{
	int x, y;
	x = 5;
	y = 8;

	int sum, mul;

	//TODO: write a void function which calculates the sum and multiplication of x and y according to the function prototype. Use 'output parameters'. Print out these values.

	calc(x, y, &sum, &mul);
	printf("%d, %d", sum, mul);

	return 0;
}

void calc(int a, int b, int *p_sum, int *p_mul)
{
    if (p_sum != NULL)
        *p_sum = a+b;
    if (p_mul != NULL)
        *p_mul = a*b;
}