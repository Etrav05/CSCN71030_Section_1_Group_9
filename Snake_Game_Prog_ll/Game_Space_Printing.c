#include "Game_Space_Printing.h"
#include "menus.h"
#include "main.h"

int snakeLength = 0;
char** grid = NULL; // declare as null so we can dynamically change the size with menus

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

void initializeGrid() {
    if (grid != NULL) { // free existing grid
        for (int y = 0; y < height; y++) {
            free(grid[y]); // free row
        }
        free(grid); // free whole grid
    }

    grid = (char**)malloc(height * sizeof(char*)); // allocate memory based on the users selection
    for (int y = 0; y < height; y++) {
        grid[y] = (char*)malloc(width * sizeof(char));
    }

    for (int y = 0; y < height; y++) { // initalize this new grid size
        for (int x = 0; x < width; x++) {
            if (y == 0 || y == height - 1 || x == 0 || x == width - 1) {
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

    for (int y = 0; y < height; y++) { // print each element of the 2D grid
        for (int x = 0; x < width; x++) {
            if (grid[y][x] == 'W') // W's are stored as a flag to track walls
                printf("I"); // I |

            else if (grid[y][x] == 'O')
                printf(GRN"O"RESET);

            else if (grid[y][x] == 'o')
                printf(GRN"o"RESET);

            else if (grid[y][x] == '@')
                printf(RED"@"RESET);

            else
                printf("%c", grid[y][x]);
        }
        printf("\n");
    }
}