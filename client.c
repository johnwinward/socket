#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <stdio.h>
#include <netinet/in.h>

#define PORT 54640


int main(int argc, char* argv[])
{
    uint16_t port = (uint16_t) atoi(argv[2]);
    char clntMes[34] = "This is the client! Hello server!";
    //int serverPort = 0;
    struct sockaddr_in serverName;
    int s;
    char servMes[200000];

    //Create socket
    if((s = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("Error: could not create socket.\n");
        return -1;
    }
    else
    {
        printf("Socket created.\n");
    }

    serverName.sin_family = AF_INET;
    serverName.sin_port = htons(port);

    //Locate server
    //No IP address entered yet
    printf("%s\n", argv[1]);
    if((inet_pton(AF_INET, argv[1], &serverName.sin_addr.s_addr)) < 0)
    {
        printf("Error: invalid address.\n");
        return -1;
    }
    else
    {
        printf("Server located.\n");
    }

    //Connect to server
    if(connect(s, (struct sockaddr *) &serverName, sizeof(serverName)) < 0)
    {
        printf("Error: failed to connect.\n");
    }
    else
    {
        printf("Connection established.\n");
    }

    //Sends message to server
    send(s, clntMes, strlen(clntMes), 0);
    printf("Message sent.\n");

    //Receive and display message from server
    if(recv(s, servMes, sizeof(servMes), 0) < 0)
    {
        printf("No message received.\n");
    }
    else
    {
        printf("%s\n", servMes);
    }

    //Close socket
    shutdown(s, 2);

    return 0;
}