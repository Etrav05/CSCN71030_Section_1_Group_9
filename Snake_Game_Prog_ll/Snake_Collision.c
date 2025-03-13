#include "Snake_Collision.h"
#include "main.h"

void collision(PSNAKENODE* list) {
	PSNAKENODE current = *list;

	if (current->data.x < 0 || current->data.x >= width || current->data.y < 0 || current->data.y >= height) { // gameover hitting walls
		gameOver = 1;
	}

	int headX = current->data.x;
	int headY = current->data.y;

	PSNAKENODE body = current->next;

	for (int i = 1; i < snakeLength; i++) {
		if (headX == body->data.x && headY == body->data.y) {
			gameOver = 1;
			return;
		}

		body = body->next;
	}
}