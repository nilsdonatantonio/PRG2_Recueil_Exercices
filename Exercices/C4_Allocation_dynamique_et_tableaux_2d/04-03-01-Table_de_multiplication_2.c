#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <inttypes.h>

size_t lire_size_t(const char *message) {
    // int64_t num;
    // printf("%s", message);
    // while (scanf("%" SCNd64, &num) != 1 || num <= 0) {
    //     printf("Erreur de saisie. Entrez un entier positif : ");
    //     while (getchar() != '\n');
    // }

    // return (size_t)num;

    int64_t num;
    printf("%s", message);
    while (scanf("%" SCNd64, &num) != 1 || num <= 0) {
        printf("Erreur de saisie. Entrer un entier positif: ");
        while (getchar() != '\n');
    }

    return (size_t)num;
}

int main() {

    //     size_t width;
    //     size_t height;

    //     int **tab = NULL;

    //     height = lire_size_t("Entrer le nombre de lignes: ");
    //     width = lire_size_t("Entrer le nombre de colonnes: ");

    //     tab = (int **)calloc(height, sizeof(int *));
    //     if (tab == NULL) {
    //         printf("Erreur d'allocation memoire\n");
    //         return 1;
    //     }

    //     for (size_t i = 0; i < height; ++i) {
    //         tab[i] = (int *)malloc(width * sizeof(int));
    //         if (tab[i] == NULL) {
    //             printf("Erreur d'allocation memoire\n");
    //             goto liberation;
    //         }
    //     }

    //     for (size_t i = 0; i < height; ++i) {
    //         for (size_t j = 0; j < width; ++j) {
    //             tab[i][j] = (i + 1) * (j + 1);
    //         }
    //     }

    //     for (size_t i = 0; i < height; ++i) {
    //         for (size_t j = 0; j < width; ++j) {
    //             printf("%d ", tab[i][j]);
    //         }
    //         printf("\n");
    //     }

    // liberation:
    //     for (size_t i = 0; i < height; ++i) {
    //         free(tab[i]);
    //     }
    //     free(tab);

    int height;
    int width;

    height = lire_size_t("Entrez le nombre de lignes: ");
    width = lire_size_t("Entrez le nombre de colonnes: ");

    int **tab2d = NULL;

    tab2d = (int **)calloc(height, sizeof(int *));

    if (tab2d == NULL) {
        printf("Erreur d'allocation");
        return -1;
    }

    for (size_t i = 0; i < height; ++i) {
        tab2d[i] = malloc(width * sizeof(int));
        if (tab2d[i] == NULL) {
            printf("Erreur d'allocation");
            goto liberation;
        }
    }

    for (size_t i = 0; i < height; ++i) {
        for (size_t j = 0; j < width; ++j) {
            tab2d[i][j] = (i + 1) * (j + 1);
        }
    }

    for (size_t i = 0; i < height; ++i) {
        for (size_t j = 0; j < width; ++j) {
            printf("%d ", tab2d[i][j]);
        }
        printf("\n");
    }
    printf("\n");


liberation:
    for (size_t i = 0; i < height; ++i) {
        free(tab2d[i]);
    }

    free(tab2d);

}
