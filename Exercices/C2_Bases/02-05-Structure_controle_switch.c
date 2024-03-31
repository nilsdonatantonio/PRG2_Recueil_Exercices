#include "stdio.h"

void exercice_1() {
    printf("Enter day of the week : ");
    int day;
    scanf("%d", &day);
    printf("\n");


    switch (day) {
    case 1:
        printf("Lundi\n");
        break;
    case 2:
        printf("Mardi\n");
        break;
    case 3:
        printf("Mercredi\n");
        break;
    case 4:
        printf("Jeudi\n");
        break;
    case 5:
        printf("Vendredi\n");
        break;
    case 6:
        printf("Samedi\n");
        break;
    case 7:
        printf("Dimanche\n");
        break;
    default:
        printf("Not a day of the week. Good bye.\n");
        break;
    }
}

void exercice_2() {
    printf("Enter math question : ");
    int lhs, rhs;
    char sign;
    scanf("%d %c %d", &lhs, &sign, &rhs);
    printf("\n");



    int result;
    switch (sign) {
    case '+':
        result = lhs + rhs;
        printf("%d \n", result);
        break;
    case '-':
        result = lhs - rhs;
        printf("%d \n", result);
        break;
    case '*':
        result = lhs * rhs;
        printf("%d \n", result);
        break;
    case '/':
        result = lhs - rhs;
        printf("%d \n", result);
        break;
    default:
        printf("Math operation not possible. Good bye.\n");
        break;
    }
}

int main() {

    exercice_1();

    exercice_2();
}
