#include "Game_Space_Printing.h"
#include "main.h"

int snakeLength = 0;

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

void printGrid(PSNAKENODE head) {
    setCursorPosition(0, 0); // set cursor to the top-left corner

    for (int i = 0; i < WIDTH / 2 + 2; i++) { // print the top border
        printf("[]");
    }
    printf("\n");

    for (int i = 0; i < HEIGHT; i++) { // print elements of the grid
        printf("[]"); // left walls

        for (int j = 0; j < WIDTH; j++) {
            if (j == x && i == y) { // snake head
                printf("O");
            }

            else {
                int tailPtr = 0; // flag to check if a tail section was printed
                PSNAKENODE current = head;
                int k = 0;

                while (current != NULL) {
                    if (current->data.x == j && current->data.y == i) {
                        if (k != snakeLength - 1) {
                            printf("c"); // snake body parts
                        }
                        else {
                            printf("o"); // snake tail
                        }
                        tailPtr = 1; // set flag to indicate a tail section was printed
                        break; // exit the loop once a body part is found
                    }
                    current = current->next;
                    k++;
                }

                if (!tailPtr) { // if nothing else was printed, print a blank space
                    printf(" ");
                }
            }
        }

        printf("[]\n"); // right walls
    }

    for (int i = 0; i < WIDTH / 2 + 2; i++) { // print the bottom border
        printf("[]");
    }
    printf("\n");
}