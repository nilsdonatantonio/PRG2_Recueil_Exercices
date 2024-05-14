#include "stdio.h"

int main() {

    char nom[50];
    int age = 0;

    char *ptr_nom = nom;
    int *ptr_age = &age;

    char **ptr_ptr_nom = &ptr_nom;
    int **ptr_ptr_age = &ptr_age;

    printf("NOM : ");
    scanf("%s", *ptr_ptr_nom);
    printf("\n");

    printf("AGE : ");
    scanf("%d", *ptr_ptr_age);
    printf("\n");

    printf("NOM : %s, AGE : %d\n", nom, age);


}
