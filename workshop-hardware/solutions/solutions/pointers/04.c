#include <stdio.h>

int my_strlen(char *string);

int main()
{
	char my_string[50] = "Hello world!";

	//TODO: implement your own strlen function.

	int length = my_strlen(my_string);

	printf("%d", length);

	return 0;
}

int my_strlen(char *string)
{
	int i;
	for (i = 0; string[i] != '\0'; ++i)
		;
	return i;
}
