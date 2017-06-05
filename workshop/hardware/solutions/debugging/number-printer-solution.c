#include <stdio.h>
#include <stdint.h>

void printf_numbers(unsigned int from, unsigned int to)
{
	for (unsigned int i = from; i < to; i++)
		printf("%u,", i);
}

int main()
{
	printf_numbers(2147483600, 2147484600);
	return 0;
}
