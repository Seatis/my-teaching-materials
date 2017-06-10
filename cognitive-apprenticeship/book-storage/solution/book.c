#include "book.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void book_init(book_storage_t *storage)
{
    storage->arr = NULL;
    storage->length = 0;
}

void book_deinit(book_storage_t *storage)
{
    free(storage->arr);
    storage->arr = NULL;
    storage->length = 0;
}

int book_add(book_storage_t *storage,
             char *title,
             char *author,
             int year,
             state_t state,
             theme_t theme)
{

    // Allocate new space for a book
    int new_length = storage->length + 1;
    storage->arr = realloc(storage->arr, sizeof(book_t) * new_length);
    storage->length = new_length;

    // Fill in data into the new book struct
    strcpy(storage->arr[new_length - 1].title, title);
    strcpy(storage->arr[new_length - 1].author, author);
    storage->arr[new_length - 1].year = year;
    storage->arr[new_length - 1].state = state;
    storage->arr[new_length - 1].theme = theme;

    return 0;
}

int book_list(book_storage_t *storage)
{
    if (storage == NULL)
        return -1;

    for (int i = 0; i < storage->length; i++) {
        printf("%d - ", i + 1);
        printf("%s - ", storage->arr[i].title);
        printf("%s - ", storage->arr[i].author);
        printf("%d - ", storage->arr[i].year);
        switch (storage->arr[i].state) {
        case STATE_EXCELLENT:
            printf("excellent - ");
            break;
        case STATE_GOOD:
            printf("good - ");
            break;
        case STATE_BAD:
            printf("bad - ");
            break;
        default:
            break;
        }
        switch (storage->arr[i].theme) {
        case THEME_LITERATURE:
            printf("literature");
            break;
        case THEME_SCIENCE:
            printf("science");
            break;
        case THEME_SCI_FI:
            printf("sci-fi");
            break;
        default:
            printf("misc");
            break;
        }
        printf("\n");
    }

    return 0;
}

int book_write(book_storage_t *storage, char *path)
{
    if (storage == NULL || path == NULL)
        return -1;

    FILE *file = fopen(path, "w");
    if (file == NULL)
        return -1;

    for (int i = 0; i < storage->length; i++) {
        fprintf(file,
                "%s %s %d %d %d\n",
                storage->arr[i].title,
                storage->arr[i].author,
                storage->arr[i].year,
                storage->arr[i].state,
                storage->arr[i].theme);
    }

    fclose(file);
    return 0;
}

int book_read(book_storage_t *storage, char *path)
{
    if (storage == NULL || path == NULL)
        return -1;

    FILE *file = fopen(path, "r");
    if (file == NULL)
        return -1;

    char title[BOOK_TITLE_MAX_LEN];
    char author[BOOK_AUTHOR_MAX_LEN];
    int year;
    state_t state;
    theme_t theme;

    while(fscanf(file, "%s %s %d %d %d\n", title, author, &year, &state, &theme) == 5) {
        book_add(storage, title, author, year, state, theme);
    }

    fclose(file);
    return 0;
}
