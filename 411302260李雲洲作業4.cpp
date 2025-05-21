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
void displayStudents() {
    if (studentCount == 0) {
        printf("�|����J�ǥ͸�ơC\n");
        return;
    }
    printf("�ǥ͸�Ʀp�U�G\n");
    for (int i = 0; i < studentCount; i++) {
        printf("�m�W: %s\t�Ǹ�: %d\t����: %.2f\n", students[i].name, students[i].id, students[i].average);
    }
}
void searchStudent() {
    char name[20];
    int found = 0;
    printf("�п�J�n�d�ߪ��ǥͩm�W�G");
    scanf("%s", name);

    for (int i = 0; i < studentCount; i++) {
        if (strcmp(name, students[i].name) == 0) {
            printf("���ǥ͡G%s\t�Ǹ�: %d\t�������Z: %.2f\n", students[i].name, students[i].id, students[i].average);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("�d�L���ǥ͸�ơC\n");
    }
}
int compare(const void *a, const void *b) {
    float avgA = ((Student*)a)->average;
    float avgB = ((Student*)b)->average;
    return (avgB > avgA) - (avgB < avgA); 
}

void rankStudents() {
    if (studentCount == 0) {
        printf("�|����J�ǥ͸�ơC\n");
        return;
    }
    qsort(students, studentCount, sizeof(Student), compare);
    printf("�ǥͦ��Z�ƦW�p�U�G\n");
    for (int i = 0; i < studentCount; i++) {
        printf("%d. %s\t����: %.2f\n", i + 1, students[i].name, students[i].average);
    }
}

