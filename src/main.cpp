#include <Arduino.h>
#include <thing-ac-switch.h>
#include <iot-connection.h>

void setup() {
  Serial.begin(115200);
  InitAcSwitch();
  delay(1500);
  InitIotCloud();
}

void loop() {
  ArduinoCloud.update();
}

