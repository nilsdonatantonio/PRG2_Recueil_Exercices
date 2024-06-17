
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LONGUEUR_NOM 35

typedef struct {
    char *nom;
    int age;
} Personne;

int main(int argc, char *argv[]) {
    Personne *qqnPtr = malloc(sizeof(Personne));

    qqnPtr->nom = malloc(LONGUEUR_NOM);

    if (qqnPtr->nom != NULL) {
        strcpy(qqnPtr->nom, "la bite");
    }

    printf("Votre nom est : %35s \n", qqnPtr->nom);

    free(qqnPtr->nom);
    free(qqnPtr);

    return 0;
}
