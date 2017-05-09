#include <stdio.h>

//ws-04

/* Write a non void function which has a paramters (let's say for example x).
The funtion than returns the "xth" fibonaci number.
What the hack is a fibonacci number? Search it on wikipedia!
*/

int fib(int);

int main() {

    int xth_fib_num = fib(6);
    printf("%d", xth_fib_num);

    return 0;
}

int fib(int x) {
    if (x <= 1)
        return x;
    return fib(x-1) + fib(x-2);
}
