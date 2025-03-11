#include "Snake_Initalization.h"
#include "Game_Space_Printing.h"
#include "Main.h"

// Evan T
// Yash B
// Liv G
// Austin F

int x, y;

// Dont change this often
int main() {
    
    int startX = 10, startY = 5, length = 4; // take out and put in game_initailization
    PSNAKENODE head = initialSize(startX, startY, length);

    x = startX; // set the head position (x, y)
    y = startY;

    printGrid(head); // print the grid

    freeSnake(head); // free the snake linked list
	return 0;
}