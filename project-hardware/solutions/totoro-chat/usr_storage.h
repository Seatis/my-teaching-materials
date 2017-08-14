#ifndef USR_STORAGE_H_INCLUDED
#define USR_STORAGE_H_INCLUDED

#include <stdint.h>

#define TOTORO_STORAGE_LEN  50
#define NAME_LEN            256

typedef struct {
    char name[NAME_LEN];
    uint32_t ip;
    uint16_t port;
} totoro_usr_t;

typedef struct {
    totoro_usr_t arr[TOTORO_STORAGE_LEN];
    int cnt;
}totoro_usr_storage_t;

totoro_usr_storage_t usr_storage;
totoro_usr_t my_usr_data;

void usr_storage_init(char *name, uint16_t port);
void add_user(char *name, uint32_t ip, uint16_t port);
void set_my_name(char *name);
void list_users();
char *get_usr_name(uint32_t ip);
int get_usr_index_by_name(char *name);
#endif // USR_STORAGE_H_INCLUDED
