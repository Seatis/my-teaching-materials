#include <stdio.h>

void reverse_name(char *name, char *reversed_name);

int main(void) {
	char name[] = "Gipsz Jakab";

    char reversed[50];
    
    //write a function which reverse a name's last name and first name. Use a void function. Put your 'return' value in the second parameter.

    reverse_name(name, reversed);

    printf("The reversed name: %s", reversed);
}

void reverse_name(char *name, char *reversed_name)
{
    int i;

    for (i = 0; name[i] != ' '; ++i)            //finding the position of space
        ;
    int space = i;

    int dest = 0;
    for (i = space + 1; name[i] != '\0'; ++i)   //first name
        reversed_name[dest++] = name[i];
    reversed_name[dest++] = ' ';
    for (i = 0; i != space; ++i)               //last name
        reversed_name[dest++] = name[i];
    reversed_name[dest++] = '\0';
}