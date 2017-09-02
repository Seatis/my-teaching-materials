#include <stdio.h>


int main()
{
	int k = 1521;
	// tell if k is dividable by 3 or 5
	printf("k = %d\n", k);
	if (k % 3 == 0)
		printf("k is dividable by 3");

	if (k % 5 == 5)
		printf("k is dividable by 5");

	return 0;
}
