#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <winsock2.h>

int flag;
char buff[1024];

SOCKET client_sock;

int send_message()
    {
    char msg[1024];
    //Küldés
    printf("your message:");
    gets(msg);
    flag = send (client_sock, msg, sizeof(msg), 0);
	if(msg[0] == 'c')
        return -1;
    if(flag<0)
        handle_error("Kuldes");
    printf("%dB elkuldve a %dB-bol.\n", flag, sizeof(msg));
    return 1;
    }

void handle_error(const char* error_string)
{
    printf("Hiba: %s\nHibakod: %d", error_string, WSAGetLastError());
    WSACleanup();
    exit(EXIT_FAILURE);
}
void wsa_init()
{
    WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != NO_ERROR)
    {
        wprintf(L"WSAStartup failed with error: %ld\n", iResult);
        return 1;
    }
}
void net_init()
{
    //Inicializálás

    char server_ip[]="127.0.0.1";
    short int server_port=1234;

    struct sockaddr* addr;
    struct sockaddr_in addr_in;

    client_sock=socket(PF_INET,SOCK_STREAM,IPPROTO_IP);
    if(client_sock<0)
        handle_error("Socket letrehozas");

    //Címösszeállítás
    addr_in.sin_family=AF_INET;
    addr_in.sin_port=htons(server_port);
    addr_in.sin_addr.s_addr=inet_addr(server_ip);

    addr=(struct sockaddr*)&addr_in;

//Kapcsolódás
    flag=connect(client_sock, addr, sizeof(*addr));
    if(flag<0)
        handle_error("Kapcsolodas");
    printf("Kapcsolodva - %s:%d\n", server_ip, server_port);
}
int main()
{
wsa_init();
net_init();
flag=1;

while (flag!=0)
{
    if (send_message() == -1)
    {
        flag=0;
    } else {
        //Fogadás
        flag = recv (client_sock, buff, sizeof(buff)-1, 0);
        if (flag != 0)
        {
            buff[flag] = 0;
            printf ("%s\n", buff);
        }
    }
}

//Lezárás
closesocket(client_sock);
printf("SOCKET closed, exiting");
WSACleanup();
return 0;

}

