#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 10
#define SUBJECTS 3

typedef struct {
    char name[20];
    int id;
    float scores[SUBJECTS]; 
    float average;
} Student;

Student students[MAX_STUDENTS];
int studentCount = 0;

void enterStudentGrades() {
    int n;
    printf("�п�J�ǥͤH�� (5~10)�G");
    scanf("%d", &n);
    if (n < 5 || n > 10) {
        printf("�H�ƿ�J���~�I�Э��s�ާ@�C\n");
        return;
    }

    studentCount = n;
    for (int i = 0; i < n; i++) {
        printf("��J�� %d ��ǥͪ����\n", i + 1);
        printf("�m�W�G");
        scanf("%s", students[i].name);
        printf("�Ǹ��]6�X��ơ^�G");
        scanf("%d", &students[i].id);
        printf("�ƾǦ��Z�G");
        scanf("%f", &students[i].scores[0]);
        printf("���z���Z�G");
        scanf("%f", &students[i].scores[1]);
        printf("�^�妨�Z�G");
        scanf("%f", &students[i].scores[2]);
        students[i].average = (students[i].scores[0] + students[i].scores[1] + students[i].scores[2]) / 3.0;
    }
    printf("��J�����I��^�D���C\n");
}

