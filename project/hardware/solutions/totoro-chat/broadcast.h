#ifndef BROADCAST_H_INCLUDED
#define BROADCAST_H_INCLUDED
#include <stdint.h>

#define BROADCAST_IP                "255.255.255.255"

#define BROADCAST_UNIQUE_STR        "TOTORO"
#define BROADCAST_UNIQUE_STR_LEN    (strlen(BROADCAST_UNIQUE_STR)+1)

#define BROADCAST_MSG_LEN           1024
#define TCP_MSG_LEN                 1024

#define BROADCAST_LISTENING_PORT    12345    // Same for every device

int send_broadcast_msg(char *msg, uint16_t dest_port);
void broadcast_listener();

#endif // BROADCAST_H_INCLUDED
