#ifndef NODEMCU_ALEXA_IOT_IR_REMOTE_INCLUDE_THING_AC_SWITCH_H_
#define NODEMCU_ALEXA_IOT_IR_REMOTE_INCLUDE_THING_AC_SWITCH_H_

#include <ir_Mitsubishi.h>
#include <iot-thing-properties.h>

const uint16_t kIrLedPin = 4;  // ESP8266 GPIO pin to use. Recommended: 4 (D2).

IRMitsubishiAC remote(kIrLedPin);

void InitAcSwitch(){
  remote.begin();
  remote.setFan(0);
  remote.setMode(kMitsubishi112Cool);
  remote.setTemp(24);
  remote.setVane(kMitsubishiAcVaneAuto);
}

void OnAcSwitchChange()  {
  if(ac_switch){
	remote.on();
	remote.send();
  } else {
	remote.off();
	remote.send();
  }
}

#endif //NODEMCU_ALEXA_IOT_IR_REMOTE_INCLUDE_THING_AC_SWITCH_H_
