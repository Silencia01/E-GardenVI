// SerialCom.h

#ifndef SERIALCOM_H
#define SERIALCOM_H

#include "mbed.h"

// Define the serial communication globally in this file
extern UnbufferedSerial pc;  // USB serial port, can be connected to your Nucleo USB port for communication

// Function to send messages over serial
void sendSerialMessage(const char* message);

#endif // SERIALCOM_H