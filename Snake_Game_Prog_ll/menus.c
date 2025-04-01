#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "menus.h"
#include "gameInit.h"
#include "File_IO.h"
#include "Game_Space_Printing.h"
#include "Snake_Initalization.h"

// needs runMenu to work!!! :D

int width;
int height;
int started;
int difficulty;
int snakeLength;

void gameOverArt() {
printf(" @@@@@@@@   @@@@@@   @@@@@@@@@@   @@@@@@@@      @@@@@@   @@@  @@@  @@@@@@@@  @@@@@@@\n");
printf("@@@@@@@@@  @@@@@@@@  @@@@@@@@@@@  @@@@@@@@     @@@@@@@@  @@@  @@@  @@@@@@@@  @@@@@@@@\n");
printf("!@@        @@!  @@@  @@! @@! @@!  @@!          @@!  @@@  @@!  @@@  @@!       @@!  @@@\n");
printf("!@!        !@!  @!@  !@! !@! !@!  !@!          !@!  @!@  !@!  @!@  !@!       !@!  @!@\n");
printf("!@! @!@!@  @!@!@!@!  @!! !!@ @!@  @!!!:!       @!@  !@!  @!@  !@!  @!!!:!    @!@!!@!\n");
printf("!!! !!@!!  !!!@!!!!  !@!   ! !@!  !!!!!:       !@!  !!!  !@!  !!!  !!!!!:    !!@!@!\n");
printf(":!!   !!:  !!:  !!!  !!:     !!:  !!:          !!:  !!!  :!:  !!:  !!:       !!: :!!\n");
printf(":!:   !::  :!:  !:!  :!:     :!:  :!:          :!:  !:!   ::!!:!   :!:       :!:  !:!\n");
printf(" ::: ::::  ::   :::  :::     ::    :: ::::     ::::: ::    ::::     :: ::::  ::   :::\n");
printf(" :: :: :    :   : :   :      :    : :: ::       : :  :      :      : :: ::    :   : :\n\n\n");
printf("Score:  %d\n\n", snakeLength * 100 - 100);
}

void instructionsArt() {
    printf(" _____ _   _  _____ ___________ _   _ _____ _____ _____ _____ _   _  _____ \n");
    printf("|_   _| \\ | |/  ___|_   _| ___ \\ | | /  __ \\_   _|_   _|  _  | \\ | |/  ___|\n");
    printf("  | | |  \\| |\\ `--.  | | | |_/ / | | | /  \\/ | |   | | | | | |  \\| |\\ `--. \n");
    printf("  | | | . ` | `--. \\ | | |    /| | | | |     | |   | | | | | | . ` | `--. \\ \n");
    printf(" _| |_| |\\  |/\\__/ / | | | |\\ \\| |_| | \\__/\\ | |  _| |_\\ \\_/ / |\\  |/\\__/ /\n");
    printf(" \\___/\\_| \\_/\\____/  \\_/ \\_| \\_|\\___/ \\____/ \\_/  \\___/ \\___/\\_| \\_/\\____/ \n\n");
}

void displayTitleArt() {
    printf(RED" _____ _   _   ___   _   __ _____ \n"RESET);
    printf(YLW"/  ___| \\ | | / _ \\ | | / /|  __'|--<\n"RESET);
    printf(RED"\\ `--.|  \\| |/ /_\\ \\| |/ / | |__  \n"RESET);
    printf(YLW" `--. \\ . ` ||  _  ||    \\ |  __| \n"RESET);
    printf(RED"/\\__/ / |\\  || | | || |\\  \\| |___ \n"RESET);
    printf(YLW"\\____/\\_| \\_/\\_| |_/|_| \\\_/\\____/ \n"RESET);
    printf("\n");
    printf(YLW"   _____   ___  ___  ___ _____    \n"RESET);
    printf(RED"  |  __ \\ / _ \\ |  \\/  ||  ___|   \n"RESET);
    printf(YLW"  | |  \\// /_\\ \\| .  . || |__     \n"RESET);
    printf(RED"  | | __ |  _  || |\\/| ||  __|    \n"RESET);
    printf(YLW"  | |_\\ \\| | | || |  | || |___    \n"RESET);
    printf(RED"   \\____/\\_| |_/\\_|  |_/\\____/   \n"RESET);
}

void displaySnakeArt() {
    printf(GRN"                  _________         _________\n");
    printf(GRN "                 /         \\       /         \\   \n" RESET);
    printf(GRN "                /  /~~~~~\\  \\     /  /~~~~~\\  \\  \n" RESET);
    printf(GRN "                |  |     |  |     |  |     |  |\n" RESET);
    printf(GRN "                |  |     |  |     |  |     |  |\n" RESET);
    printf(GRN "                |  |     |  |     |  |     |  |         /\n" RESET);
    printf(GRN "                |  |     |  |     |  |     |  |       //\n" RESET);
    printf(GRN "               ("RESET"o  o" GRN ")    \\  \\_____/  /     \\  \\_____/ /\n" RESET);
    printf(GRN "                \\__/      \\         /       \\        /\n" RESET);
    printf(RED "                 |         " GRN "~~~~~~~~~         ~~~~~~~~\n" RESET);
    printf(RED "                 ^\n\n" RESET);
}

