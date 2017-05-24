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
    printf("Num - Tasks - Prio\n");

    for(int i = 0; i < storage->length; i++) {
        printf("%d - [", i + 1);

        if(storage->array[i].checked)
            printf("x] ");
        else
            printf(" ] ");
        printf(storage->array[i].name);
        printf(" - %d\n", storage->array[i].prio);
    }

    return 0;
}

void print_empty()
{
    clear_screen();
    printf("No todos for today! :)\n");
}

void print_error(todoerr_t err)
{
    switch(err) {
    case ADD_NO_TASK:
        printf("Unable to add: No task is provided\n");
        break;
    case RM_NO_INDEX:
        printf("Unable to remove: No index is provided\n");
        break;
    case RM_NOT_NUMBER:
        printf("Unable to remove: Index is not a number\n");
        break;
    case RM_INV_INDEX:
        printf("Unable to remove: Index is out of bound\n");
        break;
    case CHECK_NO_INDEX:
        printf("Unable to check: No index is provided\n");
        break;
    case CHECK_NOT_NUMBER:
        printf("Unable to check: Index is not a number\n");
        break;
    case CHECK_INV_INDEX:
        printf("Unable to check: Index is out of bound\n");
        break;
    case PRIO_NO_TASK:
        printf("Unable to add task with priority: No task is provided\n");
        break;
    case PRIO_NOT_NUMBER:
        printf("Unable to add task with priority: Index is not a number\n");
        break;
    default:
        break;
    }
}
