#include <stdio.h>

//ws-01

/* Write a void function which can print the following text on the screen:
------------
-- TOTORO --
------------
- GREENFOX -
------------
Name this function as "totoro_logo_printer" and call it from the main function!*/

void totoro_logo_printer(void);

int main()
{
	totoro_logo_printer();
	return 0;
}

void totoro_logo_printer()
{
	printf("------------\n");
	printf("-- TOTORO --\n");
	printf("------------\n");
	printf("- GREENFOX -\n");
	printf("------------\n");
}
