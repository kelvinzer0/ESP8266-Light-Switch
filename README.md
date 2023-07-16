# Web Server Switch

This is a simple Arduino sketch for controlling multiple switches using a web server. The switches are connected to GPIO pins on an ESP8266 module. The sketch sets up a WiFi access point and serves a web page that displays the status of each switch and allows the user to turn them on or off.

## Prerequisites

To run this code, you will need the following libraries:

- ESP8266WiFi: This library provides the necessary functions for connecting to a WiFi network.
- ESP8266WebServer: This library enables the creation of a web server on the ESP8266 module.

## Circuit Diagram

Make sure to connect the switches to the appropriate GPIO pins on the ESP8266 module. The code assumes that the switches are connected to GPIO pins D0 to D7.

## Usage

1. Connect your computer or mobile device to the WiFi network named "SKLR-01" with the password "12345678".
2. Open a web browser and enter the IP address "192.168.4.1" to access the web server.
3. The web page will display the status of each switch (ON or OFF).
4. Click on the "ON" or "OFF" link next to each switch to toggle its state.

## Code Explanation

1. The code starts by including the required libraries: `ESP8266WiFi.h` and `ESP8266WebServer.h`.
2. The network credentials (SSID and password) are defined as `ssid` and `password` variables.
3. An instance of the `ESP8266WebServer` class is created, listening on port 80.
4. The `handleRoot()` function is defined to generate the HTML page displaying the status of the switches.
5. The `switchOn()` and `switchOff()` functions are defined to turn on or off a specific switch based on its index.
6. In the `setup()` function:
   - The ESP8266 module is set up as a soft access point using the provided SSID and password.
   - The GPIO pins connected to the switches are configured as outputs.
   - The root URL ("/") is mapped to the `handleRoot()` function.
   - URLs for turning on and off each switch are mapped to the corresponding functions.
   - The web server is started.
7. In the `loop()` function, the web server is continuously checked for incoming requests.
