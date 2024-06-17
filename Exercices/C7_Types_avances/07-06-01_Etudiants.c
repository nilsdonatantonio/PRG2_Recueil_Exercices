#include <stdlib.h>
#include <stdio.h>
#include <time.h>


typedef enum Gradelevel {
    FRESHMAN,
    SOPHOMORE,
    JUNIOR,
    SENIOR
} Gradelevel;

typedef struct Date {
    int day;
    int month;
    int year;
} Date;

typedef struct Student {
    char *name;
    int id;
    Date birthday;
    Gradelevel grade;
} Student;

void print_student(Student *student) {
    printf("Student ID : %d\n", student->id);
    printf("Name       : %s\n", student->name);
    printf("Birthday   : %2d.%2d.%4d\n", student->birthday.day, student->birthday.month, student->birthday.year);
    printf("Grade leve : ");
    switch (student->grade) {
    case FRESHMAN:
        printf("Freshman\n");
        break;
    case SOPHOMORE:
        printf("Sophomore\n");
        break;
    case JUNIOR:
        printf("Junior\n");
        break;
    case SENIOR:
        printf("Senior\n");
    default:
        break;
    }

    printf("\n");
}

int main() {
    Student students[3] = {
        {.name = "Nicolas Cage", .id = 1, .birthday = {.day = 1,.month = 12,.year = 1997}, .grade = SOPHOMORE},
        {.name = "George Lucas", .id = 2, .birthday = {.day = 1, .month = 10, .year = 1967}, .grade = SENIOR},
        {.name = "Francis Copolla", .id = 3, .birthday = {.day = 12, .month = 4, .year = 1932}, .grade = FRESHMAN}
    };

    for (size_t i = 0; i < 3; ++i) {
        print_student(&(students[i]));
    }
}
