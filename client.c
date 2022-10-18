/*
    Authors: John Winward and Ben Chernin
    Date: 10/17/2022
    Desc: Assignment for CPSC 445: Networking
*/

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

    serverName.sin_family = AF_INET;
    serverName.sin_port = htons(port);

    //Locate server
    if((inet_pton(AF_INET, argv[1], &serverName.sin_addr.s_addr)) < 0)
    {
        perror("Error: invalid address");
        exit(EXIT_FAILURE);
    }

    //Connect to server
    if(connect(s, (struct sockaddr *) &serverName, sizeof(serverName)) < 0)
    {
        perror("Failed to connect to server");
        exit(EXIT_FAILURE);
    }
    
    //Read in message
    printf("Begin typing message (CTRL D to send): ");
    while(1){
        *clntMes_p = getchar();
        if(*clntMes_p == EOF){
            break;
        }
        clntMes_p++;
    }
    *clntMes_p = '\0';

    //Sends message to server
    send(s, clntMes, strlen(clntMes), 0);

    //Receive and display message from server
    if(recv(s, servMes, sizeof(servMes), 0) < 0)
    {
        printf("No message received.\n");
    }
    else
    {
        printf("\n%s\n", servMes);
    }

    //Close socket
    shutdown(s, 2);

    return 0;
}