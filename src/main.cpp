#include <Arduino.h>
#include <thing-ac-switch.h>
#include <iot-connection.h>

const uint32_t kBaudRate = 115200;

void setup() {
  Serial.begin(kBaudRate);
  InitAcSwitch();
  delay(1500);
  InitIotCloud();
}

void loop() {
  ArduinoCloud.update();
}

