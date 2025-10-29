#include "Thermometer.h"
#include <stdio.h>
#include <stdlib.h>

float read_temp(void) {
    float t = (float)rand() / RAND_MAX * 25.0f;
    printf("Reading temperature: %.2f\n", t);
    return t;
}