void displayStartMenu(int selected) {
    system("cls");
    displayTitleArt();
    printf("\n\n\n%s    start\n", selected == 0 ? ">" : " ");
    printf("%s    how to play\n", selected == 1 ? ">" : " ");
    printf("%s    scoreboard\n", selected == 2 ? ">" : " ");
}

int handleMenuSelection(void(*displayChoice)(int)) {
    int selected = 0;
    displayChoice(selected);
    while (1) {
        int ch = _getch();

        if (ch == 224) {
            ch = _getch();

            if (ch == 72 && selected > 0) // Up Arrow
                selected--;
            else if (ch == 80 && selected < MENU_ITEMS - 1) // Down Arrow
                selected++;
            displayChoice(selected); // Update the menu display
        }
        else if (ch == 13) {  // Enter key
            return selected;  // Return the selected menu index
        }
        else if (ch == 27) {  // Escape key to go back
            return -1;  // Return a special value to indicate "back"
        }
    }
}

int displayGameStart(int selected) {
    while (1) {
        system("cls"); // Clears the console screen (Windows)
        printf("What size grid would you like?\n\n");

        // Dynamically prints the menu with the selection arrow
        printf("%s    10x10\n", selected == 0 ? ">" : " ");
        printf("%s    20x20\n", selected == 1 ? ">" : " ");
        printf("%s    50x50 (HARD MODE)\n", selected == 2 ? ">" : " ");

        int ch = _getch();

        if (ch == 224) {
            ch = _getch();

            if (ch == 72 && selected > 0) // Up Arrow
                selected--;
            else if (ch == 80 && selected < MENU_ITEMS - 1) // Down Arrow
                selected++;
        }
        else if (ch == 13) {  // Enter key
            system("cls");
            if (selected == 0) {
                width = 20;
                height = 10;
                difficulty = 100;
                // printf("You selected 10x10 grid.\n");
            }
            else if (selected == 1) {
                width = 40;
                height = 20;
                difficulty = 50;
                // printf("You selected 20x20 grid.\n");
            }
            else if (selected == 2) {
                width = 60;
                height = 30;
                difficulty = 25; // speed but in the inverse basically (25ms per game loop)
                // printf("You selected 30x30 grid (HARD MODE).\n");
            }
            system("cls");
            return 1;
        }
        else if (ch == 27) {  //go back
            return -1;
        }
    }
}

void howToPlayDisplay() {
    system("cls");
    instructionsArt();
    printf("      Snake is very simple, try grow your snake as long as possible \n");
    printf("      without crashing into yourself, or the wall. Eat the apples,\n");
    printf("      get big, don't die. You can press ESC to go back to previous\n");
    printf("      menus. Your highscore will be saved, so try beat yourself!!!\n\n\n");

    displaySnakeArt();

    while (1) {
        int ch = _getch();
        if (ch == 27) {
            break;
        }
    }
}

int gameOverScreen(){
    int selected = 0;

    while(1){
        system("cls");
        gameOverArt();
        printf("%s    replay\n", selected == 0 ? ">" : " ");
        printf("%s    quit to main menu\n", selected == 1 ? ">" : " ");


        int ch = _getch();

        if (ch == 224) {
            ch = _getch();

            if (ch == 72 && selected > 0) // Up Arrow
                selected--;
            else if (ch == 80 && selected < 2 - 1) // Down Arrow
                selected++;
        }
        else if (ch == 13) {  // Enter key
            system("cls");
            return selected;
        }
    } 
}

void scoreboardDisplay() {
    system("cls");
    printf("Highscore: %d\n", readHighScore());
    while (1) {
        int ch = _getch();
        if (ch == 27) {
            break;
        }
    }
}

// Function to run the menu and process selection
void runMenu() {
    int choice = 0;
    int selected = 0;

    hideCursor();

    displayStartMenu(selected);
    system("cls");  // Clear screen for next menu

    while (started != 1) {
        choice = handleMenuSelection(displayStartMenu);

        if (choice == 0) {
            int gridChoice = displayGameStart(selected);
            if (gridChoice == 1) {
                started = 1;
                break;
            }
            else if (gridChoice != -1) {
                _getch();
            }
        }
        else if (choice == 1) { // include saying press escape to go back to previous menu
            howToPlayDisplay();
        }
        else if (choice == 2) {
            scoreboardDisplay();
        }
        else if (choice == -1) {
            continue;
        }
    }
}
