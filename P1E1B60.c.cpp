#include<stdio.h>
#include<stdlib.h>
#define PASSWORD 2024 
int main(void){
	int password;
	char input;
	printf("====================================\n");
	printf("     �w��ϥ�c�y���K�X���Ҩt��      \n");
	printf(" �@�� : �����w\n");
	printf(" �Ǹ� : 411302260\n");
	printf(" �п�J�K�X�H�i�J�t��");
	printf("====================================\n");
	printf("�п�J 4 ��ƱK�X");
	scanf("%d",&password);
	if (password != PASSWORD){
		printf("\n �K�X���~�A�{���Y�N����!\n");
		system("PAUSE");
		return 0;
	}
	system("CLS");
	printf("�n�J���\!�п�ܾާ@:\n\n");
	printf("�п�J�@�Ӧr���A�ڭ̱N�P�_�����C\n");
	printf("-----------------------------------\n");
	printf("|  'A' ~ 'Z'   :Uppercase     |\n");
	printf("|  'a' ~ 'z'   :Lowercase     |\n");
	printf("|  '0' ~ '9'   :Digit         |\n");
	printf("| ��L�r��        : Your name |\n");
	printf("-----------------------------------");
	printf("�п�J�@�Ӧr��:");
	fflush(stdin);
	scanf("%c", &input);
	if(input >= 'A' && input <= 'Z'){
		printf("\n ��J���O�j�g�r�� (Uppercase)\n");
	}
	else if (input >= 'a' && input <= 'z'){
		printf("\n ��J�r���O�p�g (Lowercase)\n");
	}
	else if (input >= '0' && input <= '9'){
		printf("\n ��J���O�Ʀr (Digit)\n");
	}
	else {
		printf("\n ��L�r���A��ܧA���W�l :�����w\n");
	}
	printf("\n �{�����槹���A�P�¨ϥ�!\n");
	system("pause");
	return 0;
	
}
