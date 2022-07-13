#include "arduino_secrets.h"
#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>

const char DEVICE_LOGIN_NAME[]  = "79e87b3f-6747-44b2-8f50-c0149a3528c1";

const char SSID[]               = SECRET_SSID;    // Network SSID (name)
const char PASS[]               = SECRET_PASS;    // Network password (use for WPA, or use as key for WEP)
const char DEVICE_KEY[]  = SECRET_DEVICE_KEY;     // Secret device password

void onAcSwitchChange();

CloudSwitch ac_switch;

void initProperties(){
  ArduinoCloud.setBoardId(DEVICE_LOGIN_NAME);
  ArduinoCloud.setSecretDeviceKey(DEVICE_KEY);
  ArduinoCloud.addProperty(ac_switch, READWRITE, ON_CHANGE, onAcSwitchChange);
}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);
