#include <stdio.h>
#define WIDTH 7
#define HEIGHT 6


// int main() {
//     int tab[HEIGHT][WIDTH];

//     for (size_t i = 0; i < HEIGHT; ++i) {
//         for (size_t j = 0; j < WIDTH; ++j) {
//             tab[i][j] = (j + 1) * (i + 1);
//         }
//     }


//     int *tab1d = (int *)tab;

//     for (size_t i = 0; i < HEIGHT; ++i) {
//         for (size_t j = 0; j < WIDTH; ++j) {
//             printf("%2d ", tab1d[i * WIDTH + j]);
//         }
//         printf("\n");
//     }


// }

int main(void) {

    //Solution 1
    // int tab[WIDTH * HEIGHT];

    // for (size_t i = 0; i < HEIGHT; ++i) {
    //     for (size_t j = 0; j < WIDTH; ++j) {
    //         tab[i * WIDTH + j] = (i + 1) * (j + 1);
    //     }
    // }

    // for (size_t i = 0; i < HEIGHT; ++i) {
    //     for (size_t j = 0; j < WIDTH; ++j) {
    //         printf("%d ", tab[i * WIDTH + j]);
    //     }
    //     printf("\n");
    // }

    // printf("\n");

    //Solution 2
    // int tab[HEIGHT][WIDTH];

    // for (size_t i = 0; i < HEIGHT; ++i) {
    //     for (size_t j = 0; j < WIDTH; ++j) {
    //         tab[i][j] = (i + 1) * (j + 1);
    //     }
    // }

    // for (size_t i = 0; i < HEIGHT; ++i) {
    //     for (size_t j = 0; j < WIDTH; ++j) {
    //         printf("%d ", tab[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");

    //Solution 3
    // int tab1d[HEIGHT * WIDTH];

    // for (size_t i = 0; i < HEIGHT; ++i) {
    //     for (size_t j = 0; j < WIDTH; ++j) {
    //         tab1d[i * WIDTH + j] = (i + 1) * (j + 1);
    //     }
    // }

    // int(*tab2d)[WIDTH] = (int(*)[WIDTH])tab1d;

    // for (size_t i = 0; i < HEIGHT; ++i) {
    //     for (size_t j = 0; j < WIDTH; ++j) {
    //         printf("%d ", tab2d[i][j]);
    //     }
    //     printf("\n");
    // }

    // printf("\n");

    //Solution 4
    int tab2d[HEIGHT][WIDTH];

    for (size_t i = 0; i < HEIGHT; ++i) {
        for (size_t j = 0; j < WIDTH; ++j) {
            tab2d[i][j] = (i + 1) * (j + 1);
        }
    }

    int *tab1d = (int *)tab2d;

    for (size_t i = 0; i < HEIGHT; ++i) {
        for (size_t j = 0; j < WIDTH; ++j) {
            printf("%d ", tab1d[i * WIDTH + j]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}
