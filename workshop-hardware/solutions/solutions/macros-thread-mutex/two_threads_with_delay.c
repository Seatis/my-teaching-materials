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

    pthread_t thread_1;
    pthread_t thread_2;

    pthread_create(&thread_1, NULL, printer_1, NULL);
    pthread_create(&thread_2, NULL, printer_2, NULL);

    pthread_join(thread_1, NULL);
    pthread_join(thread_2, NULL);

    printf("Both threads are ready");


    return 0;
}

void printer_1()
{
    int i;
    for (i = 0; i < 10; i++) {
        printf("Thread 1: %d\n", i);
        usleep(1000 * (rand() % (250 + 1 - 125) + 125));
    }
}

void printer_2()
{
    int i;
    for (i = 0; i < 10; i++) {
        printf("Thread 2: %d\n", i);
        usleep(1000 * (rand() % (500 + 1 - 250) + 250));
    }
}