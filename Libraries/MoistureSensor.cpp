#include "MoistureSensor.h"
#include "SerialCom.h"

MoistureSensor::MoistureSensor(PinName analogPin, PinName powerPin) : sensor(analogPin), power(powerPin) {
    power = 0;  // Initially turn off the sensor
}

int MoistureSensor::readMoisture() {
    power = 1;  // Turn on the sensor
    ThisThread::sleep_for(1000ms);  // Wait for sensor to stabilize

    float sensorValue = sensor.read();  // Read the analog value (0.0 to 1.0)
    int rawValue = sensorValue * 4095;  // Convert to a 12-bit raw value

    power = 0;  // Turn off the sensor
    return rawValue;
}

int MoistureSensor::convertToMoisturePercentage(int rawValue, int dryValue, int wetValue) {
    if (rawValue > dryValue) rawValue = dryValue;
    if (rawValue < wetValue) rawValue = wetValue;

    float percent = ((float)(dryValue - rawValue) / (dryValue - wetValue)) * 100.0;
    return (int)percent;
}

const char* MoistureSensor::getMoistureLabel(int percentage) {
    if (percentage < 30) return "Dry";
    else if (percentage < 70) return "Moist";
    else return "Wet";
}
