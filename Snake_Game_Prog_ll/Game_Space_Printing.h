#pragma once
#include <windows.h>
#include "Snake_Initalization.h"

extern int appleX, appleY;

void setCursorPosition(int x, int y);

void hideCursor();

void printGrid(PSNAKENODE head);

void initializeGrid();

void placeSnake(PSNAKENODE head);

void clearSnake(PSNAKENODE head);

void placeAppleOnGrid(int appleX, int appleY);