#include <stdio.h>


int main()
{
	int j1 = 10;
	int j2 = 3;
	// tell if j1 is higher than j2 squared and smaller than j2 cubed

	printf("j1 = %d\n", j1);
	printf("j2 = %d\n", j2);

	if ((j1 > j2 * 2) && (j1 < j2 * j2 * j2))
		printf("j1 is higher than j2 squared and smaller than j2 cubed");

	return 0;
}
