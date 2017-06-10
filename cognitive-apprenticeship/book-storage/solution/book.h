#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED

/************************
 * Constant definitions
 ************************/
#define BOOK_TITLE_MAX_LEN  255
#define BOOK_AUTHOR_MAX_LEN  255


/*******************
 * Type definitions
 *******************/
typedef enum {
    STATE_EXCELLENT,
    STATE_GOOD,
    STATE_BAD
}state_t;

typedef enum {
    THEME_LITERATURE,
    THEME_SCIENCE,
    THEME_SCI_FI,
    THEME_MISC
}theme_t;

typedef struct {
    char title[BOOK_TITLE_MAX_LEN];
    char author[BOOK_AUTHOR_MAX_LEN];
    int year;
    state_t state;
    theme_t theme;
}book_t;

typedef struct {
    book_t *arr;
    unsigned int length;
}book_storage_t;

/************************
 * Function declarations
 ************************/
void book_init(book_storage_t *storage);
void book_deinit(book_storage_t *storage);
int book_add(book_storage_t *storage,
             char *title,
             char *author,
             int year,
             state_t state,
             theme_t theme);
int book_list(book_storage_t *storage);
int book_write(book_storage_t *storage, char *path);

#endif // BOOK_H_INCLUDED
