#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ROWS 9
#define COLS 9
#define PASSWORD "2025"

char seats[ROWS][COLS]; 

void initializeSeats() {
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            seats[i][j] = '-';
}

void displaySeats() {
    printf("  ");
    for (int j = 0; j < COLS; j++)
        printf("%d", j + 1);
    printf("\n");
    for (int i = ROWS - 1; i >= 0; i--) {
        printf("%d ", i + 1);
        for (int j = 0; j < COLS; j++) {
            printf("%c", seats[i][j]);
        }
        printf("\n");
    }
}

void showWelcomeScreen() {
    for (int i = 0; i < 20; i++) {
        printf("Welcome to the Booking System...\n");
    }
}

int login() {
    char input[10];
    printf("Please enter the 4-digit password: ");
    scanf("%s", input);
    if (strcmp(input, PASSWORD) == 0) {
        printf("Login successful! Welcome!\n");
        return 1;
    } else {
        printf("Incorrect password. Program will exit.\n");
        return 0;
    }
}

void showMenu() {
    printf("\n--------- [Booking System] ---------\n");
    printf("a. Available seats\n");
    printf("b. Arrange for you\n");
    printf("c. Choose by yourself\n");
    printf("d. Exit\n");
    printf("------------------------------------\n");
    printf("Please select an option: ");
}

int autoArrange(int n) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j <= COLS - n; j++) {
            int available = 1;
            for (int k = 0; k < n; k++) {
                if (seats[i][j + k] != '-') {
                    available = 0;
                    break;
                }
            }
            if (available) {
                printf("System suggests seats: ");
                for (int k = 0; k < n; k++) {
                    printf("(%d,%d) ", i + 1, j + k + 1);
                    seats[i][j + k] = '?'; 
                }
                printf("\nAccept arrangement? (y/n): ");
                char ans;
                scanf(" %c", &ans);
                if (ans == 'y' || ans == 'Y') {
                    for (int k = 0; k < n; k++) {
                        seats[i][j + k] = '@';
                    }
                    return 1;
                } else {
                    for (int k = 0; k < n; k++) {
                        seats[i][j + k] = '-';
                    }
                    printf("Seats cleared. Returning to menu.\n");
                    return 0;
                }
            }
        }
    }
    printf("No suitable seats found.\n");
    return 0;
}

void manualChoose() {
    char input[10];
    printf("Enter seat positions like '1-2'. Type 'q' to quit.\n");
    while (1) {
        printf("Select seat (row-col): ");
        scanf("%s", input);
        if (strcmp(input, "q") == 0) break;

        int row, col;
        if (sscanf(input, "%d-%d", &row, &col) != 2 ||
            row < 1 || row > ROWS || col < 1 || col > COLS) {
            printf("Invalid format or out-of-range input.\n");
            continue;
        }

        if (seats[row - 1][col - 1] == '-') {
            seats[row - 1][col - 1] = '@';
        } else {
            printf("Seat already taken.\n");
        }
    }
}

int main() {
    showWelcomeScreen();
    if (!login()) return 0;
    initializeSeats();

    char choice;
    while (1) {
        showMenu();
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                displaySeats();
                break;
            case 'b': {
                int num;
                printf("How many seats do you want to reserve? (1-4): ");
                scanf("%d", &num);
                if (num >= 1 && num <= 4) {
                    autoArrange(num);
                } else {
                    printf("Invalid seat number.\n");
                }
                break;
            }
            case 'c':
                manualChoose();
                break;
            case 'd': {
                char cont;
                printf("Continue? (y/n): ");
                scanf(" %c", &cont);
                if (cont == 'n' || cont == 'N') {
                    printf("Exiting the program.\n");
                    return 0;
                }
                break;
            }
            default:
                printf("Invalid menu option.\n");
        }
    }

    return 0;
}
