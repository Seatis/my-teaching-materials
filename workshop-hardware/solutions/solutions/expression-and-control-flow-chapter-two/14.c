#include <stdio.h>

/*
modify the previous program to print the table reverse order
for example:

Fahrenheit       Celsius
300               148.9
280               137.8
260               126.7
240               115.6
...
print out at least 10 lines
*/

int main()
{
    float celsius;

	printf("Fahrenheit\tCelsius\n");

	int fahrenheit;
	for (fahrenheit = 300; fahrenheit > 100; fahrenheit -= 20) {
		celsius = (5.0/9) * (fahrenheit-32.0);
		printf("%d\t\t%.1f\n", fahrenheit, celsius);
	}

	return 0;
}

