#include <stdio.h>
#include <stdint.h>

struct bitfield {
	uint8_t boolean_value_1: 1;
	uint8_t boolean_value_2: 1;
	uint8_t boolean_value_3: 1;
	uint8_t boolean_value_4: 1;
	uint8_t boolean_value_5: 1;
	uint8_t boolean_value_6: 1;
	uint8_t boolean_value_7: 1;
	uint8_t boolean_value_8: 1;
};

struct not_bitfield {
	uint8_t boolean_value_1;
	uint8_t boolean_value_2;
	uint8_t boolean_value_3;
	uint8_t boolean_value_4;
	uint8_t boolean_value_5;
	uint8_t boolean_value_6;
	uint8_t boolean_value_7;
	uint8_t boolean_value_8;
};


int main()
{
	struct bitfield btf = {0, 0, 0, 0, 0, 0, 0, 0};
	struct not_bitfield nbtf = {0, 0, 0, 0, 0, 0, 0, 0};
	// TODO:
	// Print out the size of both structs (use sizeof() function)
	printf("Size of bitfield: %d\n", sizeof (btf));
	printf("Size of not_bitfield: %d", sizeof (nbtf));

	return 0;
}
