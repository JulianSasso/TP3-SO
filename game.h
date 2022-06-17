#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <stdlib.h>
#define MAX 12

#define CHALLENGE_MSG "------------- DESAFIO -------------\n"
#define QUESTION_MSG "----- PREGUNTA PARA INVESTIGAR -----\n"

void loadChallenges();

int challenge(int index);

#endif