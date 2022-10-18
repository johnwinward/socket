/*
    Authors: John Winward and Ben Chernin
    Date: 10/17/2022
    Desc: Assignment for CPSC 445: Networking
*/

#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]){
    uint16_t port;
    int s;                              //Socket
    int sOpen;                          //Open socket
    char msgBuff[200000];               //Message Buffer and pointer to it
    char *p_msgBuff = msgBuff;          //Pointer to Message Buffer
    char ack[31] = "Message Recieved!"; //Message to send back to client
    struct sockaddr_in sAdd;            //Server Address/Port
    struct sockaddr_in cAdd;            //Client Address/Port

    if(argc == 2){
        port = (uint16_t) atoi(argv[1]);
    }
    else{
        printf("Invalid # of arguments\n");
        return 1;
    }
    
    //Create Socket
    if((s = socket(AF_INET, SOCK_STREAM, 0)) == -1){
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }
    
    //Bind address to socket
    sAdd.sin_family = AF_INET;
    sAdd.sin_addr.s_addr = htonl(INADDR_ANY);
    sAdd.sin_port = htons(port);
    if(bind(s, (struct sockaddr *) &sAdd, sizeof(sAdd)) == -1){
       perror("Failed to bind address to socket");
       exit(EXIT_FAILURE);
    }
    
    //Start listening
    if(listen(s, 1) == -1){
        perror("Failure at listen()");
        exit(EXIT_FAILURE);
    }
    
    //Accept connection
    socklen_t cAdd_size = sizeof(cAdd);
    if((sOpen = accept(s, (struct sockaddr *) &cAdd, &cAdd_size)) == -1){
        perror("Failure at accept()");
        exit(EXIT_FAILURE);
    }
    
    //Receive message
    if(read(sOpen, p_msgBuff, sizeof(msgBuff)) == -1){
        perror("Failure at read()");
        exit(EXIT_FAILURE);
    }

    //Print Message
    printf("Message from %s:\n", inet_ntoa(cAdd.sin_addr));
    int i = 0;
    char ch = msgBuff[i];
    while(ch != '\0'){           //TODO: Change \0 to EOF
        printf("%c", ch);
        i++;
        ch = msgBuff[i];
    }
    printf("\n");
    
    //ACK message
    if(write(sOpen, (char *) &ack, sizeof(ack)) == -1){
        perror("Failure at write()");
        exit(EXIT_FAILURE);
    }
    
    //Close Socket
    shutdown(sOpen, 2);
    shutdown(s, 2);

    return 0;
}
