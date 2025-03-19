#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define GRN "\x1b[32m"
#define RED "\x1b[31m"
#define RESET "\x1b[0m"

#define MENU_ITEMS 3  

// needs runMenu to work!!! :D

void instructionsArt() {
    printf(" _____ _   _  _____ ___________ _   _ _____ _____ _____ _____ _   _  _____ \n");
    printf("|_   _| \\ | |/  ___|_   _| ___ \\ | | /  __ \\_   _|_   _|  _  | \\ | |/  ___|\n");
    printf("  | | |  \\| |\\ `--.  | | | |_/ / | | | /  \\/ | |   | | | | | |  \\| |\\ `--. \n");
    printf("  | | | . ` | `--. \\ | | |    /| | | | |     | |   | | | | | | . ` | `--. \\ \n");
    printf(" _| |_| |\\  |/\\__/ / | | | |\\ \\| |_| | \\__/\\ | |  _| |_\\ \\_/ / |\\  |/\\__/ /\n");
    printf(" \\___/\\_| \\_/\\____/  \\_/ \\_| \\_|\\___/ \\____/ \\_/  \\___/ \\___/\\_| \\_/\\____/ \n\n");
}

void displayTitleArt() {
    printf(" _____ _   _   ___   _   __ _____ \n");
    printf("/  ___| \\ | | / _ \\ | | / /|  ___|\n");
    printf("\\ `--.|  \\| |/ /_\\ \\| |/ / | |__  \n");
    printf(" `--. \\ . ` ||  _  ||    \\ |  __| \n");
    printf("/\\__/ / |\\  || | | || |\\  \\| |___ \n");
    printf("\\____/\\_| \\_/\\_| |_/|_| \\\_/\\____/ \n");
    printf("\n");
    printf("   _____   ___  ___  ___ _____    \n");
    printf("  |  __ \\ / _ \\ |  \\/  ||  ___|   \n");
    printf("  | |  \\// /_\\ \\| .  . || |__     \n");
    printf("  | | __ |  _  || |\\/| ||  __|    \n");
    printf("  | |_\\ \\| | | || |  | || |___    \n");
    printf("   \\____/\\_| |_/\\_|  |_/\\____/   \n");
}

void displaySnakeArt() {
    printf(GRN"   _________         _________\n");
    printf(GRN "  /         \\       /         \\   \n" RESET);
    printf(GRN " /  /~~~~~\\  \\     /  /~~~~~\\  \\  \n" RESET);
    printf(GRN " |  |     |  |     |  |     |  |\n" RESET);
    printf(GRN " |  |     |  |     |  |     |  |\n" RESET);
    printf(GRN " |  |     |  |     |  |     |  |         /\n" RESET);
    printf(GRN " |  |     |  |     |  |     |  |       //\n" RESET);
    printf(GRN "("RESET"o  o" GRN ")    \\  \\_____/  /     \\  \\_____/ /\n" RESET);
    printf(GRN " \\__/      \\         /       \\        /\n" RESET);
    printf(RED "  |         " GRN "~~~~~~~~~         ~~~~~~~~\n" RESET);
    printf(RED "  ^\n\n" RESET);
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
        printf("%s    20x10\n", selected == 0 ? ">" : " ");
        printf("%s    40x20\n", selected == 1 ? ">" : " ");
        printf("%s    100x50 (HARD MODE)\n", selected == 2 ? ">" : " ");

        int ch = _getch();

        if (ch == 224) {
            ch = _getch();

            if (ch == 72 && selected > 0) // Up Arrow
                selected--;
            else if (ch == 80 && selected < MENU_ITEMS - 1) // Down Arrow
                selected++;
        }
        else if (ch == 13) {  // Enter key
            break;
        }
        else if (ch == 27) {  //go back
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
    instructionsArt();
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

// Function to run the menu and process selection
void runMenu() {
    int choice = 0;
    int selected = 0;

    displayStartMenu(selected);
    system("cls");  // Clear screen for next menu
    while (1) {
        choice = handleMenuSelection(displayStartMenu);

        if (choice == 0) {
            int gridChoice = displayGameStart(selected);
            if (gridChoice != -1) {
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

int main() {
    runMenu(); // Start the menu system
    return 0;
}
