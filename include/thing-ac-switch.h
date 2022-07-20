/**
 * @file thing-ac-switch.h
 *
 * @brief The file that handles what the IOT AC Switch does.
 *
 * @author Vlad-Marian Lupu
 *
 * @date July 16, 2022
 */

#ifndef NODEMCU_ALEXA_IOT_IR_REMOTE_INCLUDE_THING_AC_SWITCH_H_
#define NODEMCU_ALEXA_IOT_IR_REMOTE_INCLUDE_THING_AC_SWITCH_H_

#include <ir_Mitsubishi.h>
#include <iot-cloud-connection.h>
#include <arduino-config.h>

IRMitsubishiAC remote(IR_TRANSMITTER_PIN);

//TODO: Delete this.
void InitAcSwitch(){
  remote.begin();
  remote.setFan(0);
  remote.setMode(kMitsubishi112Cool);
  remote.setTemp(24);
  remote.setVane(kMitsubishiAcVaneAuto);
}
//TODO: Delete also this.
void OnAcSwitchChange()  {
  if(ac_switch){
	Serial.println("[AC]Switch works");
	remote.on();
	remote.send();
  } else {
	remote.off();
	remote.send();
  }
}

#endif //NODEMCU_ALEXA_IOT_IR_REMOTE_INCLUDE_THING_AC_SWITCH_H_
