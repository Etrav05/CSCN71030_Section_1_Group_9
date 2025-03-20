#include "Apple_Placement.h"
#include "main.h"
#include <stdlib.h>
#include <conio.h>

int appleX, appleY;

void placeApple(PSNAKENODE head) {
    srand(time(NULL));

    int validPosition;
    do {
        validPosition = 1;
        appleX = (rand() % (GRID_WIDTH - 2) + 1);
        appleY = (rand() % (GRID_HEIGHT - 2) + 1);

        // Ensure the apple does not spawn inside the snake
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
