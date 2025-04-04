// SerialCom.cpp

#include "SerialCom.h"

// USB Serial Communication setup with baud rate (e.g., 9600)
UnbufferedSerial pc(USBTX, USBRX, 115200);  // USBTX and USBRX are default pins for serial communication on many Nucleo boards

// Function to send a message over serial
void sendSerialMessage(const char* message) {
    pc.write("\n", 1);  // Newline for better readability
    pc.write(message, strlen(message));  // Sends the message
    ThisThread::sleep_for(2000ms);  // Wait for 2 seconds before sending the next message
}