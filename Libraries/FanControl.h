#ifndef FAN_CONTROL_H
#define FAN_CONTROL_H

#include "mbed.h"

// === Pin Setup ===
extern AnalogIn tempSensor;     // LM35 analog temperature sensor
extern DigitalOut fanRelay;     // Relay module controlling fan (LOW = ON, HIGH = OFF)

// === Threshold ===
extern const int TEMP_THRESHOLD; // Temperature threshold in °C

// === Function Prototypes ===
void initializeFanControl();
void updateFanControl();

#endif
