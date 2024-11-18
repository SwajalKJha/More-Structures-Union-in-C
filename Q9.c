#include <stdio.h>

#define MAX_STUDENTS 3
#define SUBJECTS 5

struct Student {
    char name[50];
    int marks[SUBJECTS];
};

int main() {
    struct Student students[MAX_STUDENTS];
    int student_totals[MAX_STUDENTS] = {0};
    int subject_totals[SUBJECTS] = {0};

    // Input data for each student
    for (int i = 0; i < MAX_STUDENTS; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf("%s", students[i].name);

        printf("Enter marks for 5 subjects (space separated): ");
        for (int j = 0; j < SUBJECTS; j++) {
            scanf("%d", &students[i].marks[j]);
            student_totals[i] += students[i].marks[j]; // Calculate student total
            subject_totals[j] += students[i].marks[j]; // Calculate subject total
        }
    }

    // Output data
    printf("\nStudent Details:\n");
    for (int i = 0; i < MAX_STUDENTS; i++) {
        printf("Name: %s, Total Marks: %d\n", students[i].name, student_totals[i]);
        for (int j = 0; j < SUBJECTS; j++) {
            printf("Marks in Subject %d: %d\n", j + 1, students[i].marks[j]);
        }
    }

    // Print subject-wise totals
    printf("\nSubject Wise Totals:\n");
    for (int j = 0; j < SUBJECTS; j++) {
        printf("Total marks in Subject %d: %d\n", j + 1, subject_totals[j]);
    }

    return 0;
}

