# NodeMCU ESP8266 as a Network Testing Tool

## Overview
This project turns a NodeMCU ESP8266, equipped with an integrated 0.96'' OLED Display, into a multifunctional network testing device. It's designed for integration with Flipper Zero, enhancing its capabilities for network testing and security analysis. The current implementation serves as a Wi-Fi Access Point, displaying connected clients on the OLED screen.

## Features
- **Wi-Fi Access Point**: Allows devices to connect and displays their connection status on the OLED.
- **Flipper Zero Integration** (Upcoming): Enabling advanced network testing operations via GPIO connections.
- **Real-Time Client Display**: Shows connected clients on the OLED display in real-time.

## Hardware Requirements
- NodeMCU ESP8266 with a 0.96'' OLED Display (I got mine for like $6 on AliExpress)

## Software Requirements
- Arduino IDE
- ESP8266WiFi library
- ESP8266WebServer library
- U8g2lib library

## Installation
1. **Setup the Arduino Environment**: Install the Arduino IDE and the required libraries.
2. **Load and Upload the Sketch**: Open the `ESP8266_WiFi_Analyzer.ino` file in the Arduino IDE and upload it to your NodeMCU.

## Usage
- **Connecting to the AP**: Search for the Wi-Fi network named "NodeMCU-AP" and connect using the provided credentials.
- **Viewing Connected Clients**: Observe the OLED display on the NodeMCU for real-time client information.

## License
This project is licensed under the GNU General Public License v3.0 - see the LICENSE file for details.

## Acknowledgments
- Thanks to the open-source community for continuous inspiration and support.

