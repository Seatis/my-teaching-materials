#include <stdio.h>

int first_word(char *string, char *first);

int main()
{
    //TODO: write a function, which extracts the first word of a given string.
    //return with the word's length

    char str[] = "Extracting the first word.";
    char first[50];

    int size_of_first_word = first_word(str, first);

    int i;
    for (i = 0; i<size_of_first_word; i++) {
        printf("%c", first[i]);
    }

    return 0;
}

int first_word(char *string, char *first)
{
    int pos = 0;

    int i;
    for (i = 0; string[i]!=' '; i++) {
        pos++;
    }

    for (i = 0; i < pos; i++) {
        first[i] = string[i];
    }
    return pos;
}