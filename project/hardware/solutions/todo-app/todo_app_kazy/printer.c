#include "printer.h"
#include "todo.h"
#include <stdio.h>
#include <stdlib.h>

void print_usage()
{
    clear_screen();
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

void clear_screen()
{
    system("cls");
}

int list_todo(struct todostorage *storage)
{
	if(storage == NULL)
		return -1;
    clear_screen();
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
