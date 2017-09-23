#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

//TODO: write 2 functions which prints out numbers from 0 to 10
//In the first function use random generated 250-500 ms delay.
//In the second function use random generated 125-250 ms delay.
//use delay with calling usleep() function.
//in the main() function create 2 threads with the 2 functions and after they're terminated, join to the main thread and print out: "Both threads are ready."

//hint: random number within a range: int r = (rand() % (max + 1 - min)) + min

void printer_1();
void printer_2();

int main()
{
    srand(time(NULL));

    return 0;
}
