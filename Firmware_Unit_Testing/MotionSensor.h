#ifndef MOTIONSENSOR_H
#define MOTIONSENSOR_H

typedef enum {
    MOTIONSENSOR_OFF,
    MOTIONSENSOR_ON
} MotionSensorState;

int motion_sensor_read(void);

#endif
