#include "stdio.h"

//===================================
//============Exercice 1=============

void exercice_1() {
    printf("Enter a number : ");
    int number;
    scanf("%d", &number);
    printf("\n");

    if (number % 3 == 0 && number % 13 == 0) {
        printf("%d est divisible par 3 et 13\n", number);
    } else {
        printf("%d n'est pas divisible par 3 et 13\n", number);
    }
}

//===================================
//============Exercice 2=============

void exercice_2() {
    printf("Enter 3 numbers : ");
    int number_1, number_2, number_3;
    scanf("%d %d %d", &number_1, &number_2, &number_3);
    printf("\n");

    if (number_1 > number_2) {
        if (number_1 > number_3) {
            printf("Le maximum est : %d\n", number_1);
        } else {
            printf("Le maximum est : %d\n", number_3);
        }
    } else {
        if (number_2 > number_3) {
            printf("Le maximum est : %d\n", number_2);
        } else {
            printf("Le maximum est : %d\n", number_3);
        }
    }

}

int main() {
    exercice_2();
}
