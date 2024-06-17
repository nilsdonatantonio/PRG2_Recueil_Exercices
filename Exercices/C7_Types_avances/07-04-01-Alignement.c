#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

typedef struct __attribute__((packed)) {
    uint16_t id;
    time_t timestamp;
    uint8_t type;
    float val;
} Sensor;

void show_sensor(Sensor sensor) {
    printf("ID : %u\n", sensor.id);
    printf("Time : %u\n", sensor.timestamp);
    printf("Type : %u\n", sensor.type);
    printf("Value : %.5f\n", sensor.val);
}

int main() {

    Sensor sensor;
    sensor.id = 12345;
    sensor.timestamp = 161803398;
    sensor.type = 2;
    sensor.val = 3.14159;

    show_sensor(sensor);

    return 0;
}
