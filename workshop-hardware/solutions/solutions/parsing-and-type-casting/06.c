#include <stdio.h>
#include <stdlib.h>

void transform (char str[], int original_base, int new_base);

//TODO: write a program, which transforms a number from a number system to another.
//use the stdlib.h functions, and take care of error handling (see the reference)
//the transform() function should print out the result.

int main()
{
    char str[20];
    int original_base;
    int new_base;
    printf("Give me a number to transform it in an other system: ");
    scanf("%s", str);
    printf("Give me the original base: ");
    scanf("%d", &original_base);
    printf("Give me the number of the new base: ");
    scanf("%d", &new_base);

    transform(str, original_base, new_base);
    return(0);
}

void transform (char str[], int original_base, int new_base)
{
    char error = 1;
    if (original_base >= 36 || original_base <=2) {
        error = 1;
    }
    if (new_base < 0) {
        error = 2;
    }

    if (error == 1) {
        printf("The original base can be between 2 and 36.\n");
    } else if (error == 2) {
        printf("The new base should be a positive number.\n");
    }
    else {
        long num = strtol(str, NULL, original_base);
        char result[20];
        itoa(num, result, new_base);
        printf("The number in %d base is: %s.", new_base, result);
    }
}