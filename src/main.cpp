#include <Arduino.h>
//#include <IRremoteESP8266.h>
#include <ir_Mitsubishi.h>
#include "arduino_secrets.h"
#include "thingProperties.h"

const uint16_t kIrLed = 4;  // ESP8266 GPIO pin to use. Recommended: 4 (D2).
IRMitsubishiAC remote(kIrLed);

void setup() {
  Serial.begin(115200);
  remote.begin();
  remote.setFan(0);
  remote.setMode(kMitsubishi112Cool);
  remote.setTemp(24);
  remote.setVane(kMitsubishiAcVaneAuto);
  delay(1500);

  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
}

void onAcSwitchChange()  {
  if(ac_switch){
	remote.on();
	remote.send();
  } else {
	remote.off();
	remote.send();
  }
}