#include "MotionSensor.h"
#include <stdlib.h>
#include <stdio.h>

int motion_sensor_read(void) {
    int val = rand() % 2; // randomly 0 or 1
    printf("Motion sensor read: %d\n", val);
    return val;
}
