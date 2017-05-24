#include "todo.h"
#include <stdlib.h>
#include <stdio.h>

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
