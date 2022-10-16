FROM gcc:latest

COPY . /usr/src/myapp
WORKDIR /usr/src/myapp
RUN gcc -o server server.c
CMD ["./server", "8080"]