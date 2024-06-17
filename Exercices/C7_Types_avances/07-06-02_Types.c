#include <stdio.h>
#include <stdlib.h>

typedef union Data {
    int _int;
    float _float;
    char _char[20];
} Data;

typedef enum DataType {
    INT,
    FLOAT,
    STRING
} DataType;

typedef struct DataContainer {
    DataType type;
    Data data;

} DataContainer;


void print_data(const DataContainer data) {
    printf("Data contient : ");
    switch (data.type) {
    case INT:
        printf("%d", data.data._int);
        break;

    case FLOAT:
        printf("%f", data.data._float);
        break;

    case STRING:
        printf("%s", data.data._char);
        break;

    default:
        break;
    }
}

int main() {

    DataContainer data[3] = {
        {.type = INT, .data._int = 4},
        {.type = FLOAT, .data._float = 2.2f},
        {.type = STRING, .data._char = "Salut bel homme"}
    };

    for (size_t i = 0; i < 3; ++i) {
        print_data(data[i]);
        printf("\n");
    }
}
