#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// TODO:
// Create a struct called circular_buffer
// It should store:
// A pointer that points to the start of a dynamically allocated array of ints (could be null) (head pointer)
// A pointer that points to the end of the dynamically allocated array of ints (could be null) (tail pointer)
// A pointer that points to the currently readable buffer item (could be null) (read pointer))
// A pointer that points to the currently writable buffer item (could be null) (write pointer)
// The lenght of the buffer
typedef struct {
	int *head;
	int *tail;
	int *read;
	int *write;
} circular_buffer;

// TODO:
// Create a function that returns a dynamically allocated circular_buffer (the buffer itself should be allocated as well, not just the array inside)
// It should take a normal array and it's length as argument, and it should fill all the buffer values from the array
circular_buffer *get_new_circular_buffer(int *source_array, int len)
{
	int *buffer = (int *)calloc(len, sizeof(int));
	memcpy(buffer, source_array, len * sizeof(int));

	circular_buffer *to_return = malloc(sizeof(circular_buffer));
	to_return->head = buffer;
	to_return->read = buffer;
	to_return->write = buffer;
	to_return->tail = &buffer[len - 1];

	return to_return;
}

// TODO:
// Create a function that resizes a circular_buffer, it should take a circular_buffer as a pointer and change that buffers length and reallocate it's array as well. (copying it's values)
void resize(circular_buffer *circular_buffer, int len)
{
	int index_of_element_poited_by_read = circular_buffer->read - circular_buffer->head;
	int index_of_element_poited_by_write = circular_buffer->write - circular_buffer->head;

	circular_buffer->head = realloc(circular_buffer->head, len * sizeof(int));
	circular_buffer->tail = &(circular_buffer->head[len - 1]);
	circular_buffer->read = &(circular_buffer->head[index_of_element_poited_by_read]);
	circular_buffer->write = &(circular_buffer->head[index_of_element_poited_by_write]);
}


// TODO:
// Create a function that takes a circular_buffer and returns a new circular_buffer that only contains the even numbers from the old circular_buffer

// TODO:
// Try all the functions in the main function, plase deallocate any buffer and the array inside it after using them

int main()
{
	circular_buffer *ptr;
	int array[12] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
	ptr = get_new_circular_buffer(array, 12);

	printf("Length=12\n");
	for (int *i = ptr->head; i <= ptr->tail ; i++) {
		printf("@%p:", i);
		printf("%d\n", *i);
	}
	printf("\n\n\n");

	resize(ptr, 24);
	printf("Length=24\n");
	for (int *i = ptr->head; i <= ptr->tail ; i++) {
		printf("@%p:", i);
		printf("%d\n", *i);
	}
	printf("\n\n\n");

	free(ptr->head);
	free(ptr);
	return 0;
}
