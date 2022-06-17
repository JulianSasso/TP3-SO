#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <stdlib.h>

#define MAX 12
#define BUFFER_SIZE 1024

#define CHALLENGE_MSG "------------- DESAFIO -------------\n"
#define QUESTION_MSG "----- PREGUNTA PARA INVESTIGAR -----\n"

#define QUESTION_1  "¿Cómo descubrieron el protocolo, la dirección y el puerto para conectarse?\n"
#define QUESTION_2  "¿Qué diferencias hay entre TCP y UDP y en qué casos conviene usar cada uno?\n"
#define QUESTION_3  "¿El puerto que usaron para conectarse al server es el mismo que usan para mandar las respuestas? ¿Por qué?\n"
#define QUESTION_4  "¿Qué útil abstracción es utilizada para comunicarse con sockets? ¿se puede utilizar read(2) y write(2) para operar?\n"
#define QUESTION_5  "¿Cómo garantiza TCP que los paquetes llegan en orden y no se pierden?\n"
#define QUESTION_6  "Un servidor suele crear un nuevo proceso o thread para atender las conexiones entrantes. ¿Qué conviene más?\n"
#define QUESTION_7  "¿Cómo se puede implementar un servidor que atienda muchas conexiones sin usar procesos ni threads?\n"
#define QUESTION_8  "¿Qué aplicaciones se pueden utilizar para ver el tráfico por la red?\n"
#define QUESTION_9  "sockets es un mecanismo de IPC. ¿Qué es más eficiente entre sockets y pipes?\n"
#define QUESTION_10  "¿Cuáles son las características del protocolo SCTP?\n"
#define QUESTION_11  "¿Qué es un RFC?\n"
#define QUESTION_12  "¿Fue divertido?\n"

#define END_MSG "Felicitaciones, finalizaron el juego. Ahora deberán implementar el servidor que se comporte como el servidor provisto\n"

void loadChallenges();

int challenge(int index);

#endif