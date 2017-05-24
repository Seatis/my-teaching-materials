#ifndef TODO_H_INCLUDED
#define TODO_H_INCLUDED

/*******************************
 *          DEFINTIONS         *
 *******************************/
#define MAX_TODO_NAME_LEN   256

/*******************************
 *       DATA STRUCTURES       *
 *******************************/
struct todo {
	char name[MAX_TODO_NAME_LEN];
	int checked;
	int prio;
};

struct todostorage {
	struct todo *array;
	int length;
};

/*******************************
 *    FUNCTION DECLARATIONS    *
 *******************************/
int add_todo(struct todostorage *storage, char *name);
int write_todo(struct todostorage *storage, char *path);
int read_todo(struct todostorage *storage, char *path);


#endif // TODO_H_INCLUDED
