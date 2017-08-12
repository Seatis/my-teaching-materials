#include <stdio.h>
#include <stdlib.h>

// TODO:
// Create a function which receives a string as parameter, and returns
// the numbers of characters in the string.
// Don't use the strlen() function!

int strlen(char *string)
{
	int i = 0;
	while (string[i] != '\0')
		i++;

	return i;
}


int main()
{
	char mystring[] = "hello";

	printf("%d", strlen(mystring));

	return 0;
}
