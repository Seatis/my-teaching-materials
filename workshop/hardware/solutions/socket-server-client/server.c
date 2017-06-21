#define _WIN32_WINNT 0x0501

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <winsock2.h>
#include <conio.h>
#include <math.h>

/*
#include <fstream>
#include <ctime>
#include <iostream>
using namespace std;

ofstream myfile;

const std::string currentDateTime() {
time_t     now = time(0);
struct tm  tstruct;
char       buf[80];
tstruct = *localtime(&now);
// Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
// for more information about date/time format
strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);

return buf;
}

void print_data(char* buff)
{
unsigned char* buff2=(unsigned char*)buff;
double ST=buff2[0]*256.0+buff2[1];

double SRH=buff2[2];
SRH=SRH*256.0+buff2[3];

double Vbat=buff2[5];
Vbat=Vbat*256.0+buff2[4];

double temp=175.0*ST/(65535.0)-45.0;
double humidity=100.0*SRH/65535.0;

cout<<"Data Bytes:"<<endl;
for(int i=0; i<6; i++)
    cout<<(double)(buff2[i])<<endl;
0
cout<<currentDateTime()<<endl;
cout<<"Temperature: "<<temp<<"oC"<<endl;
cout<<"Humidity: "<<humidity<<"\%"<<endl;
cout<<"Vbat: "<<Vbat<<"mV"<<endl;
myfile<<currentDateTime()<<"\t"<<temp<<"\t"<<humidity<<"\t"<<Vbat<<endl;
}

*/

void handle_error(const char* error_string)
{
printf("Hiba: %s\nHibakod: %d", error_string, WSAGetLastError());
WSACleanup();
exit(EXIT_FAILURE);
}
int getip(char* saveto, const struct sockaddr* from)
{
struct sockaddr_in* from_in;
from_in=(struct sockaddr_in*)from;
//    saveto[0]=from_in->sin_addr.S_un.S_un_b.s_b1);
//    saveto[1]='.';
//    saveto[2]=from.sa_data[1];
//    saveto[3]='.';
//    saveto[4]=from.sa_data[2];
//    saveto[5]='.';
//    saveto[6]=from.sa_data[3];
//    saveto[7]=':';
//    saveto[8]=from.sa_data[4];
//    saveto[9]=0;
return 0;
}
int main()
{

// myfile.open("data.txt", fstream::app);


WSADATA wsaData;
int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
if (iResult != NO_ERROR) {
    wprintf(L"WSAStartup failed with error: %ld\n", iResult);
    return 1;
}
//Inicializálás
SOCKET master_sock, slave_sock;
int flag;

unsigned int queue_size=1;
char server_ip[]="127.0.0.1";
short int server_port=1234;

struct sockaddr* addr;
struct sockaddr_in addr_in;
struct sockaddr client_addr;
char client_ip[10];
char buff[1024];

master_sock=socket(PF_INET,SOCK_STREAM,0);
if(master_sock<0)
    handle_error("Socket letrehozas");

//Címösszeállítás
addr_in.sin_family=AF_INET;
addr_in.sin_port=htons(server_port);
addr_in.sin_addr.s_addr=inet_addr(server_ip);
addr=(struct sockaddr*)&addr_in;

//Figyelés
flag=bind(master_sock,addr,sizeof(*addr));
if(flag<0)
    handle_error("Bind");
flag=listen(master_sock, queue_size);
if(flag<0)
    handle_error("Listen");
printf("A szerver kesz, kapcsolatra var - %s:%d\n", server_ip, server_port);

int cntr=1;

while(!kbhit())
{
//Fogadás
    slave_sock=accept(master_sock, &client_addr, NULL);
    if(slave_sock<0)
        handle_error("Accept");
    //getip(client_ip, &client_addr);
    printf("%d. Kapcsolat fogadva.\n",cntr);
    flag=1;

    do{
        flag=recv(slave_sock, buff, sizeof(buff), 0);
        if(buff[0] == 'c' | flag == -1)
        {
            printf("waiting to an other connection!\n");
        } else {
            buff[flag]=0;
            printf("Most erkezett: %s \n",buff);

            //puts(buff);
            send(slave_sock,buff, sizeof(buff), 0);
        }
    } while(flag > 0);

    closesocket(slave_sock);
    cntr++;
}

//Lezárás
closesocket(master_sock);
printf("socket clodes exiting");

WSACleanup();
//myfile.close();
// getchar();
return 0;
}
