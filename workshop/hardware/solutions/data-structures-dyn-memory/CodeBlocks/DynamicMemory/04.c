#include <stdio.h>
#include <stdlib.h>
// TODO:
/**
 * Create a function called "resize" that takes a pointer to an int array, it's
 * size and it's new size,
 * then it should return a new pointer that points to the new resized array.
 * It should copy all the elements to the new array, if the array is bigger it
 * should fill all the new slots with zeros.
 * It should delete the old array.
 */
#define NEWSIZE 11
int* resize(int* array, int size, int newsize)
{
    if(newsize < size)
    {
        printf("Newsize is smaller than size!\n");
        return NULL;
    }
    // Create new pointer
    int* array_ptr;
    // Allocate memory for "newsize" integers
    array_ptr = (int*)calloc(newsize, sizeof(int));
    // Copy the items of source array
    int i;
    for (i = 0; i < size; i++)
    {
        array_ptr[i] = array[i];
    }
    // Fill the remaining with zeros
    for (; i < newsize; i++)
    {
        array_ptr[i] = 0;
    }
    // Free up the memory allocated by "array"
    free(array);
    // Return with the new pointer
    return array_ptr;
}
int main()
{
    int array[] = {1, 2, 3, 4, 5, 6};
    int length = sizeof(array) / sizeof(array[0]);
    int* newarray = resize(array, length, NEWSIZE);
    for (int i = 0; i < NEWSIZE; i++)
    {
        printf("%d\n", *(newarray + i));
    }
    free(newarray);
    return 0;
}