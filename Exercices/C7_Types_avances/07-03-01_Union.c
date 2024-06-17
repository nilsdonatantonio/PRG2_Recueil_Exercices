#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef union {
    float temp;
    float humidity;
    int occupation;
} DonneesCapteur;

typedef enum {
    TEMPERATURE,
    HUMIDITE,
    OCCUPATION
} TypeDeCapteur;

typedef struct {
    TypeDeCapteur type;
    DonneesCapteur data;
    time_t timestamp;
} Capteur;

void show_status(const Capteur *capteur) {
    printf("[%ld] ", capteur->timestamp);
    switch (capteur->type) {
    case TEMPERATURE:
        printf("Température : %.2f°C\n", capteur->data.temp);
        break;
    case HUMIDITE:
        printf("Humidité : %.2f%\n", capteur->data.humidity);
    case OCCUPATION:
        printf("Occupation : %d personnes\n", capteur->data.occupation);
    }
}

int main(int argc, char *argv[]) {
    Capteur capteur;
    capteur.type = TEMPERATURE;
    capteur.data.temp = 23.5;
    capteur.timestamp = time(NULL);
    show_status(&capteur);
    return 0;

}
