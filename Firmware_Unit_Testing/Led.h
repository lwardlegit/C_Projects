#ifndef LED_H
#define LED_H

typedef enum {
    LED_OFF,
    LED_ON,
    LED_BLINK
} LedState;

void blink(int duration, LedState LedState);

#endif