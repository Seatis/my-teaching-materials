#include <stdio.h>
#include <string.h>

int main ()
{
	char str[] = "This is a sample string";
    char *first, *last;
	
	//TODO: write a program which prints out the distance between the first and last occurance of character 's'
	
    first=strchr(str,'s');
    last=strrchr(str,'s');
    printf ("Distance is: %d\n", last-first);
    return 0;
}