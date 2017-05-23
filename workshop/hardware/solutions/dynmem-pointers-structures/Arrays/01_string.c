#include <stdio.h>

int main()
{
    char my_name_array[] = "My Name";

	//TODO:
    // Print out the array character-by-character
	int n = sizeof(my_name_array)/sizeof(my_name_array[0]);
	for(int i=0; i<n; i++) {
		printf("%c", my_name_array[i]);
	}

    return 0;
}