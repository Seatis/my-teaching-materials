#include <stdio.h>
#include <string.h>

// Write a program that asks for two numbers
// The first number represents the number of girls that comes to a party, the
// second the boys
// It should print: The party is excellent!
// If the the number of girls and boys are equal and there are more people coming than 20

// It should print: Quite cool party!
// If there are more than 20 people coming but the girl - boy ratio is not 1-1

// It should print: Average party...
// If there are less people coming than 20
// It should print: Sausage party
// If no girls are coming, regardless the count of the people

int main()
{

	int boys_number = 0;
	int girls_number = 0;
	printf("Hello first please enter the number of boys: ");
	scanf("%d", &boys_number);
	printf("\nNow please enter the number of girls: ");
	scanf("%d", &girls_number);

	if (boys_number + girls_number > 20) {
		if (boys_number == girls_number)
			printf("Excellent party!");
		else if (girls_number < 1)
			printf("Sasuge party.");
		else
			printf("Quite cool party.");
	}
	if (boys_number + girls_number < 20)
		printf("Average party...");

	return 0;
}
