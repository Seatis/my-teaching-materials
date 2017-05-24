#ifndef PRINTER_H_INCLUDED
#define PRINTER_H_INCLUDED

#include "todo.h"

#define NEW_LINES_CLRSCR    60

typedef enum {
    ADD_NO_TASK,
    RM_NO_INDEX,
    RM_INV_INDEX,
    RM_NOT_NUMBER
} todoerr_t;

void print_usage();
void clear_screen();
int list_todo(struct todostorage *storage);
void print_empty();
void print_error(todoerr_t err);
#endif // PRINTER_H_INCLUDED
