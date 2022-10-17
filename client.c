#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <stdio.h>
#include <netinet/in.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    uint16_t port = (uint16_t) atoi(argv[2]);
    char clntMes[200000];
    char *clntMes_p = clntMes;
    struct sockaddr_in serverName;
    int s;
    char servMes[200000];

    //Create socket
    if((s = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("Error: could not create socket");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("Socket created.\n");
    }

    serverName.sin_family = AF_INET;
    serverName.sin_port = htons(port);

    //Locate server
    if((inet_pton(AF_INET, argv[1], &serverName.sin_addr.s_addr)) < 0)
    {
        perror("Error: invalid address");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("Server located.\n");
    }

    //Connect to server
    if(connect(s, (struct sockaddr *) &serverName, sizeof(serverName)) < 0)
    {
        perror("Failed to connect to server");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("Connection established.\n");
    }
    
    //Read in message
    printf("Begin typing message (CTRL D to send):\n");
    while((*clntMes_p = getchar()) != EOF){
        clntMes_p++;
    }
    *clntMes_p = '\0';

    //Sends message to server
    send(s, clntMes, strlen(clntMes), 0);
    printf("\nMessage sent.\n");

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