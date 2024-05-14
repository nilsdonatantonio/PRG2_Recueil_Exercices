#include <stdlib.h>
#include <stdio.h>

#define TAILLE 5

void somme_tableaux(int tab_size, const int *tab_1, const int *tab_2, int *result) {


    for (int i = 0; i < tab_size; ++i) {
        result[i] = tab_1[i] + tab_2[i];
    }

}

void show_tab(int tab_size, const int *tab) {
    for (int i = 0; i < tab_size; ++i) {
        printf("%d", tab[i]);
    }
    printf("\n");
}

int main(void) {
    int tab_1[TAILLE], tab_2[TAILLE], result[TAILLE];

    printf("Entrer les éléemnts du premier tableau : ");

    for (int i = 0; i < TAILLE; ++i) {
        scanf("%d", &tab_1[i]);
    }

    printf("Entrer les éléments du 2ème tableau : ");

    for (int i = 0; i < TAILLE; ++i) {
        scanf("%d", &tab_2[i]);
    }

    somme_tableaux(TAILLE, tab_1, tab_2, result);


    printf("Contenu du tableau 1 : \n");

    show_tab(TAILLE, tab_1);

    printf("Contenu du tableau 2 : \n");
    show_tab(TAILLE, tab_2);

    printf("Résultat de l'addition : \n");
    show_tab(TAILLE, result);
}
