#ifndef PRINTER_H_INCLUDED
#define PRINTER_H_INCLUDED

#include "todo.h"

#define NEW_LINES_CLRSCR    60

void print_usage();
void clear_screen();
int list_todo(struct todostorage *storage);

#endif // PRINTER_H_INCLUDED
