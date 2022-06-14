// CMakeProject1.cpp : Defines the entry point for the application.
//

 #include "CMakeProject1.h"
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
    WSADATA wsaData;
    int iResult;


    if (WSAStartup(0x0600, &wsaData) != 0) {
        fprintf(stderr, "Could not open Windows connection.\n");
        exit(0);
    }

    int sock = 0, valread, client_fd;
    struct sockaddr_in serv_addr;
    char* hello = "Hello from client";
    char buffer[1024] = { 0 };
    int recvbuflen = strlen(buffer) + 1;
    if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    // Initialize Winsock
    
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed: %d\n, iResult");
        return -1;
    }

    // Create a SOCKET for connecting to server
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == INVALID_SOCKET) {
        printf("Error at socket(): %ld\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(PORT);



    // Connetct to server.
    iResult = connect(sock, (SOCKADDR*)&client_fd, sizeof(client_fd));
    if (iResult == SOCKET_ERROR) { 
        closesocket(sock);
        printf("Unable to connect to server: %ld\n", WSAGetLastError());
        WSACleanup();
        return -1;
    }
    /*Shutdown connection since no more data will be sent*/
    iResult = shutdown(sock, SD_SEND);
    if (iResult == SOCKET_ERROR) {
        printf("shutdown failed: %d\n", WSAGetLastError());
        closesocket(sock);
        WSACleanup();
        return 1;
    }
    /*Receive until the connection close*/
    do {

        iResult = recv(sock, buffer, recvbuflen, 0);
        if (iResult > 0)
            printf("Bytes received: %d\n", iResult);
        else if (iResult == 0)
            printf("Connection closed\n");
        else
            printf("recv failed: %d\n", WSAGetLastError());

    } while (iResult > 0);

    // cleanup
    closesocket(sock);
    WSACleanup();

    return 0;
}
   

