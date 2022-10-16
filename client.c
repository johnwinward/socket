#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <stdio.h>

#define PORT 54640


int main(int argc, char* argv[])
{
    char* clntMes = "This is the client! Hello server!";
    int serverPort = 0;
    struct sockaddr_in serverName;
    int s = 0;
    char servMes[8000];

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
    serverName.sin_port = htons(PORT);

    //Connect to server
    if(connect(s, struct sockaddr *) &serverName, sizeof(serverName) < 0)
    {
        printf("Error: failed to connect.");
    }
    else
    {
        printf("Connection established.");
    }

    //Sends message to server
    send(s, clntMes, strlen(clntMes), 0);
    printf("Message sent.");

    //Receive and display message from server
    if(recv(s, servMes, sizeof(servMes), 0) < 0)
    {
        printf("No message received.");
    }
    else
    {
        printf("%s\n", servMes);
    }

    //Close socket
    close(s);

    return 0;
}