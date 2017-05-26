#include <stdio.h>

//ws-04

/* Write a non void function which has a paramters (let's say for example x).
The funtion than returns the "xth" fibonaci number.
What the hack is a fibonacci number? Search it on wikipedia!
*/

int fib(int);

int main()
{

	int xth_fib_num = fib(6);
	printf("%d", xth_fib_num);

	return 0;
}

int fib(int n)
{
	int fibo_n_minus_2 = 0;
	int fibo_n_minus_1 = 1;
	int fibo_n = 0;

	if (n < 1) {
		return -1;
	} else if (n == 1) {
		return 0;
	} else if (n == 2) {
		return 1;
	} else {
		for (int i = 0; i < (n - 2); i++) {
			fibo_n = fibo_n_minus_1 + fibo_n_minus_2;
			fibo_n_minus_2 = fibo_n_minus_1;
			fibo_n_minus_1 = fibo_n;
		}
		return fibo_n;
	}
}

/* Soltuion with recursion, advanced!
int fib(int x) {
    if (x <= 1)
        return x;
    return fib(x-1) + fib(x-2);
}
*/
