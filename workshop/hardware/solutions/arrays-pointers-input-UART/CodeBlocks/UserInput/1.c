#include <stdio.h>

int main()
{
	char buffer[255];   // Buffer variable for user input

	//TODO:
	// Get the user's name with scanf
	printf("Your name is: ");
	scanf("%s", buffer);

	//TODO:
	// Print it out with printf
	printf("You are: %s\n", buffer);

	return 0;
}
