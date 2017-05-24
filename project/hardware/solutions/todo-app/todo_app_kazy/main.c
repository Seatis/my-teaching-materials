#include "printer.h"
#include "todo.h"
#include <stdlib.h>

int main()
{
	print_usage();

	struct todostorage storage = {NULL, 0};
	add_todo(&storage, "Ez kell");
	add_todo(&storage, "Az kell");
	list_todo(&storage);
	write_todo(&storage, "tmp.txt");
	read_todo(&storage, "tmp.txt");
	list_todo(&storage);
	return 0;
}
