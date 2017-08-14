#include <stdio.h>
#include <stdint.h>


int main()
{
	uint8_t u = 123;
	printf("%d\n", u);
	// print 'Hooray!' if the number is bigger than 100

	if (u > 100)
		printf("Hooray");

	return 0;
}
