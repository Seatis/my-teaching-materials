#include <stdio.h>
#include <stdint.h>

void printf_numbers(int from, int to)
{
	for (int i = from; i < to; i++)
		printf("%u,", i);
}

int main()
{
	printf_numbers(21474836, 21474846);
	return 0;
}
