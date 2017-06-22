#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <winsock2.h>


int main()
{
    printf("\t\tPing google.com!\n");
    printf("\t\tPress enter to start!\n\n");
    char c = 0;
    while (c != '\n')
        c = getchar();

    if (system("ping www.google.com") == 0)
        printf("\n\n\t\tThe ping succeeded!\n");

    return 0;
}
