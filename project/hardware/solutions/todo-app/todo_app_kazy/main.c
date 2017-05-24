#include "printer.h"
#include "todo.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define COMMAND_LIST_TODOS "-l"
#define COMMAND_ADD_TODOS "-a"
#define COMMAND_WRITE_TODOS "-wr"
#define COMMAND_READ_TODOS "-rd"
#define COMMAND_EMPTY_TODOS "-e"
#define COMMAND_REMOVE_TODOS "-r"

char *parser(char *command, char *token, int substring)
{
    // Get parameter
    char *p;
    for(int i = 0; i < substring; i++) {
        if(i == 0)
            p = strtok(command, token);
        else
            p = strtok(NULL, token);
    }
    return p;
}

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

            // Copy the todo name
            char *p = parser(command, "\"", 2);

            // Error handling
            if(p == NULL) {
                print_error(ADD_NO_TASK);
            } else {
                strcpy(todo_name, p);
                // Save to file
                add_todo(&storage, todo_name);
            }

        } else if (strstr(command, COMMAND_WRITE_TODOS) != NULL) {
            char filename[256];
            // Copy the filename
            strcpy(filename, parser(command, "\"", 2));

            // Save to file
            write_todo(&storage, filename);

        } else if (strstr(command, COMMAND_READ_TODOS) != NULL) {
            char filename[256];

            // Copy the filename
            strcpy(filename, parser(command, "\"", 2));

            // Save to file
            read_todo(&storage, filename);

        } else if (strstr(command, COMMAND_EMPTY_TODOS) != NULL) {
            // Empty the storage
            empty_todo(&storage);
            print_empty();

        } else if (strstr(command, COMMAND_REMOVE_TODOS) != NULL) {
            char number[256];
            // Get the number
            char *p = parser(command, " ", 2);

            // Error handling
            if(p == NULL) {
                print_error(RM_NO_INDEX);
            } else {
                strcpy(number, p);

                // Convert string to number
                char *ptr;
                int num = strtol(number, &ptr, 10);

                // Error handling
                if(ptr == number) {
                    print_error(RM_NOT_NUMBER);
                } else if (num > storage.length || num <= 0) {
                    print_error(RM_INV_INDEX);
                } else {
                    // Remove todo
                    remove_todo(&storage, num);
                }
            }
        }
    }

    return 0;
}
