#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rows = 5;
    int  i = 0;
    int j = 0;
    int k = 0;
    int space = 0;

    for(i = 1; i <= rows; ++i, k = 0)
    {
        for(space = 1; space <= rows - i; ++space)
        {
            printf("  ");
        }

        while(k != 2 * i - 1)
        {
            printf("* ");
            ++k;
        }

        printf("\n");
    }

    for(i = rows; i >= 1; --i)
    {
        for(space = 0; space < rows - i; ++space)
            printf("  ");

        for(j = i; j <= 2 * i - 1; ++j)
            printf("* ");

        for(j = 0; j < i - 1; ++j)
            printf("* ");

        printf("\n");
    }

    return 0;
}
