#include "Apple_Placement.h"
#include "main.h"
#include <stdlib.h>
#include <conio.h>

int appleX, appleY;

void placeApple(PSNAKENODE head) {
    static int seeded = 0;
    if (!seeded) {
        srand(time(NULL));
        seeded = 1;
    }

    int validPosition;
    do {
        validPosition = 1;
        appleX = (rand() % (width - 2)) + 1;  // Ensures 1 to width-2
        appleY = (rand() % (height - 2)) + 1; // Ensures 1 to height-2

        // Ensure apple does not spawn inside the snake
        PSNAKENODE current = head;
        while (current != NULL) {
            if (current->data.x == appleX && current->data.y == appleY) {
                validPosition = 0;
                break;
            }
            current = current->next;
        }
    } while (!validPosition);
}

