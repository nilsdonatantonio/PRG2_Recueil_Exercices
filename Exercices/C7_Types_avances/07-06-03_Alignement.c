#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#pragma pack(1)
typedef struct {
    char c1;
    int i;
    char c2;
} AlignedData;

void print_offsets(AlignedData data) {
    printf("Offset of char c1 = %ld\n", offsetof(AlignedData, c1));
    printf("Offset of int i = %ld\n", offsetof(AlignedData, i));
    printf("Offset of char c2 = %ld\n", offsetof(AlignedData, c2));

    printf("\n");
}

int main() {
    AlignedData data = { .c1 = 'a', .i = 3, .c2 = 'b' };

    print_offsets(data);

}
