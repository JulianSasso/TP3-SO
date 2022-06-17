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

int main(int argc, char const* argv[]) {

    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
 
    // Creamos el fd del socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    /* int saved_flags = fcntl(server_fd, F_GETFL);
    fcntl(server_fd, F_SETFL, saved_flags & ~O_NONBLOCK); */
 
    // Conectamos el socket al puerto 8080
    if (setsockopt(server_fd, SOL_SOCKET, /* SO_REUSEADDR | */ SO_REUSEPORT, &opt, sizeof(opt)) == -1) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    //address.sin_addr.s_addr = INADDR_ANY;
    //address.sin_addr.s_addr = inet_addr("0.0.0.0");
    inet_pton(AF_INET, "0.0.0.0", &address.sin_addr);
    address.sin_port = htons(PORT);
 
    if (bind(server_fd, (struct sockaddr *) &address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // en que puerto escuchamos del cliente???
    if (listen(server_fd, 1) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    char buffer[50];
    while(1){printf("Leyendo...\n");
        if(read(new_socket, buffer, 50) < 0)
            return;
        printf("LEI: %s\n", buffer);
    }

    // juego
    loadChallenges();
    int currentChallenge = 0;

    while(currentChallenge < CHALLENGE_COUNT){

        if(challenge(currentChallenge) > 0)
            currentChallenge++;

    }
   

  // closing the connected socket
    // close(new_socket);
    close(server_fd);

  // closing the listening socket
    // shutdown(server_fd, SHUT_RDWR);
    
    return 0;
}