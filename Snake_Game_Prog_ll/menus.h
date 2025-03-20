#pragma once

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

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