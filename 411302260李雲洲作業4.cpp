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
    printf("請輸入學生人數 (5~10)：");
    scanf("%d", &n);
    if (n < 5 || n > 10) {
        printf("人數輸入錯誤！請重新操作。\n");
        return;
    }

    studentCount = n;
    for (int i = 0; i < n; i++) {
        printf("輸入第 %d 位學生的資料\n", i + 1);
        printf("姓名：");
        scanf("%s", students[i].name);
        printf("學號（6碼整數）：");
        scanf("%d", &students[i].id);
        printf("數學成績：");
        scanf("%f", &students[i].scores[0]);
        printf("物理成績：");
        scanf("%f", &students[i].scores[1]);
        printf("英文成績：");
        scanf("%f", &students[i].scores[2]);
        students[i].average = (students[i].scores[0] + students[i].scores[1] + students[i].scores[2]) / 3.0;
    }
    printf("輸入完成！返回主選單。\n");
}

