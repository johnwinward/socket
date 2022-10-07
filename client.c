#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <stdio.h>


int main(int argc, const* argv[])
{
    char serverName[16];
    int serverPort = 0;

    printf("Enter server IP address: /n");
    scanf("%s", serverName);
    printf("/n");

    printf("Enter server port number: /n");
    scan("%d", serverPort);
    printf("/n");

    printf("The IP address you entered is %s.", serverName);
    printf("The port number you entered is %s.", serverPort);

    return 0;
}