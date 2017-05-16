#include <stdio.h>

int main() {
    char char_array[] = {'a', 'b', 'c', 'd'};
    char char_array_the_same[] = "abcd";

    //TODO:
    // Print out the two arrays character-by-character
    for(int i = 0; i < 4; i++) {
        printf("%c", char_array[i]);
    }

    printf("\n");

    for(int i = 0; i < 4; i++) {
        printf("%c", char_array_the_same[i]);
    }

    //TODO:
    // What is the difference between the arrays?

    return 0;
}
