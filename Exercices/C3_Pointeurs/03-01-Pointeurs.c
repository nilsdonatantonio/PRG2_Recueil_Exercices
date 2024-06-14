#include <stdio.h>

int main(){
    int nombre = 42;
    int *ptr_to_int = &nombre;

    printf("Nombre : %d", *ptr_to_int);
}
