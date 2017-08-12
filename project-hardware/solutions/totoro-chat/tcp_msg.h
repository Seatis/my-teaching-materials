#ifndef TCP_MSG_H_INCLUDED
#define TCP_MSG_H_INCLUDED

#include <stdint.h>

#define MSG_PORT        54264
#define DISC_PORT       54265

#define MSG_BUFF_LEN         4096
#define DISC_BUFF_LEN        4096

#define TCP_QUEUE_SIZE      100

int send_tcp_msg(char *msg, uint32_t ip, uint16_t port);

void msg_listener();
void disc_listener();

#endif // TCP_MSG_H_INCLUDED
