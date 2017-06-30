#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <winsock2.h>
#include "broadcast.h"
#include "tcp_msg.h"
#include "usr_storage.h"

int send_broadcast_msg(char *msg, uint16_t dest_port)
{
    // Create broadcast socket
    SOCKET broadcast_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (broadcast_socket < 0) {
        printf("Error: send_broadcast_msg - socket()\n");
        return -1;
    }

    // Set the socket as broadcasting socket
    int setsockopt_retval = setsockopt(broadcast_socket, SOL_SOCKET, SO_BROADCAST, "1", 1);
    if (setsockopt_retval < 0) {
        printf("Error: send_broadcast_msg - setsockopt()\n");
        return -2;
    }

    // Set up destination address
    struct sockaddr_in broadcast_addr;
    broadcast_addr.sin_family = AF_INET;
    broadcast_addr.sin_port = htons(dest_port);
    broadcast_addr.sin_addr.s_addr = inet_addr(BROADCAST_IP);

    // Send broadcast message
    int sendto_retval = sendto(broadcast_socket,
                               msg,
                               strlen(msg),
                               0,
                               (SOCKADDR *)&broadcast_addr,
                               sizeof(broadcast_addr));
    if (sendto_retval < strlen(msg)) {
        printf("Error: send_broadcast_msg - sendto()\n");
        return -3;
    }

    // Close the broadcast socket
    closesocket(broadcast_socket);
    return 0;
}

void broadcast_listener()
{
    // Create listener socket
    SOCKET listen_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (listen_socket < 0) {
        printf("Error: broadcast_listener - socket()\n");
        return;
    }

    // Set the socket as broadcasting socket
    int setsockopt_retval = setsockopt(listen_socket, SOL_SOCKET, SO_BROADCAST, "1", 1);
    if (setsockopt_retval < 0) {
        printf("Error: broadcast_listener - setsockopt()\n");
        return;
    }

    // Server recv address structure initialization
	struct sockaddr_in listen_addr;
	listen_addr.sin_family = AF_INET;
	listen_addr.sin_addr.s_addr = INADDR_ANY;
	listen_addr.sin_port = htons(BROADCAST_LISTENING_PORT);

	// Bind the listen address to the socket
	if (bind(listen_socket, (struct sockaddr*)&listen_addr, sizeof(listen_addr)) < 0) {
        printf("Error: broadcast_listener - bind()\n");
        return;
	}

    //printf("broadcast_listener initialized\n");

    struct sockaddr_in client_addr;
    while (1) {
        //printf("broadcast_listener - Waiting for connection...\n");
        // recvfrom needs a pointer to the address size -.-
        int client_addr_len = sizeof(client_addr);
        // Define buffer for incoming message
        char buff[BROADCAST_MSG_LEN];
        // Receive broadcast data
        int received_bytes = recvfrom(listen_socket,
                                      buff,
                                      BROADCAST_MSG_LEN,
                                      0,
                                      (struct sockaddr*)&client_addr,
                                      &client_addr_len);
        // Check for error
        if (received_bytes < 0) {
            printf("Error: broadcast_listener - recfrom()\n");
        } else {
            // Close the string
            buff[received_bytes] = '\0';

            // Get client IP
            uint32_t client_ip = client_addr.sin_addr.s_addr;

            // Get data
            char unique_str[BROADCAST_UNIQUE_STR_LEN];
            unique_str[0] = '\0';
            int port;

            if (sscanf(buff, "%s %d", unique_str, &port) < 2) {
                printf("Error: broadcast_listener - sscanf()\n");
            } else if (strstr(BROADCAST_UNIQUE_STR, unique_str) == NULL) {
                printf("Error: broadcast_listener - unique string not found\n");
            } else {
                // Send our name and our message listening port
                char buff[TCP_MSG_LEN];
                sprintf(buff, "%s %u", my_usr_data.name, my_usr_data.port);
                send_tcp_msg(buff, client_ip, port);
            }
        }
    }
}


