#include <stdio.h>
#include <stdint.h>

//ws-16

int main()
{
	uint16_t v = 426;
	printf("%d\n", v);
	// print 'Yeah!' if dividable by 4 but print 'End of program' after regardless

	if (v % 4 == 0)
		printf("Yeah!\n");

	printf("End of program");
	return 0;
}
