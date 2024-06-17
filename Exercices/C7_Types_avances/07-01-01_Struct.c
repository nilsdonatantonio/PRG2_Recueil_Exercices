#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 256
#define MAXITEM 10

typedef struct {
    char title[MAXLEN];
    char author[MAXLEN];
    int  publishing_year;
    int stock;
} Book;

Book add_book(char *title, char *author, int pub_year, int stock) {
    Book book;
    strcpy(book.title, title);
    strcpy(book.author, author);
    book.publishing_year = pub_year;
    book.stock = stock;

    return book;
}

void show_book(const Book book) {
    printf("!-----------Entry-----------!\n");
    printf("Title           : %s\n", book.title);
    printf("Author          : %s\n", book.author);
    printf("Publishing year : %d\n", book.publishing_year);
    printf("In stock        : %d\n", book.stock);
    printf("\n\n");
}

void borrow_book(Book *book) {
    book->stock -= 1;
}

void return_book(Book *book) {
    book->stock += 1;
}

int main() {
    Book inventory[MAXITEM];

    inventory[0] = add_book("Factocrum", "Charles Bukowski", 1948, 30);
    show_book(inventory[0]);

    borrow_book(&(inventory[0]));

    show_book(inventory[0]);

    return_book(&(inventory[0]));

    show_book(inventory[0]);

    return 0;

}
