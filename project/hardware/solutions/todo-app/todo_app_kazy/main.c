#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TODO_NAME_LEN   256

struct todo {
	char name[MAX_TODO_NAME_LEN];
	int checked;
	int prio;
};

struct todostorage {
	struct todo *array;
	int length;
};

void print_usage()
{
	printf("Todo application\n");
	printf("====================\n");
	printf("Commands:\n");
	printf(" -a   Adds a new task\n");
	printf(" -wr  Write current todos to file\n");
	printf(" -rd  Read todos from a file\n");
	printf(" -l   Lists all the tasks\n");
	printf(" -e   Empty the list\n");
	printf(" -r   Removes a task\n");
	printf(" -c   Completes a task\n");
	printf(" -p   Add priority to a task\n");
	printf(" -lp  Lists all the tasks by priority\n");
}

int add_todo(struct todostorage *storage, char *name)
{
	// Error handling
	if(storage == NULL || name == NULL)
		return -1;

	// If the storage is empty allocate memory, else reallocate
	if(storage->array == NULL) {
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

int list_todo(struct todostorage *storage)
{
	if(storage == NULL)
		return -1;

	printf("List by number\n");
	printf("====================\n");
	printf("Num \t|\t Tasks\n");

	for(int i = 0; i < storage->length; i++) {
        printf("%d\t-\t", i + 1);
		printf(storage->array[i].name);
		printf("\n");
	}

	return 0;
}

int main()
{
	print_usage();

	struct todostorage storage = {NULL, 0};
	add_todo(&storage, "Ez kell");
	add_todo(&storage, "Az kell");
	list_todo(&storage);
	return 0;
}
