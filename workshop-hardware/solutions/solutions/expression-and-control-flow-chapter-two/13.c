#include <stdio.h>

/*
create a program which converts the fahrenheit to celsius
the output should look like this:

Fahrenheit       Celsius
  0               -17.8
 20                -6.7
 40                 4.4
 60                15.6
...
print out at least 10 lines
*/

int main()
{
	float celsius;

	printf("Fahrenheit\tCelsius\n");

	int fahrenheit;
	for (fahrenheit = 0; fahrenheit < 200; fahrenheit += 20) {
		celsius = (5.0/9) * (fahrenheit-32.0);
		printf("%d\t\t%.1f\n", fahrenheit, celsius);
	}

	return 0;
}

