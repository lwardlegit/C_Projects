#include "Led.h"
#include <stdio.h>

void blink(int duration, LedState ledState){
    int count = 0;
    while (count <= duration){
        ledState = LED_BLINK;
        count += 1;
    };
    ledState = LED_OFF;
};