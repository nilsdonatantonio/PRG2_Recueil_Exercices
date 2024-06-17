#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 256
#define MAXITEM 80

#define SRC "test.txt"
#define DST "test.bin"

int item_nbr = 0;

typedef struct {
    char brand[MAXLEN];
    char item[MAXLEN];
    int qty;
    float unit, total;
} StockItem;

void import_from_txt(StockItem stock[]) {

    FILE *src = fopen(SRC, "r");
    if (!src) {
        printf("[e] could not open %s... \n", SRC);
        printf("[i] exiting now\n");
        return;
    }

    int cnt = 0;
    while (fscanf(src, "%s %s %f %d %f", stock[cnt].brand, stock[cnt].item, &(stock[cnt].unit), &(stock[cnt].qty), &(stock[cnt].total)) != EOF) {
        printf("importing %s,%s,%.2f,%d,%.2f\n", stock[cnt].brand, stock[cnt].item, stock[cnt].unit, stock[cnt].qty, stock[cnt].total);
        cnt++;
        item_nbr++;
    }

    fclose(src);


}

void store_to_bin(StockItem *stock) {

    FILE *dst = fopen(DST, "wb");
    if (!dst) {
        printf("[e] could not open %s... \n", DST);
        printf("[i] exiting now\n");
        return;
    }

    //update header
    if (fwrite(&item_nbr, sizeof(item_nbr), 1, dst) != 1) {
        printf("[e] could not add header\n");
        return;
    }

    //Adding rows
    if (fwrite(stock, sizeof(stock[0]), item_nbr, dst) != item_nbr) {
        printf("[e] could not store stock to %s\n", DST);
        return;
    }

    fclose(dst);
}

void import_from_bin(const StockItem stock[]) {
    FILE *src = fopen(DST, "rb");
    if (!src) {
        printf("[e] could not open %s... \n", DST);
        printf("[i] exiting now\n");
        return;
    }

    int n;
    if (fread(&n, sizeof n, 1, src) != 1) {
        printf("[e] could not read header\n");
        return;
    }

    StockItem *tmp = (StockItem *)malloc(n * sizeof(StockItem));

    if (fread(tmp, sizeof(stock[0]), n, src) != n) {
        printf("[e] could not read stock from %s\n", DST);
        return;
    }

    printf("[i] The stock contains %d products:\n", n);

    for (size_t i = 0; i < n; ++i) {
        printf("[i] - row %d: [%s],[%s],[%.2f],[%d],[%.2f]\n",
            i, tmp->brand, tmp->item, tmp->unit, tmp->qty, tmp->total);
    }

    fclose(src);
    free(tmp);

}

int main() {

    StockItem stock[MAXITEM] = { 0 };


    import_from_txt(stock);

    store_to_bin(stock);

    import_from_bin(stock);

    return 0;
}
