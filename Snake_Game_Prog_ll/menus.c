#include "menus.h"

void displayTitleArt() {
    printf(" _____ _   _   ___   _   __ _____ \n");
    printf("/  ___| \\ | | / _ \\ | | / /|  ___|\n");
    printf("\\ `--.|  \\| |/ /_\\ \\| |/ / | |__  \n");
    printf(" `--. \\ . ` ||  _  ||    \\ |  __| \n");
    printf("/\\__/ / |\\  || | | || |\\  \\| |___ \n");
    printf("\\____/\\_| \\_/\\_| |_\\/|_\\_/\\____/ \n");
    printf("\n");
    printf("   _____   ___  ___  ___ _____    \n");
    printf("  |  __ \\ / _ \\ |  \\/  ||  ___|   \n");
    printf("  | |  \\/ /_\\ \\| .  . || |__     \n");
    printf("  | | __ |  _  || |\\/| ||  __|    \n");
    printf("  | |_\\ \\| | | || |  | || |___    \n");
    printf("   \\____/\\_| |_\\/|_  |_\\/\\____/   \n");
}

void displaySnakeArt() {
    printf("   _________         _________\n");
    printf("  /         \\       /         \\   \n");
    printf(" /  /~~~~~\\  \\     /  /~~~~~\\  \\  \n");
    printf(" |  |     |  |     |  |     |  |\n");
    printf(" |  |     |  |     |  |     |  |\n");
    printf(" |  |     |  |     |  |     |  |         /\n");
    printf(" |  |     |  |     |  |     |  |       //\n");
    printf("(o  o)    \\  \\_____/  /     \\  \\_____/ /\n");
    printf(" \\__/      \\         /       \\        /\n");
    printf("  |         ~~~~~~~~~         ~~~~~~~~\n");
    printf("  ^\n\n");
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

            if (ch == 72 && selected > 0) // up arrow
                selected--;
            else if (ch == 80 && selected < MENU_ITEMS - 1) // down arrow
                selected++;
            displayChoice(selected); // updates the display
        }
        else if (ch == 13) {  // enter
            return selected;  // returns the selected index
        }
        else if (ch == 27) {  // esc to go back
            return -1; 
        }
    }
}

int displayGameStart(int selected) {
    while (1) {
        system("cls"); 
        printf("What size grid would you like?\n\n");
        printf("%s    20x10\n", selected == 0 ? ">" : " ");
        printf("%s    40x20\n", selected == 1 ? ">" : " ");
        printf("%s    100x50 (HARD MODE)\n", selected == 2 ? ">" : " ");

        int ch = _getch();

        if (ch == 224) {
            ch = _getch();

            if (ch == 72 && selected > 0) // up arrow again
                selected--;
            else if (ch == 80 && selected < MENU_ITEMS - 1) // down arrow again
                selected++;
        }
        else if (ch == 13) {  // enter again
            break;
        }
        else if (ch == 27) {  //go back again
            return -1;
        }
    }
    system("cls");
    if (selected == 0) {
        printf("You selected 20x10 grid.\n");
        //this is just a shell for now, proper grid implementation will be added during integration testing
    }
    else if (selected == 1) {
        printf("You selected 40x20 grid.\n");
    }
    else if (selected == 2) {
        printf("You selected 100x50 grid (HARD MODE).\n");
    }
    return selected;
}

void howToPlayDisplay() {
    system("cls");
    printf("Snake is very simple, try grow your snake as long as possible \n");
    printf("without crashing into yourself, or the wall. Eat the apples,\n");
    printf("get big, don't die. You can press ESC to go back to previous\n");
    printf("menus. Your highscore will be saved, so try beat yourself!!!\n\n\n");

    displaySnakeArt();

    while (1) {
        int ch = _getch();
        if (ch == 27) {
            break;
        }
    }
}

void scoreboardDisplay() {
    system("cls");
    printf("Highscores: \n");
    while (1) {
        int ch = _getch();
        if (ch == 27) {
            break;
        }
    }
}

// literally THE function for the menus to work :p you can go to any individual menu as well
void runMenu() {
    int choice = 0;
    int selected = 0;

    displayStartMenu(selected);
    system("cls");  
    while (1) {
        choice = handleMenuSelection(displayStartMenu);

        if (choice == 0) {
            int gridChoice = displayGameStart(selected);
            if (gridChoice != -1) {
                _getch();
            }
        }
        else if (choice == 1) { 
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