#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book.h"

#define MAX_COMMAND_LEN 255
#define MAX_FILE_NAME_LEN 255
#define COM_ADD "add"
#define COM_LIST "list"
#define COM_EXIT "exit"
#define COM_WRITE "write"
#define COM_READ "read"

int main()
{
    printf("Hello world!\n");

    book_storage_t storage;
    book_init(&storage);

    char com[MAX_COMMAND_LEN];
    char com_to_parse[MAX_COMMAND_LEN];
    while (1) {
        gets(com);
        strcpy(com_to_parse, com);
        char *p;
        p = strtok(com_to_parse, "\"");

        if(strstr(p, COM_ADD)) {
            // Get title
            p = strtok(NULL, "\"");
            char title[BOOK_TITLE_MAX_LEN];
            strcpy(title, p);
            // Get author
            p = strtok(NULL, "\"");
            p = strtok(NULL, "\"");
            char author[BOOK_AUTHOR_MAX_LEN];
            strcpy(author, p);
            // Get year
            p = strtok(NULL, "\"");
            p = strtok(NULL, "\"");
            int year = atoi(p);
            // Get state
            p = strtok(NULL, "\"");
            p = strtok(NULL, "\"");
            state_t state;
            if (strcmp(p, "e") == 0)
                state = STATE_EXCELLENT;
            else if (strcmp(p, "g") == 0)
                state = STATE_GOOD;
            else if (strcmp(p, "b") == 0)
                state = STATE_BAD;
            else
                state = STATE_BAD;
            // Get theme
            p = strtok(NULL, "\"");
            p = strtok(NULL, "\"");
            theme_t theme;
            if (strcmp(p, "lit") == 0)
                theme = THEME_LITERATURE;
            else if (strcmp(p, "sci") == 0)
                theme = THEME_SCIENCE;
            else if (strcmp(p, "sci-fi") == 0)
                theme = THEME_SCI_FI;
            else
                theme = THEME_MISC;

            // Add stuff
            book_add(&storage, title, author, year, state, theme);
        } else if (strstr(p, COM_LIST)) {
            book_list(&storage);
        } else if (strstr(p, COM_EXIT)) {
            break;
        } else if (strstr(p, COM_WRITE)) {
            // Get file name
            p = strtok(NULL, "\"");
            char path[MAX_FILE_NAME_LEN];
            strcpy(path, p);
            // Writ to file
            book_write(&storage, path);
        } else if (strstr(p, COM_READ)) {
            // Get file name
            p = strtok(NULL, "\"");
            char path[MAX_FILE_NAME_LEN];
            strcpy(path, p);
            // Writ to file
            book_read(&storage, path);
        }
    }

    book_deinit(&storage);

    return 0;
}
