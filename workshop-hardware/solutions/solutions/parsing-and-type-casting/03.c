#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int a=54325;
    char buffer[20];

    //TODO: make an integer to string conversion with itoa(), first in binary, then decimal format
    // Store the string in buffer

    itoa(a,buffer,10);
    printf("Decimal value = %s\n", buffer);

    itoa(a,buffer,2);
    printf("Binary value = %s\n", buffer);

    return 0;
}