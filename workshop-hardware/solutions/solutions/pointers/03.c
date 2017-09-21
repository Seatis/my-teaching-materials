#include <stdio.h>

void print_array(int *array, int size);

int main()
{
	int a[] = {6, 8, 48, 1, -9, 89};

	//TODO: write a function, which prints out the passed array's elements.

	int size_of_array = sizeof(a)/sizeof(a[0]);

	print_array(a, size_of_array);

	return 0;
}

void print_array(int *array, int size)
{
	int i;
	for (i = 0; i != size; ++i)
        printf("%d ", array[i]);
    printf("\n");
}