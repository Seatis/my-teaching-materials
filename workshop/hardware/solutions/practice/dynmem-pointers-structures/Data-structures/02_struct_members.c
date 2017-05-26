#include <stdio.h>
#include <stdint.h>

struct computer {
	float cpu_speed_GHz;
	int ram_size_GB;
	int bits;
};

int main()
{
	struct computer cmpter = {3.2, 8, 32};

	//TODO: Change the bits to 64
	cmpter.bits = 64;

	//TODO: print out the structure members
	printf("%f,%d,%d", cmpter.cpu_speed_GHz, cmpter.ram_size_GB, cmpter.bits);

	return 0;
}
