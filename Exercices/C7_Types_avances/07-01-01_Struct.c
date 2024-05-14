#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[100];
    char author[50];
    int pub_year;
    int nbr_copies;
} Livre;


Livre add_new_book(char *title, char *author, int pub_year, int nbr_copies) {
    Livre l;
    strcpy(l.title, title);
    strcpy(l.author, author);
    l.pub_year = pub_year;
    l.nbr_copies = nbr_copies;

    return l;
}

void update_inventory(Livre *l, int update) {
    l->nbr_copies += update;
}

void show_book_info(Livre *l) {
    printf("Titre        : %s\n", l->title);
    printf("Author       : %s\n", l->author);
    printf("Year of pub. : %4d\n", l->pub_year);
    printf("Nbr in stock : %d\n", l->nbr_copies);
}

int main(int argc, char *argv[]) {
    Livre livre = add_new_book("Le Petit Prince", "Antoine de Saint-Exupéry", 1943, 30);
    show_book_info(&livre);
    update_inventory(&livre, -5);
    printf("\n");
    show_book_info(&livre);
    return 0;
}
