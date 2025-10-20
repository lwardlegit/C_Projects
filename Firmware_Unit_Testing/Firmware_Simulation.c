/*
Author@@ Luther Wardle
Summary: Micro controller operations for testing purposes 
*/
#include <stdio.h>
#include <stdint.h> 



void blink(int miliseconds){
    int16_t start = 0;
    int led = 0;
    while (start <= miliseconds){
        led = !led; // in real life this is normally much too fast to see
        start ++;
    };
};

// we'll just say this has a name and a temp
struct Thermometer {
    int temp;
    char id[10];
};

struct Motion_detector{
    int detected;
    char name[30];
    char message[30];
};

// create struct instance
struct Motion_detector motion_detector = {0, "motion detector", "detecting"};

// create instance pointer
struct Motion_detector *motionptr = &motion_detector;

/*
Let's pretend we have some controller imagine a ESP32 and we want to perform a simple operation we can test
1. a hand is waved over the motion detector
2. this causes an LED to blink so the user knows the controller is activating
3. a thermometer is turned on to simulate the temperature
4. we store the temp and print it out

*/


int main(){
    printf("%s", "wave your hand over the controller to begin.");
    if (sizeof(motion_detector) != NULL){

    while (motion_detector.detected == 0){
    
        printf("%s", motionptr->message);
    };
}
    blink(3000);
    printf("%s", "begin taking the temp");


    return 0;
}
