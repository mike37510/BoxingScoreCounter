# Boxing Score Counter with ESP32-C3 Mini

## Overview

This project implements a scoring system for French boxing (Savate) using an ESP32-C3 Mini microcontroller. The system allows referees or judges to increment points using three buttons, each representing a specific point value. A reset button is also included to reset the score. The current score is displayed in real-time on a TM1637 4-digit display.

---

## Features

- **Scoring Buttons**: 
  - Button 1: Adds **1 point** to the score.
  - Button 2: Adds **2 points** to the score.
  - Button 3: Adds **4 points** to the score.
- **Reset Button**: Resets the score to zero.
- **Real-Time Display**: A TM1637 display shows the current score.
- **Compact Design**: Utilizes the ESP32-C3 Mini and built-in pull-up resistors for simplicity.

---

## Components

### Hardware
- **Microcontroller**: ESP32-C3 Mini
- **Display**: TM1637 4-digit 7-segment display
- **Buttons**: 4 push buttons (3 for scoring, 1 for reset)
- **Power Supply**: 3.3V for ESP32-C3 and TM1637 module

### Tools
- Arduino IDE or PlatformIO
- USB-to-Serial interface for flashing the ESP32-C3 Mini

---

## Wiring Diagram

| Component         | Pin/Connection  | ESP32-C3 GPIO |
|--------------------|-----------------|---------------|
| **TM1637 CLK**     | CLK             | GPIO1         |
| **TM1637 DIO**     | DIO             | GPIO2         |
| **Button 1**       | One terminal    | GPIO3         |
| **Button 2**       | One terminal    | GPIO4         |
| **Button 3**       | One terminal    | GPIO5         |
| **Reset Button**   | One terminal    | GPIO6         |
| **Other Button Pins** | Ground (GND)  |               |

**Note**: The buttons are connected between the respective GPIO pins and GND. Internal pull-up resistors are enabled in the firmware.

---

## Software

### Dependencies

The following library is required for this project:
- [TM1637Display](https://github.com/avishorp/TM1637)

### Installation

1. Clone this repository:
   ```bash
   git clone https://github.com/your-username/boxing-score-counter.git
   cd boxing-score-counter
Open the .ino file in Arduino IDE or PlatformIO.
Install the required library (TM1637Display).
Flash the code to your ESP32-C3 Mini.
Logic Overview
The firmware reads the button states and increments the score based on the button pressed. The TM1637 display is updated in real-time. The reset button clears the score.

Buttons are configured with pull-up resistors.
When a button is pressed, its state is LOW.
Points are added to the score based on the button pressed:
Button 1 → +1 point
Button 2 → +2 points
Button 3 → +4 points
The reset button sets the score back to zero.
The TM1637 display shows the current score in real-time.
Future Enhancements
Add a battery-powered option for portability.
Incorporate a buzzer to signal scoring events.
Add wireless capabilities (e.g., Bluetooth) for remote score tracking.
Add a timer to track rounds or match duration.
License
This project is licensed under the MIT License. See the LICENSE file for details.

Acknowledgments
Thanks to the open-source community for providing libraries and resources to make this project possible.


