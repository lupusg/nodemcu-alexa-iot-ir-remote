#include <Arduino.h>
#include <ir_Mitsubishi.h>

const uint16_t kIrLed = 4;  // ESP8266 GPIO pin to use. Recommended: 4 (D2).
IRMitsubishiAC remote(kIrLed);

void setup() {
  Serial.begin(115200);
  remote.begin();
  remote.setFan(0);
  remote.setMode(kMitsubishi112Cool);
  remote.setTemp(24);
  remote.setVane(kMitsubishiAcVaneAuto);
  delay(200);
}

void loop() {
  remote.off();
  remote.send();
  delay(2000);
}