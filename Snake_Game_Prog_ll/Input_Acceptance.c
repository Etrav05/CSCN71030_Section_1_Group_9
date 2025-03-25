#include "Input_Acceptance.h"
#include "main.h"
#include <conio.h>
#include <ctype.h>

int key, gameOver;

int input() { // accept inputs and set them to a key value
	char lastValidKey = '\0'; // store only the last valid input

	while (_kbhit()) {
		char ch = tolower(getch());

		// only store the last valid key (ignore invalid ones to prevent a backlog)
		if (ch == 'w' || ch == 'a' || ch == 's' || ch == 'd' || ch == 'x') {
			lastValidKey = ch;
		}

	}

	if (lastValidKey != '\0') {
		switch (lastValidKey) {
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