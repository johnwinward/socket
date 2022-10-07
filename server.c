#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>

int main(int argc, char *argv[]){
    int port;

    if(argc == 2){
        port = atoi(argv[1]);
        //Debug
        printf("Port entered: %d", port);
    }
    else{
        printf("Invalid # of arguments");
        return 1;
    }

    return 0;
}
