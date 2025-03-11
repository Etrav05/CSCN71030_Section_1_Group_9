#include "Snake_Initalization.h"
#include "Game_Space_Printing.h"
#include "Input_Acceptance.h"
#include "Snake_Movement.h"
#include "main.h"

// Evan T
// Yash B
// Liv G
// Austin F

int x, y;

int key = 0;

// Dont change this often
int main() {
    
    int startX = 10, startY = 5, length = 4; // take out and put in game_initailization
    PSNAKENODE head = initialSize(startX, startY, length);

    x = startX; // set the head position (x, y)
    y = startY;

    while (1) {
        input();        // accept input
        printGrid(head); // print the grid
        movementLogic(&head, key);
        Sleep(100);
    }

    freeSnake(head); // free the snake linked list
	return 0;
}