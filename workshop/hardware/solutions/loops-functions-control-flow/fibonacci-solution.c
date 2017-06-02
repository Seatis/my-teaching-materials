#include <stdio.h>
#include <string.h>

/* Write a function which is called "get_fibonacci_number". It returns the "N"th
 * Fibonacci number, where "N" is received as a paramter.
 * For example:
 *  - get_fibonacci_number(1) returns 0
 *  - get_fibonacci_number(2) returns 1
 *  - get_fibonacci_number(3) returns 1
 *  - get_fibonacci_number(4) returns 2
 *  - get_fibonacci_number(5) returns 3
 *  - get_fibonacci_number(6) returns 5
 *
 *  If the function gets invalid parameter it returns -1.
 */

/*
Using that function create a program, which gets a number from the user, and
prints out the "N"th Fibonacci number, where "N" is the user given number.
Alert the user if he/she entered invalid value.
*/

int fibonacci_number(int x);

int main()
{
	int x = 8;
	if (x > 0)
		printf("%d\n", fibonacci_number(x));
	else if (x < 0)
		printf("-1");
	return 0;
}

int fibonacci_number(int x)
{
	if (x < 1)
		return 0;

	int a = 0;
	int b = 1;
	for (int i = 0; i < x; i++) {
		int temp = a;
		a = b;
		b = b + temp;
	}

	return a;
}
