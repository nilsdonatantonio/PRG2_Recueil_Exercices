#include <stdio.h>

#define DEFINE_TAB(name, type)                                                 \
                                                                               \
        struct name##_item {                                                   \
                int pos;                                                       \
                type val;                                                      \
        };                                                                     \
                                                                               \
        struct name##_item tab_##name[10];                                     \
                                                                               \
        static inline type get_##name##_val(int pos) {                         \
                return tab_##name[pos].val;                                    \
        }


DEFINE_TAB(entier, int);
DEFINE_TAB(str, char *);

int main() {
    tab_entier[0].pos = 0;
    tab_entier[0].val = 100;

    tab_str[0].pos = 0;
    tab_str[0].val = "Hello World !";

    printf("Value at position 0 in 'entier' table : %d\n", get_entier_val(0));

    printf("Value at position 0 in 'str' table : %s\n", get_str_val(0));

    return 0;
}
