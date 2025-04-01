#include<stdio.h>
#include<stdlib.h>
#define PASSWORD 2024 
int main(void){
	int password;
	char input;
	printf("====================================\n");
	printf("     歡迎使用c語言密碼驗證系統      \n");
	printf(" 作者 : 李雲洲\n");
	printf(" 學號 : 411302260\n");
	printf(" 請輸入密碼以進入系統");
	printf("====================================\n");
	printf("請輸入 4 位數密碼");
	scanf("%d",&password);
	if (password != PASSWORD){
		printf("\n 密碼錯誤，程式即將結束!\n");
		system("PAUSE");
		return 0;
	}
	system("CLS");
	printf("登入成功!請選擇操作:\n\n");
	printf("請輸入一個字元，我們將判斷其類。\n");
	printf("-----------------------------------\n");
	printf("|  'A' ~ 'Z'   :Uppercase     |\n");
	printf("|  'a' ~ 'z'   :Lowercase     |\n");
	printf("|  '0' ~ '9'   :Digit         |\n");
	printf("| 其他字元        : Your name |\n");
	printf("-----------------------------------");
	printf("請輸入一個字元:");
	fflush(stdin);
	scanf("%c", &input);
	if(input >= 'A' && input <= 'Z'){
		printf("\n 輸入的是大寫字母 (Uppercase)\n");
	}
	else if (input >= 'a' && input <= 'z'){
		printf("\n 輸入字母是小寫 (Lowercase)\n");
	}
	else if (input >= '0' && input <= '9'){
		printf("\n 輸入的是數字 (Digit)\n");
	}
	else {
		printf("\n 其他字元，顯示你的名子 :李雲洲\n");
	}
	printf("\n 程式執行完畢，感謝使用!\n");
	system("pause");
	return 0;
	
}
