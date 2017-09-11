#ifndef PRINTER_H_INCLUDED
#define PRINTER_H_INCLUDED

#include "todo.h"

#define NEW_LINES_CLRSCR    60

typedef enum {
	ADD_NO_TASK,
	RM_NO_INDEX,
	RM_INV_INDEX,
	RM_NOT_NUMBER,
	CHECK_NO_INDEX,
	CHECK_INV_INDEX,
	CHECK_NOT_NUMBER,
	PRIO_NO_TASK,
	PRIO_NOT_NUMBER,
	INV_ARGUMENT
} todoerr_t;

void print_usage();
void clear_screen();
int list_todo(todo_t *storage);
int list_todo_by_prio(todo_t *storage);
void print_empty();
void print_error(todoerr_t err);

#endif // PRINTER_H_INCLUDED
