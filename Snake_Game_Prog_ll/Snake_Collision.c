#include "Snake_Collision.h"
#include "main.h"
#include "Apple_Placement.h" // Include Apple header file

void collision(PSNAKENODE* list) {
    PSNAKENODE current = *list;

    // Check for wall collision (Game Over)
    if (current->data.x < 1 || current->data.x >= GRID_WIDTH - 1 || current->data.y < 1 || current->data.y >= GRID_HEIGHT - 1) {
        gameOver = 1;
    }

    int headX = current->data.x;
    int headY = current->data.y;

    PSNAKENODE body = current->next;

    // Check for self-collision (Game Over)
    for (int i = 1; i < snakeLength; i++) {
        if (headX == body->data.x && headY == body->data.y) {
            gameOver = 1;
            return;
        }
        body = body->next;
    }

    // Check if snake eats the apple
    if (headX == appleX && headY == appleY) {
        // Grow the snake
        for (int i = 0; i < 2; i++) {
            SNAKEBODY newBody = createBody(current->data.x, current->data.y); // Create new snake segment
            addNode(list, newBody); // Add new node to snake
        }

        // Place a new apple
        placeApple(*list);
    }
}
