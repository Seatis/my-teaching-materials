#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void thread_function();

int shared_data = 0;

//TODO: run this program and try to figure out what's happening
//what happens if you comment out usleep(1000)

pthread_mutex_t lock;
pthread_t my_thread;

int main(void)
{
    pthread_mutex_init(&lock, NULL);

    pthread_create(&my_thread, NULL, thread_function, NULL);

    int i;
    for (i = 0; i < 10; ++i) {
        usleep(1000);
        pthread_mutex_lock(&lock);
        printf("Shared intger's value = %d\n", shared_data);
        pthread_mutex_unlock(&lock);
    }
    printf("\n");

    pthread_join(my_thread, NULL);

    pthread_mutexattr_destroy(&lock);

    return 0;
}

void thread_function()
{
    int i;
    for (i = 0; i < 20000; ++i) {
        pthread_mutex_lock(&lock);
        shared_data = i;
        pthread_mutex_unlock(&lock);
    }
}