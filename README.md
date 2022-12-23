# socket
Programming Assignment for CPSC 445: Networking

To start, compile client.c on one machine and server.c on another machine, with one machine being the client and one being the server.

On the server machine, start the server application in bash, giving the listening port number as an agrument (ex: ./server 54321)

On the client, start the client application and give the server's IPv4 address and port to connect to (ex: ./client 192.168.1.5 54321)

This will establish a connection. Once connected, the client can type a message to be sent to and displayed on the server machine. To end message typing and initiate sending, use EOF (CTRL-D on Linux). If nothing happens, use EOF again.
