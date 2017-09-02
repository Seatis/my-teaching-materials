#include <stdio.h>
#include <stdint.h>

void printf_numbers(int from, int to)
{
	for (int i = from; i < to; i++)
		printf("%d,", i);
}

int main()
{
	printf_numbers(2147483600, 2147484600);
	return 0;
}
