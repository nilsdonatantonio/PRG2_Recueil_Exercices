#include <stdio.h>
#include <stdlib.h>

int main() {
    char array[60];

    char *ptr = NULL;
    char *strs[3];

    int i;

    ptr = array;
    sprintf(ptr, "%s", "Mercredi");

    strs[2] = ptr;

    ptr += 28;

    sprintf(ptr, "%s", "Lundi");

    strs[0] = ptr;

    ptr += 14;

    sprintf(ptr, "%s", "Mardi");

    strs[1] = ptr;

    for (i = 0; i < 3; ++i) {
        printf("%s\n", strs[i]);
    }

}
