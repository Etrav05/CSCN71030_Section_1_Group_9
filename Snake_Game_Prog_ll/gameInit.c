#include "gameInit.h"

void gameInitial() { // THIS IS JUST SUPER BASIC GAME INIT STUFF!!! THIS WILL BE THE DEFAULT :D
	int x, y;
	int width = 20;
	int height = 10;
	int key, gameOver = 0;
	int highScore = 0;
	int started = 0;
	int difficulty = 0;

	PSNAKENODE head = initialSize();
	x = height / 2;
	y = width / 2; 
	highScore = readHighScore;
	placeApple(head);
}

