// UDP_Server_final.cpp : Defines the entry point for the application.
//

#include "UDP_Server_final.h"
#include <stdlib.h>
#include <winsock2.h>
#include <ws2def.h>
#include <WS2tcpip.h>

#define _WIN32_WINNT 0x0600
#define PORT 8080
#define MAXLINE 1024
#pragma comment (lib, "Ws2_32.lib")

int main(int argc, char const* argv[])
{
    /*Connect to windows*/
        WSADATA wsaData;
            int iResult;
            if (WSAStartup(0x0600, &wsaData) != 0) {
            fprintf(stderr, "Could not open Windows connection.\n");
            exit(0);
            }
 /*Socket structure*/
        SOCKET serverSocket;
            struct sockaddr_in servaddr, cliaddr;
            char buffer[1024];
            char* hello = "Hello from server";
     //int recvbufflenght = strlen(buffer) + 1
                if (serverSocket = socket(AF_INET, SOCK_DGRAM, 0)) {
                printf("\n Socket creation error \n");
                return -1;
                }

 /*WSAStartup failure check*/
                iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
                if (iResult != 0) 
                {
                printf("WSAStartup failed: %d\n", iResult );
                return -1;
                }
/*Creating socket file descriptor*/
                serverSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

/*Socket failure check*/
                serverSocket = socket(AF_INET, SOCK_DGRAM, 0);
                if (serverSocket == INVALID_SOCKET) 
                {
                    printf("Error at socket(): %ld\n", WSAGetLastError());
                    WSACleanup();
                    return 1;
                }
    else {
        //call to socket() succeeded
    }

    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));

    // Filling server information
    servaddr.sin_family = AF_INET; // IPv4
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(PORT);
   

    // Bind the socket with the server address
    if (bind(serverSocket, (const struct sockaddr*)&servaddr,
        sizeof(servaddr)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    int len, n;

    len = sizeof(cliaddr);  //len is value/result

    n = recvfrom(serverSocket, (char*)buffer, MAXLINE,
        MSG_WAITALL, (struct sockaddr*)&cliaddr,
        &len);
    buffer[n] = 0;
    printf("Client : %s\n", buffer);
    sendto(serverSocket, (const char*)hello, strlen(hello),
        0, (const struct sockaddr*)&cliaddr,
        len);
    printf("Hello message sent.\n");

    return 0;
}
