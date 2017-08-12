#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <winsock2.h>
#include "tcp_msg.h"
#include "usr_storage.h"

int send_tcp_msg(char *msg, uint32_t ip, uint16_t port)
{
	// Creating client TCP IP socket
	SOCKET client_sock = socket(PF_INET, SOCK_STREAM, IPPROTO_IP);
	if (client_sock < 0) {
        printf("Error: send_tcp_msg - socket()\n");
        return -1;
	}

	// Creating server address
	struct sockaddr_in server_addr;
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(port);
	server_addr.sin_addr.s_addr = ip;

	// Connecting the client socket to the server
	int connect_retval = connect(client_sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
	if (connect_retval < 0) {
        printf("Error: send_tcp_msg - connect()\n");
        return -1;
	}

    // Send the message to the servers
	int sent_bytes = send(client_sock, msg, strlen(msg), 0);
	if (sent_bytes < strlen(msg)) {
        printf("Error: send_tcp_msg - send()\n");
        return -1;
	}

	// Close socket
	closesocket(client_sock);
	return 0;
}

void msg_listener()
{
    // Create listener socket
    SOCKET listen_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
    if (listen_socket < 0) {
        printf("Error: msg_listener - socket()\n");
        return;
    }

    // Server listen address structure initialization
	struct sockaddr_in listen_addr;
	listen_addr.sin_family = AF_INET;
	listen_addr.sin_addr.s_addr = INADDR_ANY;
	listen_addr.sin_port = htons(MSG_PORT);

	// Bind the listen address to the socket
	if (bind(listen_socket, (struct sockaddr*)&listen_addr, sizeof(listen_addr)) < 0) {
        printf("Error: msg_listener - bind()\n");
        return;
	}

    // Start listening on with the set socket with a predefined queue size
	if (listen(listen_socket, TCP_QUEUE_SIZE) < 0) {
        printf("Error: msg_listener - listen()\n");
        return;
	}

    // printf("msg_listener initialized\n");

    struct sockaddr_in client_addr;
    int client_addr_len = sizeof(client_addr);
    SOCKET client_socket;
    while (1) {
        //printf("msg_listener - Waiting for connection...\n");
        // Accept incoming connections
        client_socket = accept(listen_socket, (struct sockaddr*)&client_addr, &client_addr_len);
        if (client_socket == INVALID_SOCKET) {
            printf("Error: msg_listener - accept()\n");
        } else {
            // Define buffer for incoming message
            char buff[DISC_BUFF_LEN];
            // Receive broadcast data
            int received_bytes = recv(client_socket, buff, DISC_BUFF_LEN, 0);
            // Check for error
            if (received_bytes < 0) {
                printf("Error: msg_listener - recv()\n");
            } else {
                // Close the string
                buff[received_bytes] = '\0';

                // Get client IP
                uint32_t client_ip = client_addr.sin_addr.s_addr;

                // Print client name
                printf("%s: ", get_usr_name(client_ip));
                // Print the message
                printf("%s\n", buff);
            }
            closesocket(client_socket);
        }
    }
}

void disc_listener()
{
    // Create listener socket
    SOCKET listen_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
    if (listen_socket < 0) {
        printf("Error: disc_listener - socket()\n");
        return;
    }

    // Server listen address structure initialization
	struct sockaddr_in listen_addr;
	listen_addr.sin_family = AF_INET;
	listen_addr.sin_addr.s_addr = INADDR_ANY;
	listen_addr.sin_port = htons(DISC_PORT);

	// Bind the listen address to the socket
	if (bind(listen_socket, (struct sockaddr*)&listen_addr, sizeof(listen_addr)) < 0) {
        printf("Error: disc_listener - bind()\n");
        return;
	}

    // Start listening on with the set socket with a predefined queue size
	if (listen(listen_socket, TCP_QUEUE_SIZE) < 0) {
        printf("Error: disc_listener - listen()\n");
        return;
	}

    //printf("disc_listener initialized\n");

    struct sockaddr_in client_addr;
    int client_addr_len = sizeof(client_addr);
    SOCKET client_socket;
    while (1) {
        //printf("disc_listener - Waiting for connection...\n");
        // Accept incoming connections
        client_socket = accept(listen_socket, (struct sockaddr*)&client_addr, &client_addr_len);
        if (client_socket == INVALID_SOCKET) {
            printf("Error: disc_listener - accept()\n");
        } else {
            // Define buffer for incoming message
            char buff[DISC_BUFF_LEN];
            // Receive broadcast data
            int received_bytes = recv(client_socket, buff, DISC_BUFF_LEN, 0);
            // Check for error
            if (received_bytes < 0) {
                printf("Error: disc_listener - recv()\n");
            } else {
                // Close the string
                buff[received_bytes] = '\0';

                // Get client IP
                uint32_t client_ip = client_addr.sin_addr.s_addr;

                // Get data
                char name[NAME_LEN];
                name[0] = '\0';
                int port;

                if (sscanf(buff, "%s %d", name, &port) < 2) {
                    printf("Error: disc_listener - sscanf()\n");
                }  else {
                    // Add new user data
                    add_user(name, client_ip, port);
                    // printf("disc_listener - %s added\n", name);
                }
            }
            closesocket(client_socket);
        }
    }
}
