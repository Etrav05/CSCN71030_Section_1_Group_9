#pragma once

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define GRN "\x1b[32m"
#define RED "\x1b[31m"
#define RESET "\x1b[0m"

#define MENU_ITEMS 3 

void instructionsArt();

void displayTitleArt();

void displaySnakeArt();

void displayStartMenu(int selected);

int handleMenuSelection(void(*displayChoice)(int));

int displayGameStart(int selected);

void howToPlayDisplay();

void scoreboardDisplay();

void runMenu();