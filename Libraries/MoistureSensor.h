#ifndef MOISTURESENSOR_H
#define MOISTURESENSOR_H

#include "mbed.h"

class MoistureSensor {
public:
    MoistureSensor(PinName analogPin, PinName powerPin, PinName ledPin); // Constructor to initialize sensor with analog, power, and LED pins

    int readMoisture(); // Function to read the moisture level from the sensor
    int convertToMoisturePercentage(int rawValue, int dryValue = 2150, int wetValue = 1200); // Convert raw value to percentage
    const char* getMoistureLabel(int percentage); // Get label based on moisture percentage
    void controlLedBasedOnMoisture(int percentage); // Function to control LED based on moisture

private:
    AnalogIn sensor;  // The analog sensor input
    DigitalOut power; // The digital output pin to control sensor power
    DigitalOut led;   // The LED pin to indicate dry soil
};

#endif // MOISTURESENSOR_H
