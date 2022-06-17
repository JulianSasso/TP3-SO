#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#define CHALLENGE_COUNT 12
#define BUFFER_SIZE 1024
#define FAILED 0
#define SUCCESS 1
#define FD 13

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

#define CHALLENGE_1  "Bienvenidos al TP3 y felicitaciones, ya resolvieron el primer acertijo.\n\nEn este TP deberán finalizar el juego que ya comenzaron resolviendo los desafíos de cada nivel.\nAdemás tendrán que investigar otras preguntas para responder durante la defensa.\nEl desafío final consiste en crear un programa que se comporte igual que yo, es decir, que provea los mismos desafíos y que sea necesario hacer lo mismo para resolverlos. No basta con esperar la respuesta.\nAdemás, deberán implementar otro programa para comunicarse conmigo.\n\nDeberán estar atentos a los easter eggs.\n\nPara verificar que sus respuestas tienen el formato correcto respondan a este desafío con la palabra 'entendido\\n'\n\n"
#define CHALLENGE_2  "The Wire S1E5\n5295 888 6288\n\n"
#define CHALLENGE_3  "https://ibb.co/tc0Hb6w\n\n"
#define CHALLENGE_4  "EBADF...\n\nwrite: Bad file descriptor\n\n"
#define CHALLENGE_5  "respuesta = strings:201\n\n"
#define CHALLENGE_6  ".init .text ? .fini .rodata\n\n"
#define CHALLENGE_7  "Filter error\n\n"
#define CHALLENGE_8  "¿?\n\n"
#define CHALLENGE_9  "Latexme\n\nSi\n\\mathrm{d}y = u^v{\\cdot}(v'{\\cdot}\\ln{(u)}+v{\\cdot}\\frac{u'}{u})\nentonces\ny =\n\n"
#define CHALLENGE_10  "quine\n\n"
#define CHALLENGE_11  "b gdbme y encontrá el valor mágico\n\n"
#define CHALLENGE_12  "Me conoces\n\n"

#define ANSWER_1  "entendido"
#define ANSWER_2  "itba"
#define ANSWER_3  "M4GFKZ289aku"
#define ANSWER_4  "fk3wfLCm3QvS"
#define ANSWER_5  "too_easy"
#define ANSWER_6  ".RUN_ME"
#define ANSWER_7  "K5n2UFfpFMUN"
#define ANSWER_8  "BUmyYq5XxXGt"
#define ANSWER_9  "u^v"
#define ANSWER_10  "chin_chu_lan_cha"
#define ANSWER_11  "gdb_rules"
#define ANSWER_12  "normal"

#define END_MSG "\nFelicitaciones, finalizaron el juego. Ahora deberán implementar el servidor que se comporte como el servidor provisto\n\n"

void startChallenges();
void challenge(int index);
int checkAnswer(int challengeNumber, char * answer);

#endif