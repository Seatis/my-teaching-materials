#include <stdio.h>
#include <stdint.h>

struct Computer {
    float cpu_speed_GHz;
    int ram_size_GB;
    int bits;
};

int main() {
    struct Computer computer = {3.2, 8, 32};

    //TODO: Change the bits to 64
	computer.bits = 64;
	
    //TODO: print out the structure members
	printf("%f,%d,%d", computer.cpu_speed_GHz, computer.ram_size_GB, computer.bits);

    return 0;
}