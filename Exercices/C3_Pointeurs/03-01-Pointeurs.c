#include "stdio.h"

int main() {
    int nombre = 4;
    int *ptr = NULL;
    ptr = &nombre;

    printf("%d\n", *ptr);
}
