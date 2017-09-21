#include <stdio.h>

int assort_odd_elements(int *array, int size);

int main(void) {
	int num_array[] = {8, 7, 9, 20, 3, 81, 79, 66};

    //TODO: write a function which filters out the odd elements of an integer array
    //do it in the original array
    //your return value should be the real size of the filtered array
    //print out the filtered array's elements

    int array_size = sizeof(num_array)/sizeof(num_array[0]);

    int real_size = assort_odd_elements(num_array, array_size);

    int i;
    for(i = 0; i < real_size; i++) {
        printf("%d\n", num_array[i]);
    }

    return 0;
}

int assort_odd_elements(int *array, int size)
{
    int pos = 0;

    int i;
    for(i = 0; i < size; i++) {
        if (array[i] % 2 == 1) {
            array[pos] = array[i];
            pos++;
        }
    }
    return pos;
}