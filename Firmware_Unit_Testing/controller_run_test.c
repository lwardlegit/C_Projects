#include "../Unity/src/unity.h"
#include "led.h"
#include "Thermometer.h"
#include "MotionSensor.h"
#include "../fff/fff.h"

/*
I had a hard time finding a testing framework that did basic unit testing and did function mocking together
I found a great combination using Unity and FFF for mocking functions
*/

DEFINE_FFF_GLOBALS;

// Controller under test
extern void controller_run(void);



// Global states (defined in controller.c)
extern LedState ledState;
extern ThermometerState thermState;
extern MotionSensorState motionState;

// ------------------ Mocks ------------------

static int blink_called = 0;
static int blink_duration = 0;
static int motion_detected = 0;
static int temp_called = 0;

FAKE_VOID_FUNC(blink, int, LedState);
FAKE_VALUE_FUNC(int, motion_sensor_read);
FAKE_VALUE_FUNC(float, read_temp);


void setUp(void) {
    blink_called = 0;
    blink_duration = 0;
    motion_detected = 0;
    temp_called = 0;
    ledState = LED_OFF;
    thermState = THERM_OFF;
    motionState = MOTIONSENSOR_OFF;

    RESET_FAKE(blink);
    RESET_FAKE(motion_sensor_read);
    RESET_FAKE(read_temp);
}

void tearDown(void) {}

// ------------------ Tests ------------------

void(controller_should_turn_off_motion_sensor)(void) {
    controller_run();
    TEST_ASSERT_EQUAL(MOTIONSENSOR_OFF, motionState);
}

void(controller_should_blink_on_motion_detected)(void){
    controller_run();
    TEST_ASSERT_EQUAL_INT(1, blink_called);
    TEST_ASSERT_EQUAL_INT(3000, blink_duration);
    TEST_ASSERT_EQUAL_INT(1, motion_detected);
}

void(controller_should_take_temperature_once)(void) {
    controller_run();
    TEST_ASSERT_EQUAL_INT(1, temp_called);
    TEST_ASSERT_EQUAL_FLOAT(22.5, 22.5);
}

void(controller_should_turn_off_peripherals_when_finished)(void) {
    controller_run();
    TEST_ASSERT_EQUAL(MOTIONSENSOR_OFF, motionState);
    TEST_ASSERT_EQUAL(THERM_OFF, thermState);
    TEST_ASSERT_EQUAL(LED_OFF, ledState);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(controller_should_turn_off_motion_sensor);
    RUN_TEST(controller_should_blink_on_motion_detected);
    RUN_TEST(controller_should_take_temperature_once);
    RUN_TEST(controller_should_turn_off_peripherals_when_finished);
    return UNITY_END();
}

