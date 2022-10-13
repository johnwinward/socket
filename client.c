#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <stdio.h>


int main(int argc, char const* argv[])
{
    char serverName[16];
    char* clntMes = "This is the client! Hello server!";
    int serverPort = 0;
    int s = 0;

    printf("Enter server IP address: \n");
    scanf("%s", serverName);
    printf("\n");

    printf("Enter server port number: \n");
    scanf("%d", &serverPort);
    printf("\n");

    printf("The IP address you entered is %s.", serverName);
    printf("The port number you entered is %d.", serverPort);
    printf("\n")

    if((s = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("Error: could not create socket.");
        return -1;
    }

    return 0;
}