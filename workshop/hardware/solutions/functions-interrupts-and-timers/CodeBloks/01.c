#include <stdio.h>

//ws-01

/* Write a void function which can print the following text on the screen:
------------
-- TOTORO --
------------
- GREENFOX -
------------
Name this function as "TotoroLogoPrinter" and call it from the main function!*/

void TotoroLogoPrinter(void);

int main(){
	TotoroLogoPrinter();
    return 0;
}

void TotoroLogoPrinter()
{
	printf("------------\n");
	printf("-- TOTORO --\n");
	printf("------------\n");
	printf("- GREENFOX -\n");
	printf("------------\n");
}
