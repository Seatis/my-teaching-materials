#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void  palindrome(void);

int main()
{
	palindrome();
	return 0;
}

void  palindrome()
{
	char input[100] = {};
	printf("please enter a world: \n");
	scanf("%s", input);
	printf("%s", input);
	int *number_pointer;
	int i;
	for (i = 0; i < strlen(input); i++) {
		number_pointer = &input[strlen(input) - i - 1];
		printf("%c", *number_pointer);
	}
}