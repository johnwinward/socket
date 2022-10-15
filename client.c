#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <stdio.h>


int main(int argc, char* argv[])
{
    char* clntMes = "This is the client! Hello server!";
    int serverPort = 0;
    struct sockaddr_in serverName;
    int s = 0;

    //Gather and display user input
    // printf("Enter server IP address: \n");
    // scanf("%s", serverName);
    // printf("\n");

    // printf("Enter server port number: \n");
    // scanf("%d", &serverPort);
    // printf("\n");

    // printf("The IP address you entered is %s.", serverName);
    // printf("The port number you entered is %d.", serverPort);
    // printf("\n")

    //Create socket
    if((s = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("Error: could not create socket.");
        return -1;
    }
    else
    {
        printf("Socket created.");
    }

    serverName.sin_family = AF_INET;

    return 0;
}