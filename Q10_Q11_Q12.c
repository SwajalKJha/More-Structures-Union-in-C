#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

struct teacher {
    char name[15];
    char surname[15];
    char subject[15];
    int age;
    int j_year;
    int reg_num;
    union T_ID {
        char adhaar[20];
        char passport[20];
        char d_licence[20];
    } t_id;
    int t_id_choice;
};

struct student {
    char name[15];
    char surname[15];
    char father_name[15];
    int age;
    int class;
    int roll_num;
    union S_ID {
        char adhaar[20];
        char passport[20];
        char d_licence[20];
    } s_id;
    int s_id_choice;
};

void teacher_data(FILE *file_t);
void student_data(FILE *file_s);

int main() {
    char choice;

    do {
        printf("Which file do you want to access: Teacher(T) / Student(S) / Quit(Q): ");
        scanf(" %c", &choice);
        getchar();

        if (choice == 't' || choice == 'T') {
            FILE *file_t = fopen("teachers.txt", "a+");
            if (file_t == NULL) {
                printf("File couldn't be initialized... Exiting...\n");
                return -1;
            }
            teacher_data(file_t);
            fclose(file_t);
        } 
        else if (choice == 's' || choice == 'S') {
            FILE *file_s = fopen("students.txt", "a+");
            if (file_s == NULL) {
                printf("File couldn't be initialized... Exiting...\n");
                return -1;
            }
            student_data(file_s);
            fclose(file_s);
        }
        else if (choice == 'q' || choice == 'Q') {
            printf("Exiting...\n");
            return 0;
        } else {
            printf("Please enter a valid character...\n");
        }

    } while (1); // Continue until quit is chosen

    return 0;
}

void teacher_data(FILE *file_t) {
    struct teacher t;
    char print_choice;

    // Input teacher data
    do {
        printf("Enter Employee Registration Number (1 - 50): ");
        scanf("%d", &t.reg_num);
    } while (t.reg_num < 1 || t.reg_num > 50);

    printf("Enter Name: ");
    scanf("%s", t.name);

    printf("Enter Surname: ");
    scanf("%s", t.surname);

    printf("Enter Subject: ");
    scanf("%s", t.subject);

    printf("Enter Year of Joining: ");
    scanf("%d", &t.j_year);

    do {
        printf("Enter age (35 - 60): ");
        scanf("%d", &t.age);
    } while (t.age < 35 || t.age > 60);

    do {
        printf("Enter the choice for ID, 1: Adhaar, 2: Passport, 3: Driving Licence: ");
        scanf("%d", &t.t_id_choice);
        getchar(); 

        switch (t.t_id_choice) {
            case 1:
                printf("Enter Adhaar card ID: ");
                scanf("%s", t.t_id.adhaar);
                break;
            case 2:
                printf("Enter Passport ID: ");
                scanf("%s", t.t_id.passport);
                break;
            case 3:
                printf("Enter Driving Licence ID: ");
                scanf("%s", t.t_id.d_licence);
                break;
            default:
                printf("Invalid choice, try again.\n");
        }
    } while (t.t_id_choice < 1 || t.t_id_choice > 3);

    // Output teacher data
    printf("Do you want to print the data? (Y/N): ");
    scanf(" %c", &print_choice);

    if (print_choice == 'y' || print_choice == 'Y') {
        printf("**************************************************************************\n");
        printf("Employee Registration Number: %d\n", t.reg_num);
        printf("Employee Name: %s %s\n", t.name, t.surname);
        printf("Employee Subject: %s\n", t.subject);
        printf("Employee Year of Joining: %d\n", t.j_year);
        printf("Employee Age: %d\n", t.age);
        if (t.t_id_choice == 1)
            printf("Employee Adhaar: %s\n", t.t_id.adhaar);
        else if (t.t_id_choice == 2)
            printf("Employee Passport: %s\n", t.t_id.passport);
        else if (t.t_id_choice == 3)
            printf("Employee Driving Licence: %s\n", t.t_id.d_licence);
        printf("**************************************************************************\n");
    }

    // Write to the file
    if (t.t_id_choice == 1)
        fprintf(file_t, "Registration Number: %d Name: %s %s Subject: %s Age: %d Joining Year: %d Adhaar Number: %s\n", t.reg_num, t.name, t.surname, t.subject, t.age, t.j_year, t.t_id.adhaar);
    else if (t.t_id_choice == 2)
        fprintf(file_t, "Registration Number: %d Name: %s %s Subject: %s Age: %d Joining Year: %d Passport Number: %s\n", t.reg_num, t.name, t.surname, t.subject, t.age, t.j_year, t.t_id.passport);
    else if (t.t_id_choice == 3)
        fprintf(file_t, "Registration Number: %d Name: %s %s Subject: %s Age: %d Joining Year: %d Driving Licence Number: %s\n", t.reg_num, t.name, t.surname, t.subject, t.age, t.j_year, t.t_id.d_licence);
        
}

