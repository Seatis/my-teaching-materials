#include <stdio.h>
#include <string.h>

/*
Create a program which ask for a name and an age.
From the age it tells the user when he or she will be 100 years old.
You should only take care of the years (don't bother with the months or days).
*/

int main()
{

	char yourname[100];
	int yourage;
	int hundredyearsold;

	printf("Whats your name?\t");
	scanf("%s", yourname);
	printf("How old are you?\t");
	scanf("%d", &yourage);
	hundredyearsold = 100 - yourage;
	printf("You will be 100 years old in %d years.\n", hundredyearsold);

	return 0;
}
