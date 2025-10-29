#include "led.h"
#include "Thermometer.h"
#include "MotionSensor.h"
#include <stdio.h>

LedState ledState = LED_OFF;
ThermometerState thermState = THERM_OFF;
MotionSensorState motionState = MOTIONSENSOR_OFF;

// --- Controller logic ---
void controller_run(void) {
    motionState = MOTIONSENSOR_ON;
    thermState = THERM_ON;
    ledState = LED_OFF;

    if (motion_sensor_read() >= 0) { // ✅ FIX: call the function!
        ledState = LED_ON;
        blink(3000, ledState);
    }

    float temp = read_temp();
    printf("the temp is: %f\n", temp);

    // Turn off peripherals
    motionState = MOTIONSENSOR_OFF;
    thermState = THERM_OFF;
    ledState = LED_OFF;
}
