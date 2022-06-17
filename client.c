#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_INPUT 50

#define PORT 8080
#define IP "0.0.0.0"

static void readInput(char * buffer);
 
int main(int argc, char const* argv[]){

    int socketFd = 0; 
    struct sockaddr_in address;

    socketFd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketFd < 0) {
        printf("Error creando el socket\n");
        return -1;
    }
 
    address.sin_family = AF_INET;
    address.sin_port = htons(PORT);
 
    if (inet_pton(AF_INET, IP, &address.sin_addr) <= 0) {
        printf("Direccion Invalida\n");
        return -1;
    }
 
    if (connect(socketFd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        printf("Error en la conexion \n");
        return -1;
    }

    char buffer[MAX_INPUT];
    int s = 1;
    while(s > 0){
        readInput(buffer);
        //printf("Ingresaste: %s\n", buffer);
        s = send(socketFd, buffer, strlen(buffer), 0);
    }
 
    return 0;
}

static void readInput(char * buffer){
    char c;
    int read = 0;
    while (((c = getchar()) != '\n') && read < MAX_INPUT){
        buffer[read++] = c;
    }
    buffer[read++] = '\n';
    buffer[read] = 0;
}