#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Add two numbers using pointers
 */


int main()
{

	int a  = 20;
	int b = 17;

	int *ptra = &a;
	int *ptrb = &b;

	printf("a+b=%d", *ptra + *ptrb);

	return 0;
}