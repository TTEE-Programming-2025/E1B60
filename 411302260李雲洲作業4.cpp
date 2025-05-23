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
void displayStudents() {
    if (studentCount == 0) {
        printf("尚未輸入學生資料。\n");
        return;
    }
    printf("學生資料如下：\n");
    for (int i = 0; i < studentCount; i++) {
        printf("姓名: %s\t學號: %d\t平均: %.2f\n", students[i].name, students[i].id, students[i].average);
    }
}
void searchStudent() {
    char name[20];
    int found = 0;
    printf("請輸入要查詢的學生姓名：");
    scanf("%s", name);

    for (int i = 0; i < studentCount; i++) {
        if (strcmp(name, students[i].name) == 0) {
            printf("找到學生：%s\t學號: %d\t平均成績: %.2f\n", students[i].name, students[i].id, students[i].average);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("查無此學生資料。\n");
    }
}
int compare(const void *a, const void *b) {
    float avgA = ((Student*)a)->average;
    float avgB = ((Student*)b)->average;
    return (avgB > avgA) - (avgB < avgA); 
}

void rankStudents() {
    if (studentCount == 0) {
        printf("尚未輸入學生資料。\n");
        return;
    }
    qsort(students, studentCount, sizeof(Student), compare);
    printf("學生成績排名如下：\n");
    for (int i = 0; i < studentCount; i++) {
        printf("%d. %s\t平均: %.2f\n", i + 1, students[i].name, students[i].average);
    }
}
void menu() {
    char choice;
    while (1) {
        printf("------------[Grade System]------------\n");
        printf("a. Enter student grades\n");
        printf("b. Display student grades\n");
        printf("c. Search for student grades\n");
        printf("d. Grade ranking\n");
        printf("e. Exit system\n");
        printf("請選擇：");
        scanf(" %c", &choice);

        switch (choice) {
            case 'a': enterStudentGrades(); break;
            case 'b': displayStudents(); break;
            case 'c': searchStudent(); break;
            case 'd': rankStudents(); break;
            case 'e': {
                char confirm;
                printf("確定離開？(y/n)：");
                scanf(" %c", &confirm);
                if (confirm == 'y') {
                    printf("程式結束，感謝使用。\n");
                    return;
                }
                break;
            }
            default:
                printf("輸入錯誤，請重新選擇。\n");
        }
    }
}
int main() {
    char password[5];

    for (int i = 0; i < 3; i++) {
        printf("請輸入密碼（4碼）：");
        scanf("%s", password);
        if (strcmp(password, "2025") == 0) {
            printf("歡迎進入系統！\n");
            menu();
            return 0;
        } else {
            printf("密碼錯誤！\n");
        }
    }

    printf("密碼錯誤超過三次，程式結束。\n");
    return 0;
}
