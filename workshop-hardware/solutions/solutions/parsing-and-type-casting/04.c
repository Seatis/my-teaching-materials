#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	float val;
	char str[5];
	strcpy(str, "3.14");

	//TODO: print out the value of pi, first as a string, then a float value.

	val = atof(str);
	printf("String value = %s\n", str);
	printf("Float value = %f\n", val);

	return(0);
}
