#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "SKLR-01";
const char* password = "12345678";

ESP8266WebServer server(80);

void handleRoot() {
  String html = "<html><body>";
  html += "<h1>Saklar Web Server</h1>";

  for (int i = 0; i < 8; i++) {
    int saklarStatus = digitalRead(D0 + i);
    html += "<p>Saklar ";
    html += i + 1;
    html += ": ";
    html += saklarStatus == HIGH ? "ON" : "OFF";
    html += "</p>";
    html += "<p><a href=\"/on/";
    html += i;
    html += "\">ON</a> | <a href=\"/off/";
    html += i;
    html += "\">OFF</a></p>";
  }
  
  html += "</body></html>";
  server.send(200, "text/html", html);
}

void saklarOn(int index) {
  if (index >= 0 && index < 8) {
    digitalWrite(D0 + index, HIGH);
  }
  server.sendHeader("Location", "/");
  server.send(302, "text/plain", "");
}

void saklarOff(int index) {
  if (index >= 0 && index < 8) {
    digitalWrite(D0 + index, LOW);
  }
  server.sendHeader("Location", "/");
  server.send(302, "text/plain", "");
}

void setup() {
  WiFi.softAP(ssid, password);
  for (int i = 0; i < 8; i++) {
    pinMode(D0 + i, OUTPUT);
    digitalWrite(D0 + i, LOW);
  }
  server.on("/", handleRoot);
  
  for (int i = 0; i < 8; i++) {
    String onURL = "/on/" + String(i);
    String offURL = "/off/" + String(i);
    server.on(onURL.c_str(), [i]() { saklarOn(i); });
    server.on(offURL.c_str(), [i]() { saklarOff(i); });
  }

  server.begin();
}

void loop() {
  server.handleClient();
}
