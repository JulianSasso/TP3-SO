#include "game.h"

int (*challenges[MAX])(void);
char * buffer[BUFFER_SIZE];

static int challenge1();
static int challenge2();
static int challenge3();
static int challenge4();
static int challenge5();
static int challenge6();
static int challenge7();
static int challenge8();
static int challenge9();
static int challenge10();
static int challenge11();
static int challenge12();

static int checkAnswer(char * correctAnswer, char * answer);


void loadChallenges(){
    challenges[0] = &challenge1;
    challenges[1] = &challenge2;
    challenges[2] = &challenge3;
    challenges[3] = &challenge4;
    challenges[4] = &challenge5;
    challenges[5] = &challenge6;
    challenges[6] = &challenge7;
    challenges[7] = &challenge8;
    challenges[8] = &challenge9;
    challenges[9] = &challenge10;
    challenges[10] = &challenge11;
    challenges[11] = &challenge12;
}

int challenge(int index){
    system("clear");
    printf(CHALLENGE_MSG);
    return challenges[index]();
}

static int checkAnswer(char * correctAnswer, char * answer){
    if (strcmp(correctAnswer, answer) != 0){
        printf("\nRespuesta incorrecta: %s\n", answer);
        return 0;
    }
    return 1;
}

static int challenge1(){
    return 0;
}

static int challenge2(){
    return 0;
}

static int challenge3(){
    return 0;
}

static int challenge4(){
    return 0;
}

static int challenge5(){
    return 0;
}

static int challenge6(){
    return 0;
}

static int challenge7(){
    return 0;
}

static int challenge8(){
    return 0;
}

static int challenge9(){
    return 0;
}

static int challenge10(){
    return 0;
}

static int challenge11(){
    return 0;
}

static int challenge12(){
    return 0;
}