#include "Snake_Initalization.h"
#include "Game_Space_Printing.h"
#include "Input_Acceptance.h"
#include "Snake_Collision.h"
#include "Snake_Movement.h"
#include "menus.h"
#include "main.h"
#include "Apple_Placement.h"
#include "File_IO.h"

// Evan T
// Yash B
// Liv G
// Austin F

// could be moved to a game initialization function
int x, y;
int width = 20;
int height = 10;
int key, gameOver = 0;
int highScore = 0;
int started = 0;
int difficulty = 0;

// Dont change this often
int main() {
    PSNAKENODE head = initialSize();
    x = height / 2; // set the head position (x, y)
    y = width / 2;

    highScore = readHighScore(); // Load high score from file

    placeApple(head); // Place the first apple on the grid

    runMenu();

    if (started == 1) {
        while (!gameOver) {
            input(); // accept input
            movementLogic(&head);
            collision(&head);
            printGrid(head); // print the grid
            printf("High Score: %d\n", highScore); // Display high score
            Sleep(difficulty);
        }

        if (snakeLength > highScore) {
            saveHighScore(snakeLength); // Save new high score
            printf("New High Score! %d\n", snakeLength);
        }  
    }

    freeSnake(head); // free the snake linked list
    return 0;
}