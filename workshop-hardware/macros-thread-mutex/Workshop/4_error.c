#include <stdio.h>
#include <stdlib.h>

// Define the TOTORO macro which holds the number of students in our class

int main()
{
    // If TOTORO is not defined throw a preprocessor error

    printf("Class members: %d", TOTORO);
    return 0;
}
