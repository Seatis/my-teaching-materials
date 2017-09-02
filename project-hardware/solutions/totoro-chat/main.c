#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <winsock2.h>
#include <conio.h>
#include <process.h>
#include "broadcast.h"
#include "tcp_msg.h"
#include "usr_storage.h"

void wsa_init();
void wsa_deinit();
void print_usage();

int main()
{
    // TODO:
    // Initialize WSA
    wsa_init();

    // TODO:
    // Set default name
    usr_storage_init("Kazy", MSG_PORT);

    // TODO:
    // Start broadcast listener
    _beginthread(broadcast_listener, 0, NULL);

    // TODO:
    // Start message listener
    _beginthread(msg_listener, 0, NULL);

    // TODO:
    // Start discovery listener
    _beginthread(disc_listener, 0, NULL);

    // TODO:
    // Start user input handling
    int loop_exit = 0;
    char name[NAME_LEN];
    char msg[MSG_BUFF_LEN];
    while (!loop_exit) {
        if (kbhit()) {
            char usr_input = getch();
            switch (usr_input) {
            case 'e':
                loop_exit = 1;
                break;
            case 'n':
                // TODO:
                // Set name
                printf("Please enter your name: ");
                gets(name);
                set_my_name(name);
                break;
            case 'd':
                // TODO:
                // Send discovery request
                printf("Sending discovery request...\n");
                char buff[BROADCAST_MSG_LEN];
                sprintf(buff, "TOTORO %d", DISC_PORT);
                if (send_broadcast_msg(buff, BROADCAST_LISTENING_PORT) < 0)
                    printf("Error in discovery request sending\n\n");
                else
                    printf("Discovery request sent\n\n");
                break;
            case 'l':
                // TODO:
                // List users
                list_users();
                break;
            case 'm':
                // TODO:
                // Send message
                printf("Enter message (name message): ");
                scanf("%s %s", name, msg);
                int index = get_usr_index_by_name(name);
                if (index >= 0)
                    send_tcp_msg(msg, usr_storage.arr[index].ip, usr_storage.arr[index].port);
                break;
            case 'h':
                // TODO:
                // Print help inf;
                print_usage();
                break;
            default:
                break;
            }
        }
    }

    // TODO:
    // Deinitialize WSA
    wsa_deinit();
    return 0;
}

void handle_error(const char *error_string)
{
	printf("Error: %s\nError code: %d\n", error_string, WSAGetLastError());
	WSACleanup();
	printf("Press any key to exit from the program...");
	while (!kbhit());
	exit(EXIT_FAILURE);
}

void wsa_init()
{
    WSADATA wsaData;
	int wsa_result = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (wsa_result != NO_ERROR)
		handle_error("WSAStartup() ");
    else
        printf("WSA initialized\n");
}

void wsa_deinit()
{
    printf("Cleaning up winsock2...\n");
	WSACleanup();
}

void print_usage()
{
    system("cls");
    printf("TOTORO - CHAT\n");
    printf("-------------\n");
    printf("e\tExit\n");
    printf("n\tSet your name\n");
    printf("l\tList users\n");
    printf("d\tSend discovery request\n");
    printf("m\tSend message\n");
    printf("h\tPrint help info\n");
}