void student_data(FILE *file_s) {
    struct student s;
    char print_choice;

    // Input student data
    do {
        printf("Enter Student Roll Number (1 - 550): ");
        scanf("%d", &s.roll_num);
    } while (s.roll_num < 1 || s.roll_num > 550);

    printf("Enter Name: ");
    scanf("%s", s.name);

    printf("Enter Surname: ");
    scanf("%s", s.surname);

    printf("Enter Father's Name: ");
    scanf("%s", s.father_name);

    do {
        printf("Enter Class Number (1 - 4): ");
        scanf("%d", &s.class);
    } while (s.class < 1 || s.class > 4);

    do {
        printf("Enter age (18 - 26): ");
        scanf("%d", &s.age);
    } while (s.age < 18 || s.age > 26);

    do {
        printf("Enter the choice for ID, 1: Adhaar, 2: Passport, 3: Driving Licence: ");
        scanf("%d", &s.s_id_choice);
        
        switch (s.s_id_choice) {
            case 1:
                printf("Enter Adhaar card ID: ");
                scanf("%s", s.s_id.adhaar);
                break;
            case 2:
                printf("Enter Passport ID: ");
                scanf("%s", s.s_id.passport);
                break;
            case 3:
                printf("Enter Driving Licence ID: ");
                scanf("%s", s.s_id.d_licence);
                break;
            default:
                printf("Invalid choice, try again.\n");
        }
    } while (s.s_id_choice < 1 || s.s_id_choice > 3);

    // Output student data
    printf("Do you want to print the data? (Y/N): ");
    scanf(" %c", &print_choice);

    if (print_choice == 'y' || print_choice == 'Y') {
        printf("**************************************************************************\n");
        printf("Student's Roll Number: %d\n", s.roll_num);
        printf("Student's Name: %s %s\n", s.name, s.surname);
        printf("Student's Father's Name: %s\n", s.father_name);
        printf("Student's Age: %d\n", s.age);
        printf("Student's Class: %d\n", s.class);
        if (s.s_id_choice == 1)
            printf("Student's Adhaar: %s\n", s.s_id.adhaar);
        else if (s.s_id_choice == 2)
            printf("Student's Passport: %s\n", s.s_id.passport);
        else if (s.s_id_choice == 3)
            printf("Student's Driving Licence: %s\n", s.s_id.d_licence);
        printf("**************************************************************************\n");
    }

    // Write to the file
    if (s.s_id_choice == 1)
        fprintf(file_s, "Roll Number: %d Name: %s %s Father's Name: %s Age: %d Class: %d Adhaar Number: %s\n", s.roll_num, s.name, s.surname, s.father_name, s.age, s.class, s.s_id.adhaar);
    else if (s.s_id_choice == 2)
        fprintf(file_s, "Roll Number: %d Name: %s %s Father's Name: %s Age: %d Class: %d Passport Number: %s\n", s.roll_num, s.name, s.surname, s.father_name, s.age, s.class, s.s_id.passport);
    else if (s.s_id_choice == 3)
        fprintf(file_s, "Roll Number: %d Name: %s %s Father's Name: %s Age: %d Class: %d Driving Licence Number: %s\n", s.roll_num, s.name, s.surname, s.father_name, s.age, s.class, s.s_id.d_licence);
        
}

