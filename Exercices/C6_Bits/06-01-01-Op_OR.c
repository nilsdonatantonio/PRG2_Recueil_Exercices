#include <stdio.h>

#define READ 0x01
#define WRITE 0x02
#define EXECUTE 0x04

int main() {

    unsigned char rights = 0x0;

    rights |= READ | WRITE;

    printf("Droits d'accès après modification: 0x%X\n", rights);

    if (rights & READ) printf("Read rights granted");
    if (rights & WRITE) printf("Write rights granted");
    if (rights & EXECUTE) printf("Execute rights granted");

    return 0;
}
