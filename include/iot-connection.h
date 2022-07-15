#ifndef NODEMCU_ALEXA_IOT_IR_REMOTE_INCLUDE_IOT_CONNECTION_H_
#define NODEMCU_ALEXA_IOT_IR_REMOTE_INCLUDE_IOT_CONNECTION_H_

#include "arduino-secrets.h"

void InitIotCloud(){
  InitProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

#endif //NODEMCU_ALEXA_IOT_IR_REMOTE_INCLUDE_IOT_CONNECTION_H_
