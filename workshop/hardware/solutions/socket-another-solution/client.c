#include<stdio.h>
#include<winsock2.h>

/**
Creating a client app

Initialising Winsock---> WSAStartup
Creating a socket---> socket()
Connect to a Server---> connect()
Sending Data---> send()
Receiving Data---> recv()
Close socket
*/

int main(int argc , char *argv[]) //argc and argv are the arguments that passed form cl to main
{
    WSADATA wsa;
    SOCKET s;
    struct sockaddr_in server;
    char *message;
    char server_reply[2000];
    int recv_size;

    //Initialising Winsock
    printf("\nInitialising Winsock...\t");
    if (WSAStartup(MAKEWORD(2,2),&wsa) != 0) //the WSAStartup() func. has two agruments, first is the version number
                                             //the second is the struct that holds all the additional informations
    {
        printf("Failed. Error Code : %d",WSAGetLastError()); //WSAGetLastError gives back an error code,
                                                             //you can look up any of it in:
                                                             //https://msdn.microsoft.com/en-us/library/windows/desktop/ms740668(v=vs.85).aspx
        return 1;
    }

    /**
    you can check what values have been passed to main using printf()
    printf("\nthe 'int argc' agrumentum contains: %d \n", argc);
    printf("the 'int argc' agrumentum contains: %c \n", argv);
    */

    printf("Initialised.\n");

    //Create a socket
    if((s = socket(AF_INET , SOCK_STREAM , 0 )) == INVALID_SOCKET)
        //socket() func creates a socket and returns a socket descriptor
        //Address Family: AF_INET stands for IP version 4
        //type: SOCK_STREAM this calls the TCP protocol
        //protocol function: this is 0 usually, in this case the service provider will choose the protocol to use
    {
        printf("Could not create socket : %d" , WSAGetLastError());
    }

    printf("Socket created.\n");


    server.sin_addr.s_addr = inet_addr("216.58.209.206"); //google.com
    server.sin_family = AF_INET; //the internet protocol version 4 (IPv4) address family
    server.sin_port = htons( 80 ); //the port we are using

    //Connect to remote server
    //we need two things: IP address and a port number
    if (connect(s , (struct sockaddr *)&server , sizeof(server)) < 0)
        //connect() func takes three parameters
        //a descriptor identifying a connected socket
        //second is a pointer to the sockaddr structure to which the connection should be established
        //third is the length, in bytes, of the sockaddr structure pointed to by the name parameter
    {
        printf("Could not create socket : %d" , WSAGetLastError());
        return 1;
    }

    puts("Connected");

    //Send some data
    message = "GET / HTTP/1.1\r\n\r\n"; //CRLF line endings
    if( send(s , message , strlen(message) , 0) < 0)
        //send() func sends data on a connected socket
        //the first parameter is a descriptor identifying a connected socket
        //the second is the message
        //the third is the length of the message size
        //the fouth stands for the flag, it is usually is a 0
    {
        puts("Send failed");
        return 1;
    }
    puts("Data Send\n");

    //Receive a reply from the server
    if((recv_size = recv(s , server_reply , 2000 , 0)) == SOCKET_ERROR)
    {
        puts("recv failed");
    }

    puts("Reply received\n");

    //Add a NULL terminating character to make it a proper string before printing
    server_reply[recv_size] = '\0';
    puts(server_reply);

    closesocket(s);
    WSACleanup();

    return 0;
}
