#ifndef THERMOMETER_H
#define THERMOMETER_H

typedef enum {
    THERM_OFF,
    THERM_ON
} ThermometerState;

float read_temp(void);

#endif
