#include <stdio.h>
#define MAX_CHARS 255 // Maximum characters allowed


int main()
{
    //TODO: write a function which finds the maximum occurrence of a character in a given string.
    //return with the most frequent character
    //the number of occurrence should be an output parameter

    char str[] = "e is the most frequent element.";

    int occurrence = 0;
    int character = freq(str, &occurrence);
    printf("Maximum occurring character is %c.\n", character);
    printf("Number of occurrence: %d.", occurrence);

    return 0;
}

int freq(char *string, int *occurrence)
{
    int freq[MAX_CHARS]; // Store frequency of each character
    int ascii;

    //Initializes frequency of all characters to 0
    int i;
    for(i=0; i<MAX_CHARS; i++) {
        freq[i] = 0;
    }

    //Finds frequency of each characters
    i=0;
    while(string[i] != '\0') {
        ascii = (int)string[i];
        freq[ascii]++;
        i++;
    }

    //Finds maximum frequency
    int max = 0;
    for(i=0; i<MAX_CHARS; i++) {
        if(freq[i] > freq[max])
            max = i;
    }

    *occurrence = freq[max];

    return max;
}