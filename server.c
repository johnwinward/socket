#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>

int main(int argc, char *argv[]){
    int port;
    int s;                   //Socket
    int sOpen;               //Open socket
    char msgBuff[200000];    //Message Buffer and pointer to it
    char *p_msgBuff = &msgBuff;
    char ack[18] = "Message Recieved!";
    struct sockaddr_in sAdd; //Server Address/Port
    struct sockaddr_in cAdd; //Client Address/Port

    if(argc == 2){
        port = atoi(argv[1]);
        //Debug
        printf("Port entered: %d\n", port);
    }
    else{
        printf("Invalid # of arguments\n");
        return 1;
    }
    
    //Create Socket
    if(s = socket(AF_INET, SOCK_STREAM, 0) == -1){
        printf("Failed to create socket\n");
        return 1;
    }
    
    //Bind address to socket
    sAdd.sin_family = AF_INET;
    sAdd.sin_addr.s_addr = htonl(INADDR_ANY);
    sAdd.sin_port = htons(port);
    if(bind(s, (struct sockaddr *) &sAdd, sizeof(sAdd)) == -1){
        printf("Failed to bind address to socket.\n");
        return 1;
    }
    
    //Start listening
    if(listen(s, 1) == -1){
        printf("Failure at listen()\n");
        return 1;
    }
    
    //Accept connection
    if(sOpen = accept(s, (struct sockaddr *) &cAdd, sizeof(cAdd)) == -1){
        printf("Failure at accept()\n");
        return 1;
    }
    
    //Receive message
    if(read(sOpen, p_msgBuff, sizeof(msgBuff)) == -1){
        printf("Failure at read()\n");
        return 1;
    }

    int i = 0;
    char ch = msgBuff[i];
    while(ch != "\0"){           //TODO: Change \0 to EOF
        printf("%c", ch);
        i++;
        ch = msgBuff[i];
    }
    
    //ACK message
    
    
    //Close Socket

    return 0;
}
