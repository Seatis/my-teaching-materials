#include "todo.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int add_todo(struct todostorage *storage, char *name)
{
	// Error handling
	if(storage == NULL || name == NULL)
		return -1;

	// If the storage is empty allocate memory, else reallocate
	if(storage->array == NULL || storage->length == 0) {
		storage->array = (struct todo*)malloc(sizeof(struct todo));
	} else {
		int size_in_bytes = sizeof(struct todo) * (storage->length + 1);
		storage->array = (struct todo*)realloc(storage->array, size_in_bytes);
	}
	storage->length++;

	// Put name into the new todo's name member
	int index = storage->length - 1;
	strcpy(storage->array[index].name, name);

	return 0;
}

int write_todo(struct todostorage *storage, char *path)
{
	// Error handling
	if(storage == NULL || path == NULL)
		return -1;

    // open file
    FILE *file = fopen(path, "w");
    if(file == NULL)
		return -1;

	for(int i = 0; i < storage->length; i++) {
		fprintf(file, "%s\n", storage->array[i].name);
	}

	fclose(file);
	return 0;
}

int read_todo(struct todostorage *storage, char *path)
{
	// Error handling
	if(storage == NULL || path == NULL)
		return -1;

    // open file
    FILE *file = fopen(path, "r");
    if(file == NULL)
		return -1;

	char buffer[MAX_TODO_NAME_LEN];

    while(fgets(buffer, MAX_TODO_NAME_LEN, file) != NULL) {
		// Remove \n
		buffer[strlen(buffer) - 1] = '\0';
		// Add to storage
        add_todo(storage, buffer);
    }

	fclose(file);
	return 0;
}

int empty_todo(struct todostorage *storage)
{
	// Error handling
	if(storage == NULL)
		return -1;

    free(storage->array);
    storage->array = NULL;
    storage->length = 0;
    return 0;
}

int remove_todo(struct todostorage *storage, int num)
{
	// Error handling
	if(storage == NULL || (num > storage->length))
		return -1;

    // First allocate memory for the temporary array
    int count = storage->length - num;
    struct todo *tmp = (struct todo*)calloc(count, sizeof(struct todo));
    // Copy the todos after "num" into the tmp array
    for(int i = 0; i < count; i++) {
        tmp[i] = storage->array[num + i];
    }
    // Reallocate the array
    int new_array_size = storage->length - 1;
    int new_array_size_in_bytes = new_array_size * sizeof(struct todo);
    storage->array = realloc(storage->array, new_array_size_in_bytes);
    storage->length--;
    // Copy the tmp stored values into the reallocated array
    for(int i = 0; i < count; i++) {
        storage->array[num - 1 + i] = tmp[i];
    }
    free(tmp);
    return 0;
}
