#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <fcntl.h>
#include <arpa/inet.h>

#include "game.h"

#define PORT 8080
#define IP "0.0.0.0"
#define MAX_INPUT 50

static int getUserInput(int fd, char * buffer);

int main(int argc, char const* argv[]) {

    int serverFd, clientFd;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    int opt = 1;
 
    // Creamos el fd del socket
    if ((serverFd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        return -1;
    }
 
    // Conectamos el socket al puerto 8080
    if (setsockopt(serverFd, SOL_SOCKET, SO_REUSEPORT, &opt, sizeof(opt)) == -1) {
        perror("setsockopt");
        return -1;
    }

    address.sin_family = AF_INET;
    address.sin_port = htons(PORT);
    inet_pton(AF_INET, IP, &address.sin_addr);
 
    if (bind(serverFd, (struct sockaddr *) &address, addrlen) < 0) {
        perror("bind failed");
        return -1;
    }

    if (listen(serverFd, 1) < 0) {
        perror("listen");
        return -1;
    }
    if ((clientFd = accept(serverFd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
        perror("accept");
        return -1;
    }

    startChallenges();
    for (int i = 0; i < CHALLENGE_COUNT; i++){
        challenge(i);
        int result = FAILED;
        char buffer[MAX_INPUT];
        while (result == FAILED){
            if(getUserInput(clientFd, buffer) < 0)
                return 0;
            result = checkAnswer(i, buffer);
        }
    }

    // closing the connected socket
    close(clientFd);
    //close(serverFd);

    // closing the listening socket
    shutdown(serverFd, SHUT_RDWR);
    
    return 0;
}

static int getUserInput(int fd, char * buffer){
    int r = read(fd, buffer, MAX_INPUT);
    if(r <= 0)
        return -1;

    buffer[r] = 0;
    return 1;
}