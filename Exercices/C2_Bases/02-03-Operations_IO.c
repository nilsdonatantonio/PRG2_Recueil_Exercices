#include "stdio.h"
#include "string.h"

int main() {
    printf("Enter your name : ");
    char prenom[50];

    scanf("%s", prenom);

    printf("\n");

    printf("Enter your age : ");
    int age;
    scanf("%d", &age);
    printf("\n");

    printf("Welcome %s, you are %d years old.", prenom, age);
    printf("\n");

}
