#include <stdio.h>
#include <stdlib.h>

//TODO: make a custom type from union and nested structs. this type should be 8 bit wide.
//you should be able to assign values:
// - each bits
// - upper 3 bits and lower 5 bits
// - the whole 8-bit memory

typedef union {
    struct {
        unsigned char _8th      :1;
        unsigned char _7th      :1;
        unsigned char _6th      :1;
        unsigned char _5th      :1;
        unsigned char _4th      :1;
        unsigned char _3rd      :1;
        unsigned char _2nd      :1;
        unsigned char _1st      :1;

    };
    struct {
        unsigned char _lower5   :5;
        unsigned char _upper3   :3;
    };
    struct {
        unsigned char _whole    :8;
    };
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