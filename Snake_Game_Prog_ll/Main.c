#include "Snake_Initalization.h"
#include "Game_Space_Printing.h"
#include "Input_Acceptance.h"
#include "Snake_Collision.h"
#include "Apple_Placement.h"
#include "Snake_Movement.h"
#include "File_IO.h"
#include "menus.h"
#include "main.h"

// Evan T
// Yash B
// Liv G
// Austin F

int x, y;
int width = 20;
int height = 10;
int key, gameOver = 0;
int highScore = 0;
int started = 0;
int difficulty = 0;
int replay = 0;
int play = 1;
char gameStart[20];

int main(int argc, char* argv[]) {
    printf("Enter here (Start Snake): ");
    fgets(gameStart, sizeof(gameStart), stdin); // get the whole input of the user (not just the first word)

    gameStart[strcspn(gameStart, "\n")] = '\0';         // remove any endline symbols 
    if (argc < 2 || strcmp(argv[1], gameStart) != 0) { // only start after the user has entered the command line arg
        printf("Invalid start command\n");
        return 1;
    }

    while (play == 1) { // main menu
        runMenu();

        while (started == 1) { // initialize game
            PSNAKENODE head = initialSize(); // create snake
            highScore = readHighScore();    // load highscore
            placeApple(head);              // place the first apple on the grid
            gameOver = 0;
            key = 0;
            
            while (!gameOver) { // game loop
                input();                      // accept input
                movementLogic(&head);        // translate input to movement
                collision(&head);           // detect collision
                printGrid(head);           // print the grid and its elements
                printScore(highScore);    // print score/highscore below grid
                Sleep(difficulty);       // wait
            } 

            if (snakeLength * 100 - 100 > readHighScore())
                saveHighScore(snakeLength * 100 - 100);

            int choice = gameOverScreen();
            freeSnake(head); // free snake before user replays

            if (choice == 1) {
                started = 0;
            }
        }

        // play = 0;
    }
    return 0;
}