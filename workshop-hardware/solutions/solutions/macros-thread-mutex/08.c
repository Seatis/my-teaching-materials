#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>

void thread_function();

int shared = 0;

//TODO: Implement the former exercise, but this time don't use mutex. Use semaphore instead.

sem_t binary_sem;
pthread_t my_thread;

int main()
{
    sem_init(&binary_sem, 0, 1);

    pthread_create(&my_thread, NULL, thread_function, NULL);


    int i;
    for (i = 0; i < 10; ++i) {
        usleep(1000);
        sem_wait(&binary_sem);
        printf("Shared intger's value = %d\n", shared);
        sem_post(&binary_sem);
    }
    printf("\n");


    pthread_join(my_thread, NULL);

    sem_destroy(&binary_sem);

    return 0;
}

void thread_function()
{
    int i;
    for (i = 0; i < 1024*1024; ++i) {
        sem_wait(&binary_sem);
        shared = i;
        sem_post(&binary_sem);
    }
}