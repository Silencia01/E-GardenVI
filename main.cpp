#include "mbed.h"
#include "MoistureSensor.h"  // Include the custom MoistureSensor class
#include "SerialCom.h"       // Include custom Serial Communication functions
#include <cstdio>            // For sprintf

// Create instances of the MoistureSensor class for two sensors
MoistureSensor sensor1(A0, D7);  // Sensor 1 on analog pin A0 and power pin D7
MoistureSensor sensor2(A1, D6);  // Sensor 2 on analog pin A1 and power pin D6


int main() {
    pc.write("Starting Moisture Calibration Test...\n", 37);

    while (true) {
        // Read the raw moisture value for both sensors
        int raw1 = sensor1.readMoisture();
        int percent1 = sensor1.convertToMoisturePercentage(raw1);
        const char* label1 = sensor1.getMoistureLabel(percent1);

        int raw2 = sensor2.readMoisture();
        int percent2 = sensor2.convertToMoisturePercentage(raw2);
        const char* label2 = sensor2.getMoistureLabel(percent2);

        // Print the results to the serial monitor
        char buffer[100];
        int len = sprintf(buffer, "Sensor 1: Raw = %d | %d%% | %s\n", raw1, percent1, label1);
        pc.write(buffer, len);

        len = sprintf(buffer, "Sensor 2: Raw = %d | %d%% | %s\n\n", raw2, percent2, label2);
        pc.write(buffer, len);

        ThisThread::sleep_for(5s);  // Wait before the next reading cycle
    }
}
