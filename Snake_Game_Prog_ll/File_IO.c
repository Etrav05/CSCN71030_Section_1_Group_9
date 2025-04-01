// File_IO.c
#define _CRT_SECURE_NO_WARNINGS
#include "File_IO.h"
#include "main.h"

int readHighScore() {
    FILE* file = fopen("highscore.txt", "r");
    int score = 0;
    if (file) {
        fscanf(file, "%d", &score);
        fclose(file);
    }
    return score;
}

void saveHighScore(int score) {
    FILE* file = fopen("highscore.txt", "w");
    if (file) {
        fprintf(file, "%d", score);
        fclose(file);
    }
}

void printScore(int highScore) {
    printf("Score:       %d     \nHigh Score:  %d", (snakeLength * 100 - 100), highScore); // Display high score
}