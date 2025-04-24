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
        printf("密碼錯誤三次，程式結束。\n");
        return 0;
    }

    int cont = 1;
    while (cont) {
        showMenu();
        char choice;
        printf("請輸入選項：");
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
                printf("輸入錯誤，請重新選擇。\n");
                break;
        }
    }

    printf("感謝使用，再見！\n");
    return 0;
}
void showWelcome() {
    for (int i = 0; i < 21; i++) {
        printf("* 歡迎使用 程式練習系統 %d *\n", i+1);
    }
}
int checkPassword() {
    int input, attempts = 0;
    showWelcome();

    while (attempts < 3) {
        printf("請輸入4位數密碼：");
        scanf("%d", &input);
        if (input == PASSWORD) {
            printf("密碼正確，歡迎使用系統！\n");
            return 1;
        } else {
            printf("密碼錯誤。\n");
            attempts++;
        }
    }
    return 0;
}

void showMenu() {
    system("cls"); 
    printf("=== 主選單 ===\n");
    printf("a. 直出直角三角形\n");
    printf("b. 顯示乘法表\n");
    printf("c. 結束\n");
}

void triangle() {
    char ch;
    printf("請輸入一個 a~z 的字元作為三角形符號：");
    fflush(stdin);
    scanf(" %c", &ch);
    if (ch < 'a' || ch > 'z') {
        printf("輸入錯誤，請輸入 a~z 字元。\n");
        getch();
        return;
    }

    printf("以下是直角三角形：\n");
    for (int i = 1; i <= 5; i++) {
        for (int j = 0; j < i; j++) {
            printf("%c", ch);
        }
        printf("\n");
    }

    printf("按任意鍵返回主選單...\n");
    getch();
}
void multiplicationTable() {
    int n;
    printf("請輸入1~9的整數產生乘法表：");
    scanf("%d", &n);
    if (n < 1 || n > 9) {
        printf("數值錯誤，請重新輸入。\n");
        getch();
        return;
    }

    printf("以下是 %d x %d 的乘法表：\n", n, n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d×%d=%2d  ", i, j, i * j);
        }
        printf("\n");
    }

    printf("按任意鍵返回主選單...\n");
    getch();
}
int continuePrompt() {
    char yn;
    printf("Continue? (y/n)：");
    fflush(stdin);
    scanf(" %c", &yn);

    if (yn == 'Y' || yn == 'y') {
        return 1;
    } else if (yn == 'N' || yn == 'n') {
        return 0;
    } else {
        printf("輸入錯誤，請重新輸入。\n");
        return 1;
    }
}
