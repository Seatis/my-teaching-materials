#include <stdio.h>

//ws-03

/* Write a non void function which returns the value of PI, so the following number:
3.1415926535897932384626433832795028841971693993
Try it out in the main function by printing out the result of the pi generator function!
*/
double pi_generator(void);

int main()
{

	double result = pi_generator();
	printf("%f", result);
	return 0;
}

double pi_generator()
{
	return 3.1415926535897932384626433832795028841971693993;
}
