#include <stdio.h>
#include <stdlib.h>

/*
TODO: Implement a function that concatenates 2 strings (dest and source).
The return value should be the concatenated strings.
*/
char *string_concat(char *dest, char *src)
{
    int i;
    for(i=0; dest[i]!='\0'; i++) {
        ;
    }

    int j;
    for(j=0; src[j]!='\0'; j++) {
        dest[i+j] = src [j];
    }
    dest[i+j]='\0';
    return dest;
}

int main()
{
    char string1[50]="hello";
    char string2[]="world";
    char *concatenated = string_concat(string1, string2);
    for(int i=0; concatenated[i]!='\0'; i++) {
        printf("%c", concatenated[i]);
    }
    return 0;
}
