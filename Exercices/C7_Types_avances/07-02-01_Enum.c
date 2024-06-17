#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    EN_LIGNE,
    HORS_LIGNE,
    EN_JEU,
    EN_PAUSE
} StatutJoueur;

void show_statut(const StatutJoueur *statut) {
    switch (*statut) {
    case EN_LIGNE:
        printf("Le joueur est en ligne\n");
        break;
    case HORS_LIGNE:
        printf("Le joueur est hors-ligne\n");
        break;
    case EN_JEU:
        printf("Le joueur est en jeu\n");
        break;
    case EN_PAUSE:
        printf("Le joueur est en pause\n");
        break;
    default:
        printf("Error\n");
        break;
    }
}

void update_statut(StatutJoueur *statut, StatutJoueur new_statut) {
    *statut = new_statut;
    show_statut(statut);
}

int main(int argc, char *argv[]) {
    StatutJoueur statut = EN_JEU;
    show_statut(&statut);

    update_statut(&statut, HORS_LIGNE);
}
