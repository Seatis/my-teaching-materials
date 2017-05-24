#include "printer.h"
#include "todo.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define COMMAND_LIST_TODOS      "-l"
#define COMMAND_ADD_TODOS       "-a"
#define COMMAND_WRITE_TODOS     "-wr"
#define COMMAND_READ_TODOS      "-rd"
#define COMMAND_EMPTY_TODOS     "-e"
#define COMMAND_REMOVE_TODOS    "-r"
#define COMMAND_CHECK_TODOS     "-c"
#define COMMAND_ADD_TODOS_PRIO  "-p"
#define COMMAND_LIST_TODOS_BY_PRIO  "-lp"

char *parser(char *command, char *token, int substring)
{
    // Get parameter
    char *p;
    for(int i = 0; i < substring; i++) {
        if(i == 0 && command != NULL)
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
        if(strstr(command, COMMAND_LIST_TODOS_BY_PRIO) != NULL) {
            list_todo_by_prio(&storage);
        } else if (strstr(command, COMMAND_ADD_TODOS) != NULL) {
            char todo_name[256];

            // Copy the todo name
            char *p = parser(command, "\"", 2);

            // Error handling
            if(p == NULL) {
                print_error(ADD_NO_TASK);
            } else {
                strcpy(todo_name, p);
                // Add todo
                add_todo(&storage, todo_name, 0, 0);
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
        } else if (strstr(command, COMMAND_CHECK_TODOS) != NULL) {
            char number[256];
            // Get the number
            char *p = parser(command, " ", 2);

            // Error handling
            if(p == NULL) {
                print_error(CHECK_NO_INDEX);
            } else {
                strcpy(number, p);

                // Convert string to number
                char *ptr;
                int num = strtol(number, &ptr, 10);

                // Error handling
                if(ptr == number) {
                    print_error(CHECK_NOT_NUMBER);
                } else if (num > storage.length || num <= 0) {
                    print_error(CHECK_INV_INDEX);
                } else {
                    check_todo(&storage, num);
                }
            }
        } else if (strstr(command, COMMAND_ADD_TODOS_PRIO) != NULL) {
            char todo_name[256];
            int error = 0;

            // Get todo name
            char *p = parser(command, "\"", 2);

            // Error handling, save todo name
            if(p == NULL) {
                print_error(PRIO_NO_TASK);
                error = 1;
            } else {
                strcpy(todo_name, p);
            }

            // Get prio number
            p = parser(NULL, "\"", 1);
            char *ptr;
            int prio = strtol(p, &ptr, 10);

            // Error handling
            if(ptr == p) {
                print_error(PRIO_NOT_NUMBER);
                error = 1;
            } else {
                error = 0;
            }

            if(!error)
                add_todo(&storage, todo_name, 0, prio);
        } else if(strstr(command, COMMAND_LIST_TODOS) != NULL) {
            list_todo(&storage);
        } else {
            print_error(INV_ARGUMENT);
        }
    }

    return 0;
}
