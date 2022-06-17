#include "game.h"

int (*challenges[CHALLENGE_COUNT])(void);
char * correctAnswers[CHALLENGE_COUNT];
char * buffer[BUFFER_SIZE];

static void loadChallenges();
static void loadCorrectAnswers();
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


void startChallenges(){
    loadChallenges();
    loadCorrectAnswers();
}

static void loadChallenges(){
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

static void loadCorrectAnswers(){
    correctAnswers[0] = ANSWER_1;
    correctAnswers[1] = ANSWER_2;
    correctAnswers[2] = ANSWER_3;
    correctAnswers[3] = ANSWER_4;
    correctAnswers[4] = ANSWER_5;
    correctAnswers[5] = ANSWER_6;
    correctAnswers[6] = ANSWER_7;
    correctAnswers[7] = ANSWER_8;
    correctAnswers[8] = ANSWER_9;
    correctAnswers[9] = ANSWER_10;
    correctAnswers[10] = ANSWER_11;
    correctAnswers[11] = ANSWER_12;
}



void challenge(int index){
    system("clear");
    printf(CHALLENGE_MSG);
    challenges[index]();
}

int checkAnswer(int challengeNumber, char * answer){
    if (strcmp(correctAnswers[challengeNumber], answer) != 0){
        printf("\nRespuesta incorrecta: %s\n", answer);
        printf("EXPECTED: %s\n", correctAnswers[challengeNumber]);
        return FAILED;
    }


    return SUCCESS;
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