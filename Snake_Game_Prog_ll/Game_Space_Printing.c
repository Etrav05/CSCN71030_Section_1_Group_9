#include "Game_Space_Printing.h"
#include "main.h"

int snakeLength = 0;

char grid[GRID_HEIGHT][GRID_WIDTH];

void setCursorPosition(int x, int y) {      // this is a function made by windows to set a position to redraw an output from
	COORD coord = { (SHORT)x, (SHORT)y };  // rather than completly clear and redraw it (fixes the flickering issue)
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void hideCursor() { // another windows made function to hide the cursor while redrawing the terminal
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); // get the handle to the standard output (console)

	CONSOLE_CURSOR_INFO cursorInfo; // define the cursor info structure
	GetConsoleCursorInfo(consoleHandle, &cursorInfo);

	cursorInfo.bVisible = 0; // set the cursor visibility to false (hide the cursor) --> 0 = false, 1 = true

	SetConsoleCursorInfo(consoleHandle, &cursorInfo); // apply the changes
}

void initializeGrid() { // create a 2D array to represent the grid + hold its values
    for (int y = 0; y < GRID_HEIGHT; y++) {
        for (int x = 0; x < GRID_WIDTH; x++) {
            if (y == 0 || y == GRID_HEIGHT - 1 || x == 0 || x == GRID_WIDTH - 1) { // create the walls and empty space
                grid[y][x] = 'W'; // wall

            }
            else {
                grid[y][x] = ' '; // empty space
            }
        }
    }
}

void placeSnake(PSNAKENODE head) { // put the snake nodes on the grid
    PSNAKENODE current = head;

    while (current != NULL) { // until the end of the snake
        if (current == head) {
            grid[current->data.y][current->data.x] = 'O'; // head
        }
        else {
            grid[current->data.y][current->data.x] = 'o'; // body
        }
        current = current->next; // move to the next node
    }
}

void clearSnake(PSNAKENODE head) { // as the snake moves, clear its old positions
    PSNAKENODE current = head;

    while (current != NULL) {
        grid[current->data.y][current->data.x] = ' '; // for each position the snake was on, replace it with a blank space
        current = current->next;
    }
}

void placeAppleOnGrid(int appleX, int appleY) {
    grid[appleY][appleX] = '@';
}

void printGrid(PSNAKENODE head) {
    setCursorPosition(0, 0); // set cursor to the top-left corner
    hideCursor();
    
    initializeGrid();

    placeSnake(head);

    placeAppleOnGrid(appleX, appleY);

    for (int y = 0; y < GRID_HEIGHT; y++) { // print each element of the 2D grid
        for (int x = 0; x < GRID_WIDTH; x++) {
            if (grid[y][x] == 'W') // W's are stored as a flag to track walls
                printf("#");

            else
                printf("%c", grid[y][x]);
        }
        printf("\n");
    }

    printf("X: %d, Y: %d", appleX, appleY);
}