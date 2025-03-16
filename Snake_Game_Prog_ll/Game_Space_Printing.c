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
    setCursorPosition(0, 0); // Set cursor to the top-left corner
    hideCursor();

    for (int i = 0; i < WIDTH / 2 + 2; i++) { // Print top border
        printf("[]");
    }
    printf("\n");

    for (int i = 0; i < HEIGHT; i++) { // Print elements of the grid
        printf("[]"); // Left wall

        for (int j = 0; j < WIDTH; j++) {
            int tailPtr = 0; // Flag to check if a tail section was printed
            int k = 0;
            PSNAKENODE current = head;

            while (current != NULL) {
                if (current->data.x == j && current->data.y == i) {
                    if (k == 0)
                        printf("O"); // Snake head
                    else if (k != snakeLength - 1)
                        printf("c"); // Snake body parts
                    else
                        printf("o"); // Snake tail
                    tailPtr = 1; // Set flag to indicate a tail section was printed
                    break; // Exit loop once a body part is found
                }
                current = current->next;
                k++;
            }

            // Print Apple if it's at this position
            if (j == appleX && i == appleY) {
                printf("@"); // Apple symbol
                tailPtr = 1; // Ensure empty space is not printed over it
            }

            if (!tailPtr) { // If nothing else was printed, print a blank space
                printf(" ");
            }
        }
        printf("[]\n"); // Right wall
    }

    for (int i = 0; i < WIDTH / 2 + 2; i++) { // Print bottom border
        printf("[]");
    }
    printf("\n");
}
