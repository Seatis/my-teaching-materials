#include <stdio.h>
#include <stdint.h>

//ws-14

int main()
{
	uint8_t number = 254;
	uint8_t result;

	result = number + 23;
	// Check the result with printf

	printf("%d\n", result);

	// What happened?!
	//overflow

	// Try again with different datatype
	uint16_t result_16 = number + 23;
	// Check the result with print

	printf("%d\n", result_16);

	// What happened and why?
	//fits in, no overflow

	//----------------------------------------
	int8_t number_negative = number;
	// Check the result with printf

	printf("%d\n", number_negative);

	// What happened and why?
	//negative overflow

	return 0;
}
