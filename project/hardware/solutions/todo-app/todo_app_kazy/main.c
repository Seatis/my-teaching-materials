#include "printer.h"
#include "todo.h"
#include <stdlib.h>
#include <string.h>

#define COMMAND_LIST_TODOS "-l"
#define COMMAND_ADD_TODOS "-a"
#define COMMAND_WRITE_TODOS "-wr"
#define COMMAND_READ_TODOS "-rd"

int main()
{
	struct todostorage storage = {NULL, 0};

	print_usage();

    char command[256];

	while(1) {
        // Get command string
        gets(command);
        // Search for command
        if(strstr(command, COMMAND_LIST_TODOS) != NULL) {
            list_todo(&storage);
        } else if (strstr(command, COMMAND_ADD_TODOS) != NULL) {
            char todo_name[256];
            // Get parameter
            char *p;
            p = strtok(command, "\"");  // Get the substring before the first "
            p = strtok(NULL, "\"");     // Get the second substring (between the two ")

            // Copy the todo name
            strcpy(todo_name, p);

            // Save to file
            add_todo(&storage, todo_name);

        } else if (strstr(command, COMMAND_WRITE_TODOS) != NULL) {
            char filename[256];
            // Get parameter
            char *p;
            p = strtok(command, "\"");  // Get the substring before the first "
            p = strtok(NULL, "\"");     // Get the second substring (between the two ")

            // Copy the filename
            strcpy(filename, p);

            // Save to file
            write_todo(&storage, filename);

        } else if (strstr(command, COMMAND_READ_TODOS) != NULL) {
            char filename[256];
            // Get parameter
            char *p;
            p = strtok(command, "\"");  // Get the substring before the first "
            p = strtok(NULL, "\"");     // Get the second substring (between the two ")

            // Copy the filename
            strcpy(filename, p);

            // Save to file
            read_todo(&storage, filename);

        }
	}

	return 0;
}
