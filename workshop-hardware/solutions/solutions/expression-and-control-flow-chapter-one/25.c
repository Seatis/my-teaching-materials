#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 123;
    int y = 44;
    int z = 72;
    int result = 0;
    int max = 0;
    result=(x+y+abs(x-y))/2;
    max=(result+z+abs(result-z))/2;
    printf("\nMaximum value of three integers: %d", max);
	printf("\n");
    return 0;
}
