#include "MoistureSensor.h"

// Constructor to initialize sensor, power, and LED pins
MoistureSensor::MoistureSensor(PinName analogPin, PinName powerPin, PinName ledPin) 
    : sensor(analogPin), power(powerPin), led(ledPin) {
    power = 0;  // Initially turn off the sensor
    led = 0;    // Initially turn off the LED
}

// Function to read the moisture value
int MoistureSensor::readMoisture() {
    power = 1;  // Turn on the sensor
    ThisThread::sleep_for(1000ms);  // Wait for sensor to stabilize

    float sensorValue = sensor.read();  // Read the analog value (0.0 to 1.0)
    int rawValue = sensorValue * 4095;  // Convert to a 12-bit raw value

    power = 0;  // Turn off the sensor
    return rawValue;
}

// Function to convert raw sensor value to moisture percentage
int MoistureSensor::convertToMoisturePercentage(int rawValue, int dryValue, int wetValue) {
    if (rawValue > dryValue) rawValue = dryValue;
    if (rawValue < wetValue) rawValue = wetValue;

    float percent = ((float)(dryValue - rawValue) / (dryValue - wetValue)) * 100.0;
    return (int)percent;
}

// Function to get the moisture label (Dry, Moist, Wet)
const char* MoistureSensor::getMoistureLabel(int percentage) {
    if (percentage < 30) return "Dry";
    else if (percentage < 70) return "Moist";
    else return "Wet";
}

// Function to control the LED based on moisture level
void MoistureSensor::controlLedBasedOnMoisture(int percentage) {
    if (percentage < 30) {
        led = 1;  // Turn LED on (dry soil)
    } else {
        led = 0;  // Turn LED off (soil is moist or wet)
    }
}
