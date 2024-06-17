#ifndef GESTION_PRODUIT_H
#define GESTION_PRODUIT_H

#define FIN "input.txt"
#define DB "database.bin"
#define FOUT "output.txt"

#define MAXLENGTH 256
#define MAXITEM 4

typedef struct {
    unsigned int id;
    char name[MAXLENGTH];
    float price;
    int qty;
} Product;

int load_data(Product *product_list);
void store_data(Product *product_list, const int nbr_item);
void read_from_bin();


#endif /* GESTION_PRODUIT_H*/
