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

    int i;
    for (i = 5; i < 45; i++) {
        printf("%d\n", i);
    }


    return 0;
}
