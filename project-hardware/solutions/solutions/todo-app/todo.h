#ifndef TODO_H_INCLUDED
#define TODO_H_INCLUDED

/*******************************
 *          DEFINTIONS         *
 *******************************/
#define MAX_TODO_NAME_LEN   256
#define ARRAYSIZE 20

int number_of_tasks;
/*******************************
 *       DATA STRUCTURES       *
 *******************************/
typedef struct {
	char name[ARRAYSIZE];
	int checked;
	int prio;
} todo_t;

/*******************************
 *    FUNCTION DECLARATIONS    *
 *******************************/
void add_todo(todo_t *storage, char *name, int checked, int prio);
int remove_todo(todo_t *storage, int index_task);
int check_todo(todo_t *storage, int index_cmp);
int write_todo(todo_t *storage, char *path);
int read_todo(todo_t *storage, char *path);
int empty_todo(todo_t *storage);

#endif // TODO_H_INCLUDED
