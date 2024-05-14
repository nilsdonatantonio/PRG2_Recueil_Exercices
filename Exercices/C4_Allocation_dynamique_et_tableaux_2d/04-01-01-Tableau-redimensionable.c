#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// int main(void) {

//     size_t n_elem = 0;
//     size_t cap = 1;
//     int *tab_nombre, *old_tab;
//     tab_nombre = (int *)malloc(sizeof(int));
//     if (tab_nombre == NULL) {
//         printf("Erreur initialisation de la mémoire\n");
//         return 1;
//     }

//     while (true) {
//         printf("Entrez un entier positif (une lettre pour finir): ");
//         int i;
//         if (scanf("%d", &i) != 1) {
//             while (getchar() != '\n');
//             break;
//         }
//         if (n_elem == cap) {
//             old_tab = tab_nombre;
//             tab_nombre = realloc(old_tab, cap * 2 * sizeof(int));
//             if (tab_nombre == NULL) {
//                 printf("Mémoire pleine\n");
//                 tab_nombre = old_tab;
//                 break;
//             } else {
//                 cap *= 2;
//             }
//         }
//         tab_nombre[n_elem++] = i;
//     }

//     printf("Vous avez entré : ");
//     for (int i = 0; i < n_elem; ++i) {
//         printf("%d", tab_nombre[i]);
//     }
//     printf("\n");

//     free(tab_nombre);

// }

int main(void) {
    int nbr_elem = 0;
    int cap = 1;

    int *tab = NULL, *old_tab = NULL;
    tab = (int *)malloc(sizeof(int));

    if (tab == NULL) {
        printf("Erreur d'allocation!");
        return 1;
    }

    while (true) {
        printf("Entrez un entier positif (une lettre pour finir): ");

        int i;
        if (scanf("%d", &i) != 1) {
            while (getchar() != '\n');
            break;
        }

        if (nbr_elem == cap) {
            old_tab = tab;
            tab = realloc(old_tab, cap * 2 * sizeof(int));
            if (tab == NULL) {
                printf("Mémoire pleine !");
                tab = old_tab;
                break;
            } else {
                cap *= 2;
            }

        }
        tab[nbr_elem++] = i;
    }

    printf("Vous avez entré: ");
    for (size_t i = 0; i < nbr_elem; ++i) {
        printf("%d ", tab[i]);
    }
    printf("\n");

    return 0;


}
