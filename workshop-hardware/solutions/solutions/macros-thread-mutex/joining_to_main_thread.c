#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//TODO: create a sum() function which adds up numbers from 0 to 30, and prints out the sum.
//from main() create a thread with sum() function
//then from main() function print out numbers from 5 to 45
//experiment with joining to the main thread in different positions

void sum();

int main()
{
    pthread_t summing_thread;
    pthread_create(&summing_thread, NULL, sum, NULL);


    int i;
    for (i = 5; i < 45; i++) {
        printf("%d\n", i);
    }

    pthread_join(summing_thread, NULL);


    return 0;
}

void sum()
{
    int sum = 0;
    int i;
    for (i = 0; i < 30; i++) {
        sum += i;
    }
    printf("Sum of the first 10 numbers from 0 is %d\n", sum);
}