#include "Input_Acceptance.h"
#include "main.h"
#include <ctype.h>

int key, gameOver;

int input() { // accept inputs and set them to a key value
	if (_kbhit()) { // changed this to IF so it only checks once every cycle (fixing the issue of multi-input)
		switch (tolower(getch())) {
		case 'w':
			if (key != 3)
				key = 1;
			break;
		case 'a':
			if (key != 4)
				key = 2;
			break;
		case 's':
			if (key != 1)
				key = 3;
			break;
		case 'd':
			if (key != 2)
				key = 4;
			break;
		case 'x':
			gameOver = 1;
			break;
			// case 'p':
				// pause = 1 - pause;
				// break;
		default:
			break; // ignore invalid inputs
		}
	}
}