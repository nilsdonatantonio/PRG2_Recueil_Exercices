#include <stdio.h>
#include <stdlib.h>

typedef union {
    int _int;
    float _float;
    char _char[50];
} OptionalData;

typedef enum {
    NONE,
    INT,
    FLOAT,
    STRING
} DataType;

typedef struct {
    DataType type;
    OptionalData data;
} OptionalField;

typedef struct {
    char name[50];
    int age;
    OptionalField optionalField;
} Person;

void print_person(const Person person) {
    printf("Name : %s\n", person.name);
    printf("Age  : %d\n", person.age);
    switch (person.optionalField.type) {
    case NONE:
        break;
    case INT:
        printf("Optional field : %d", person.optionalField.data._int);
        break;
    case FLOAT:
        printf("Optional field : %f\n", person.optionalField.data._float);
        break;
    case STRING:
        printf("Optional field : %s\n", person.optionalField.data._char);
        break;
    default:
        break;
    }
}


int main() {
    Person person[3] = {
        {.name = "Nils", .age = 24, .optionalField.type = NONE},
        {.name = "Brad", .age = 24, .optionalField.type = INT, .optionalField.data._int = 4},
        {.name = "Max", .age = 24, .optionalField.type = FLOAT, .optionalField.data._float = 2.2f}
    };

    for (size_t i = 0; i < 3; ++i) {
        print_person(person[i]);
        printf("\n");
    }

    return 0;
}
