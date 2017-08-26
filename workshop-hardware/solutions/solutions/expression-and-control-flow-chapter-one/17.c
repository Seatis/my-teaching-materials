#include <stdio.h>
#include <stdint.h>


int main()
{
	float w = 24;
	int out = 0;
	printf("%f\n", w);
	printf("%d\n", out);
	// if w is even increment out by one

	int wi = w;
	if (wi % 2 == 0)
		out += 1;

	printf("%d\n", out);

	return 0;
}
