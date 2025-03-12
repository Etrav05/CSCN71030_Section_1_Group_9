#include "Snake_Collision.h"
#include "main.h"

void collision(PSNAKENODE* list) {
	PSNAKENODE current = *list;

	if (current->data.x < 0 || current->data.x >= width || current->data.y < 0 || current->data.y >= height) { // gameover hitting walls
		gameOver = 1;
	}
}