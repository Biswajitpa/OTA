#include <WiFi.h>
#include <ArduinoOTA.h>

const char* ssid = "Biswajit";          // WiFi SSID
const char* password = "12345678"; // WiFi Password

// Give each ESP32 a unique name (edit this per device)
const char* deviceName = "ESP32S_biswajit";  

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  // Wait until connected
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Set custom OTA hostname
  ArduinoOTA.setHostname(deviceName);

  // Start OTA
  ArduinoOTA.begin();
  Serial.print("OTA Ready. Device Hostname: ");
  Serial.println(deviceName);
}

void loop() {
  // Handle OTA events
  ArduinoOTA.handle();
}
