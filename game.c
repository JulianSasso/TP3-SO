#include "game.h"

void (*challenges[CHALLENGE_COUNT])(void);
char * correctAnswers[CHALLENGE_COUNT];
char * buffer[BUFFER_SIZE];

static void loadChallenges();
static void loadCorrectAnswers();
static void challenge1();
static void challenge2();
static void challenge3();
static void challenge4();
static void challenge5();
static void challenge6();
static void challenge7();
static void challenge8();
static void challenge9();
static void challenge10();
static void challenge11();
static void challenge12();


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

static void challenge1(){
    printf(CHALLENGE_1);
    printf(QUESTION_MSG);
    printf(QUESTION_1);
}

static void challenge2(){
    printf(CHALLENGE_2);
    printf(QUESTION_MSG);
    printf(QUESTION_2);
}

static void challenge3(){
    printf(CHALLENGE_3);
    printf(QUESTION_MSG);
    printf(QUESTION_3);
}

static void challenge4(){
    printf(CHALLENGE_4);
    printf(QUESTION_MSG);
    printf(QUESTION_4);

    char * rta = "La respuesta es fk3wfLCm3QvS";
    if(write(FD, rta, strlen(rta)) == -1){
        perror("Error in write fd 13");
        return;
    }
}

static void challenge5(){
    printf(CHALLENGE_5);
    printf(QUESTION_MSG);
    printf(QUESTION_5);
}

static void challenge6(){
    printf(CHALLENGE_6);
    printf(QUESTION_MSG);
    printf(QUESTION_6);
}

static void challenge7(){
    printf(CHALLENGE_7);
    printf(QUESTION_MSG);
    printf(QUESTION_7);
}

static void challenge8(){
    printf(CHALLENGE_8);
    printf(QUESTION_MSG);
    printf(QUESTION_8);
}

static void challenge9(){
    printf(CHALLENGE_9);
    printf(QUESTION_MSG);
    printf(QUESTION_9);
}

static void challenge10(){
    printf(CHALLENGE_10);
    printf(QUESTION_MSG);
    printf(QUESTION_10);

    char c;
    do {
        system("gcc quine.c -o quine -Wall -pedantic -std=c99");
        system("./quine > quine.txt");

        int fdSource = open("quine.c", O_RDONLY);
        char bufferSource[1024];
        int r = read(fdSource, bufferSource, 1024);
        bufferSource[r] = 0;

        int fdOutput = open("quine.txt", O_RDWR);
        char bufferOutput[1024];
        r = read(fdOutput, bufferOutput, 1024);
        // El archivo se escribe con \n al final
        bufferOutput[r-1] = 0;

        int result = strcmp(bufferSource, bufferOutput);
        system("rm quine quine.txt");

        if(result == 0){
            printf("\nLa respuesta es: chin_chu_lan_cha\n");
            break;
        }

        printf("Presiona ENTER para reintentar\n");        
    } while((c = getchar()) == '\n');    
}

static void challenge11(){
    printf(CHALLENGE_11);
    printf(QUESTION_MSG);
    printf(QUESTION_11);
}

static void challenge12(){
    printf(CHALLENGE_12);
    printf(QUESTION_MSG);
    printf(QUESTION_12);
}