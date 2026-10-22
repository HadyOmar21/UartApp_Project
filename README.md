Embedded Systems Project Report: UART LED and Push-Button Control
1. Introduction
This project demonstrates UART serial communication and digital input/output using an Arduino Uno based on the ATmega328P. A computer sends text commands over UART to control an LED. The application also monitors a push-button and reports button-state changes through UART.

Supported commands:
- led_on — turn the LED on.
- led_off — turn the LED off.
The application reports button_pressed and button_released when it detects a button-state change. Commands are terminated by a carriage return (\r) or line feed (\n).
2. Project Code:

GitHub Repository:
https://github.com/HadyOmar21/UartApp_Project

Local Code Directory:
[Code][Code/main]

Main source files:
- main.ino — application initialization, button monitoring, and UART command processing.
- uart.ino / uart.h — UART communication functions.
- led.ino / led.h — LED control functions.
- hal_gpio.ino / hal_gpio.h — GPIO configuration and pin read/write operations.

3. Test Cases
[Test Cases](Tests/test_cases.robot)

The test plan covers valid LED commands, invalid and overlong commands, button press/release reporting, and basic integration.

4. Bill of Materials (BOM)
- BOM: [bom.csv](bom/bom.csv)
- Optimized BOM: [optimized_bom.csv](bom/optimized_bom.csv)

5. Video Demonstration:

 [Video Test Demonestration](Video\Project_Test_Video.mp4).

6. Design :
 [Design Document](Design\Project_Design.md)

7. Hardware Design 

 [hardwar_Design] [Schematic.png]


