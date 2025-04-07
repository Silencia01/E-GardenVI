## E-Garden Project - Smart Garden Monitoring System 
Sajini | Tooba | Taye 

This is an embedded smart garden system designed and developed to monitor and help the user maintain optimal plant growth conditions. 
Built using a Nucleo board and Keil Studio, this system integrates a temperature sensor, two moisture sensors, a Light Sensor, multiple LEDs, a DC Fan and a relay. 

## Delivered Features

-  ##  LM35 Temperature Sensing and DC Cooling Fan
  - Activates DC fan when temperature exceeds set threshold

-  ##  Dual Moisture Sensing Sensing
  - Each sensor controls a corresponding LED
  - LED turns on when soil is dry

-  ##  Light Sensing with LED Lighting 
  - Turns on LED when light levels are low

-  ##  Modular Code Architecture 
  - Sensor and actuator logic separated into reusable library files
  - Clean integration in `main.cpp`

-  ##  Battery Operation - No Connected Computer Required 
  - Seperate hardware and plant enclosures with a large battery bank to power Nucleo and sensors 
  - Clean, modular code that runs in a continuous loop, monitoring each sensor in step.
  - Serial Monitor ouput can be read with a connected computer, put all functionality can be done without a connected laptop and the system can startup and work at the touch of the power button **(Something I'm personally most proud of)**


##  Testing Approach

All features were first validated in isolation inside the `DevelopmentTestCode/` folder. Once working as expected, logic was transferred into `.cpp` and `.h` files inside the `Libraries/` directory for reuse and clarity.

## Our 'Software Next Steps

Although the core system works as intended with modular code and basic environmental feedback, several features were explored but not fully implemented in this build due to our skill and unfamiliarity, time constraints, or complexity. These present opportunities for future development:
🔸 Real-Time Clock (RTC)

  Purpose: Track time-based events, such as light/dark cycles or logging sensor data periodically.

  Progress: RTC integration was partially implemented. Basic timekeeping worked, but full integration with logging was paused due to flash-saving errors and time constraints

  Next Step: Save timestamps for events like watering or sensor checks.

🔸 MicroSD Card Logging

  Purpose: Store sensor data over time for offline analysis.

  Challenge: Communication with the module was unreliable during testing. Micro-SD Cards could initalise, but unable to read - mentioning MicroSD Write protection on cards that did not have write protection. So maybe the code was applying write protection?

   Next Step: Debug SPI communication or consider switching to internal flash or a serial output to PC/app.

🔸 Display Integration

  Purpose: Provide local feedback to the user (e.g., temperature, moisture levels).

  Challenge: Complete inability to get the I2C communication working and connection to the display. The display did light up with Squares on the screen, but nothing else. Also, the constant fighting with libraies and with hinsight, trying to use STM32 and MBED libraries didn't help.

  Next Step: Retry I2C with Display.h 

🔸 Automated Watering System

  Purpose: Automatically water plants when soil moisture drops below a certain threshold.

  Next Step: Using our included water irregation pump and large enclosure to house automated watering. 

## Personal Reflections

This project served as an important step in learning different, non arduino embedded systems, modular C++ code architecture, real-time sensor handling, and teamwork. While some ideas couldn’t be realised this time, the current system is a functional and adaptable base that could grow into a fully autonomous smart garden.
