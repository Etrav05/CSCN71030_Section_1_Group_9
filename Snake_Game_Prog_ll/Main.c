#include "Snake_Initalization.h"
#include "Game_Space_Printing.h"
#include "Input_Acceptance.h"
#include "Snake_Collision.h"
#include "Snake_Movement.h"
#include "main.h"

// Evan T
// Yash B
// Liv G
// Austin F

// could be moved to a game initialization function
int x, y;

int width = 20;
int height = 10;

int key, gameOver = 0;

// Dont change this often
int main() {
    
    PSNAKENODE head = initialSize();

    x = height / 2; // set the head position (x, y)
    y = width / 2;

    while (!gameOver) {
        input();        // accept input
        printGrid(head); // print the grid
        movementLogic(&head);
        collision(&head);
        Sleep(100);
    }

    freeSnake(head); // free the snake linked list
	return 0;
}