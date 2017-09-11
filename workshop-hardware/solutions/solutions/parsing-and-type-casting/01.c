#include <stdio.h>
#include <conio.h>

main()
{
	int  i = 2;
	float f = 13.5, result;

	//TODO: print out the f/i quotient

	//QUESTION: do you need explicit conversion?
	//ANSWER: no

	result = f/i;
	printf("Quotient of %f/%d = %f\n", f, i, result);

	return 0;
}
