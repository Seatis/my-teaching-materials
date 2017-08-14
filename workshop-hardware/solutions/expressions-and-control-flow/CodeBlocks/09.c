#include <stdio.h>

//ws-09

int main()
{
	int i = 53625;
	// tell if it has 11 as a divisor
	printf("%i\n", i);

	if (i % 11 == 0)
		printf("11 is a divisor");
	else
		printf("11 is not a divisor");

	return 0;
}
