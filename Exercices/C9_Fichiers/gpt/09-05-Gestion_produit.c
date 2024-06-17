#include <stdio.h>
#include <stdlib.h>
#include "09-05-Gestion_produit.h"



int load_data(Product *product_list) {
    FILE *src;
    src = fopen(FIN, "r");
    if (!src) {
        printf("[e] could not read %s", FIN);
        return -1;
    }


    int nbr_item = 0;
    while (fscanf(src, "%d %s %f %d", &(product_list[nbr_item].id), product_list[nbr_item].name, &(product_list[nbr_item].price),
        &(product_list[nbr_item].qty)) != EOF) {

        printf("importing item %d : %s, %.2f, %d...\n", product_list[nbr_item].id, product_list[nbr_item].name,
            product_list[nbr_item].price, product_list[nbr_item].qty);

        nbr_item++;
    }

    fclose(src);

    return nbr_item;
}

void store_data(Product *product_list, const int nbr_item) {
    FILE *db = fopen(DB, "ab");
    if (!db) {
        printf("[e] could not open %s\n", DB);
        return;
    }

    if (fwrite(product_list, sizeof(Product), nbr_item, db) != nbr_item) {
        printf("[e] could not store in file");
        return;
    }

    printf("[i]end of operation : save data\n");
    fclose(db);
}

void read_from_bin(const int nbr_item) {
    FILE *db = fopen(DB, "rb");
    if (!db) {
        printf("[e] could not open %s\n", DB);
        return;
    }

    Product *tmp = (Product *)malloc(nbr_item * sizeof(Product));


    if (fread(tmp, sizeof(tmp[0]), nbr_item, db) != nbr_item) {
        printf("[e] not able to read from db\n");
        return;
    }

    printf("[i] The stock contains %d products:\n", nbr_item);
    for (size_t i = 0; i < nbr_item; ++i) {
        printf("[i] - ID: %d", tmp[i].id);
        printf("[%s],[%.2f.chf],[%d]\n", tmp[i].name, tmp[i].price, tmp[i].qty);
    }

    free(tmp);
    fclose(db);
}



#if 1
int main() {

    Product *product_list = (Product *)malloc(MAXITEM * sizeof(Product));

    int nbr_item = load_data(product_list);

    store_data(product_list, nbr_item);

    read_from_bin(nbr_item);

    free(product_list);
    return 0;
}
#endif
