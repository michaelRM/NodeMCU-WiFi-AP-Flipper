#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <Wire.h>
#include <U8g2lib.h>

// Set your desired SSID and Password
const char* ssid = "NodeMCU-AP";
const char* password = "12345678";

// Initialize the OLED display using software I2C
U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ 14, /* data=*/ 12, U8X8_PIN_NONE);

ESP8266WebServer server(80);

void setup() {
  Serial.begin(115200);  // Initialize serial communication
  u8g2.begin();         // Initialize the OLED display

  // Set up the NodeMCU as an Access Point
  WiFi.softAP(ssid, password);

  // Start the server
  server.on("/", handleRoot); // Define the handling function for the root path
  server.begin();

  // Display initial AP information
  displayAPInfo();
}

void loop() {
  // Handle any incoming client requests
  server.handleClient();

  // Periodically update the OLED display with AP info
  static unsigned long lastUpdate = 0;
  if (millis() - lastUpdate > 10000) {  // Update every 10 seconds
    lastUpdate = millis();
    displayAPInfo();
  }
}

void handleRoot() {
  String clientName = server.client().remoteIP().toString();
  displayMessage("Client", clientName.c_str());

  String message = "<html><body><h1>Hello from NodeMCU!</h1><p>Welcome to the AP!</p></body></html>";
  server.send(200, "text/html", message);

  delay(5000);  // Keep client info on screen
  displayAPInfo();
}

void displayMessage(const char* line1, const char* line2) {
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_6x10_tf);
  u8g2.drawStr(0, 12, line1);
  u8g2.drawStr(0, 24, line2);
  u8g2.sendBuffer();
}

void displayAPInfo() {
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_6x10_tf);
  u8g2.drawStr(0, 12, "SSID:");
  u8g2.drawStr(36, 12, ssid);
  u8g2.drawStr(0, 24, "Pass:");
  u8g2.drawStr(36, 24, password);
  u8g2.drawStr(0, 36, "IP:");
  u8g2.drawStr(36, 36, WiFi.softAPIP().toString().c_str());
  u8g2.sendBuffer();
}
