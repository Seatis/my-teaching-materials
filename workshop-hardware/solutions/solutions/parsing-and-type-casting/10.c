#include <stdio.h>
#include <string.h>

int main()
{
    printf("Type in a sentence:\n\n");
    char string[256];
    gets(string);

    //TODO: write a c program which, splits a string to words by space
	//solve the problem with the proper string.h function

	char *found;

    found = strtok(string," ");
    if(found==NULL) {
        printf("%s\n",string);
        puts("No separators found");
        return(1);
    }
    while(found) {
        printf("%s\n",found);
        found = strtok(NULL," ");
    }

    return(0);
}