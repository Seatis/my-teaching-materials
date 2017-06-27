#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <winsock2.h>
#include "usr_storage.h"

void usr_storage_init(char *name, uint16_t port)
{
    usr_storage.cnt = 0;
    strcpy(my_usr_data.name, name);
    my_usr_data.port = port;
}

int is_usr_in_storage(totoro_usr_t usr)
{
    for (int i = 0; i < usr_storage.cnt; i++) {
        if (usr.ip == usr_storage.arr[i].ip)
            return 1;
    }
    return 0;
}

void add_user(char *name, uint32_t ip, uint16_t port)
{
    // Make the user structure
    totoro_usr_t new_usr;
    strcpy(new_usr.name, name);
    new_usr.ip = ip;
    new_usr.port = port;

    // Check if user already in the storage, and add to storage if not
    if (!is_usr_in_storage(new_usr)) {
        usr_storage.arr[usr_storage.cnt] = new_usr;
        usr_storage.cnt++;
    }
}

void set_my_name(char *name)
{
    strcpy(my_usr_data.name, name);
}

void list_users()
{
    struct in_addr addr;
    printf("IP\t\tport\tname\n");
    for (int i = 0; i < usr_storage.cnt; i++) {
        addr.s_addr = usr_storage.arr[i].ip;
        printf("%s\t%u\t%s\n",
               inet_ntoa(addr),
               usr_storage.arr[i].port,
               usr_storage.arr[i].name);
    }
}

char *get_usr_name(uint32_t ip)
{
    for (int i = 0; i < usr_storage.cnt; i++) {
        if (ip == usr_storage.arr[i].ip)
            return usr_storage.arr[i].name;
    }
    return NULL;
}

int get_usr_index_by_name(char *name)
{
    for (int i = 0; i < usr_storage.cnt; i++) {
        if (strcmp(name, usr_storage.arr[i].name) == 0)
            return i;
    }
    return -1;
}
