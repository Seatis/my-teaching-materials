#include <stdio.h>
#include <pthread.h>

#define WINDOWS

#ifdef WINDOWS
#include <windows.h>
#define GREEN 10
#define CYAN 11
#define WHITE 15
#endif // WINDOWS

#ifndef WINDOWS
#define GREEN "\x1B[32m"
#define CYAN "\x1B[36m"
#define WHITE "\x1B[37m"
#endif // WINDOWS

//TODO: create two functions, which prints out numbers from 0 to 10. Start 2 thread with the 2 functions. Use different colors for printf.
//hint for Linux/OSX users: https://stackoverflow.com/questions/3585846/color-text-in-terminal-applications-in-unix
//hint for Windows users:
//use this snippet before printf()
/*HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole, WHITE);*/

//try the program with and without pthread_mutex_lock() and pthread_mutex_unlock()

void green_printer();
void cyan_printer();

pthread_mutex_t lock;

int main()
{
    pthread_mutex_init(&lock, NULL);

    pthread_t green_thread;
    pthread_t cyan_thread;

    pthread_create(&green_thread, NULL, green_printer, NULL);
    pthread_create(&cyan_thread, NULL, cyan_printer, NULL);

    pthread_join(green_thread, NULL);
    pthread_join(cyan_thread, NULL);

    #ifdef WINDOWS
    HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, WHITE);
    printf("End of the program");
    #endif // WINDOWS

    #ifndef WINDOWS
    printf("%sEnd of the program", WHITE);
    #endif // WINDOWS

    return 0;
}

void green_printer()
{
    int i;
    for (i = 0; i < 10; i++) {
        pthread_mutex_lock(&lock);

        #ifdef WINDOWS
        HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, GREEN);
        printf("Green thread.\n");
        #endif // WINDOWS

        #ifndef WINDOWS
        printf("%sGreen thread.\n", GREEN);
        #endif // WINDOWS

        pthread_mutex_unlock(&lock);
    }
}

void cyan_printer()
{
    int i;
    for (i = 0; i < 10; i++) {
        pthread_mutex_lock(&lock);

        #ifdef WINDOWS
        HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, CYAN);
        printf("Cyan thread.\n");
        #endif // WINDOWS

        #ifndef WINDOWS
        printf("%sCyan thread.\n", CYAN);
        #endif // WINDOWS

        pthread_mutex_unlock(&lock);
    }
}
