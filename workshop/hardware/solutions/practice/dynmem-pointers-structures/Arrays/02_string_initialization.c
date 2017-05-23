#include <stdio.h>

int main()
{
    char char_array[] = {'a', 'b', 'c', 'd'};
    char char_array_the_same[] = "abcd";

	//TODO:
    // Print out the two arrays character-by-character

	int n = sizeof(char_array)/sizeof(char_array[0]);
	for(int i=0; i<n; i++) {
		printf("%c", char_array[i]);
	}

	printf("\n");

	n = sizeof(char_array_the_same)/sizeof(char_array_the_same[0]);
	for(int i=0; i<n; i++) {
		printf("%c", char_array_the_same[i]);
	}
	//TODO:
    // What is the difference between the arrays?

    return 0;
}