#pragma once

#ifndef INPUT_ACCEPTANCE_H
#define INPUT_ACCEPTANCE_H

#include <stdlib.h>

extern int x;
extern int y;

extern int started;
extern int difficulty;
extern int width;
extern int height;

extern int key, gameOver;

extern int snakeLength;

int input(void); // Function to accept and process inputs

#endif // INPUT_ACCEPTANCE_H