#include <stdio.h>
#include <string.h>

//TODO: write a function which returns 485 as unsigned integer value
//put your return value in an integer variable in which you should have 229
//try to figure out which type casting you should use

unsigned int casting_return_value(void);

int main()
{
	unsigned int casted_value = (unsigned char)casting_return_value();
    printf("%d", casted_value);
    return 0;
}

unsigned int casting_return_value()
{
    return 485;
}