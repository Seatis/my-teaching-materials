#include <stdio.h>
#include <stdlib.h>

typedef union {
    //TODO: make a custom type from union and nested structs. this type should be 8 bit wide.
	//you should be able to assign values:
	// - each bits
	// - upper 3 bits and lower 5 bits
	// - the whole 8-bit memory
} my_memory;

int main()
{
    my_memory mem;
    mem._whole = 0b11100010;

    printf("The whole memory: %d\n", mem._whole);
    printf("The upper 3 bits: %d\n", mem._upper3);
    printf("The lower 5 bits: %d\n", mem._lower5);
    printf("The first bit: %d", mem._1st);

    return 0;
}