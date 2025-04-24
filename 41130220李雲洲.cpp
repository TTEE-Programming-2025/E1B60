#include <stdio.h>
#include <stdlib.h>
#include <conio.h> 
#define PASSWORD 2025
void showWelcome();
int checkPassword();
void showMenu();
void triangle();
void multiplicationTable();
int continuePrompt();

int main() {
    int success = checkPassword();
    if (!success) {
        printf("�K�X���~�T���A�{�������C\n");
        return 0;
    }

    int cont = 1;
    while (cont) {
        showMenu();
        char choice;
        printf("�п�J�ﶵ�G");
        fflush(stdin); 
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
            case 'A':
                triangle();
                break;
            case 'b':
            case 'B':
                multiplicationTable();
                break;
            case 'c':
            case 'C':
                cont = continuePrompt();
                break;
            default:
                printf("��J���~�A�Э��s��ܡC\n");
                break;
        }
    }

    printf("�P�¨ϥΡA�A���I\n");
    return 0;
}
void showWelcome() {
    for (int i = 0; i < 21; i++) {
        printf("* �w��ϥ� �{���m�ߨt�� %d *\n", i+1);
    }
}
int checkPassword() {
    int input, attempts = 0;
    showWelcome();

    while (attempts < 3) {
        printf("�п�J4��ƱK�X�G");
        scanf("%d", &input);
        if (input == PASSWORD) {
            printf("�K�X���T�A�w��ϥΨt�ΡI\n");
            return 1;
        } else {
            printf("�K�X���~�C\n");
            attempts++;
        }
    }
    return 0;
}

void showMenu() {
    system("cls"); 
    printf("=== �D��� ===\n");
    printf("a. ���X�����T����\n");
    printf("b. ��ܭ��k��\n");
    printf("c. ����\n");
}

void triangle() {
    char ch;
    printf("�п�J�@�� a~z ���r���@���T���βŸ��G");
    fflush(stdin);
    scanf(" %c", &ch);
    if (ch < 'a' || ch > 'z') {
        printf("��J���~�A�п�J a~z �r���C\n");
        getch();
        return;
    }

    printf("�H�U�O�����T���ΡG\n");
    for (int i = 1; i <= 5; i++) {
        for (int j = 0; j < i; j++) {
            printf("%c", ch);
        }
        printf("\n");
    }

    printf("�����N���^�D���...\n");
    getch();
}
void multiplicationTable() {
    int n;
    printf("�п�J1~9����Ʋ��ͭ��k��G");
    scanf("%d", &n);
    if (n < 1 || n > 9) {
        printf("�ƭȿ��~�A�Э��s��J�C\n");
        getch();
        return;
    }

    printf("�H�U�O %d x %d �����k��G\n", n, n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d��%d=%2d  ", i, j, i * j);
        }
        printf("\n");
    }

    printf("�����N���^�D���...\n");
    getch();
}
int continuePrompt() {
    char yn;
    printf("Continue? (y/n)�G");
    fflush(stdin);
    scanf(" %c", &yn);

    if (yn == 'Y' || yn == 'y') {
        return 1;
    } else if (yn == 'N' || yn == 'n') {
        return 0;
    } else {
        printf("��J���~�A�Э��s��J�C\n");
        return 1;
    }
}
