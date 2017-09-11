#include "todo.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

number_of_tasks = 0;

void add_todo(todo_t *storage, char *name, int checked, int prio){
    strcpy(storage[number_of_tasks].name, name);
    storage[number_of_tasks].name;
    storage[number_of_tasks].prio = prio;
    storage[number_of_tasks].checked = checked;
    number_of_tasks++;
}

int remove_todo(todo_t *storage, int index_task){
    number_of_tasks--;
    for (int i = index_task-1; i < number_of_tasks; i++){
        strcpy(storage[i].name, storage[i+1].name);
        storage[i].prio = storage[i+1].prio;
        storage[i].checked = storage[i+1].checked;
    }
    return 0;
}

int check_todo(todo_t *storage, int index_cmp)
{
    storage[index_cmp-1].checked = 1;
}

int write_todo(todo_t *storage, char *path)
{
    // Error handling
	if (storage == NULL || path == NULL)
		return -1;

	// open file
	FILE *file = fopen(path, "w");
	if (file == NULL)
		return -1;

	// Write data to file
	for (int i = 0; i < number_of_tasks; i++) {
		fprintf(file, "%s %d %d\n",
				storage[i].name,
				storage[i].checked,
				storage[i].prio
			   );
	}

	fclose(file);
	return 0;
}

int read_todo(todo_t *storage, char *path)
{
    // Error handling
	if (storage == NULL || path == NULL)
		return -1;

	// open file
	FILE *file = fopen(path, "r");
	if (file == NULL)
		return -1;

	char name[ARRAYSIZE];
	int checked, prio;
	while (fscanf(file, "%s %d %d\n", name, &checked, &prio) == 3) {
		add_todo(storage, name, checked, prio);
	}

	fclose(file);
	return 0;
}

int empty_todo(todo_t *storage)
{
    for (int i = 0; i < number_of_tasks; i++) {
        strcpy(storage[i].name, "");
        storage[i].prio = 0;
        storage[i].checked = 0;
    }
    number_of_tasks = 0;
    return 0;
}
