FROM gcc:latest

COPY . /usr/src/myapp
WORKDIR /usr/src/myapp
RUN gcc -o client client.c
CMD ["./client", "0.0.0.0", "8080"]