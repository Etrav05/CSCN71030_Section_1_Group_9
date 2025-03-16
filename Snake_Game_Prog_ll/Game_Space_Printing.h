#pragma once
#include <windows.h>
#include "Snake_Initalization.h"

#define WIDTH		20
#define HEIGHT		10

extern int appleX, appleY;


void setCursorPosition(int x, int y);

void hideCursor();

void printGrid(PSNAKENODE head);