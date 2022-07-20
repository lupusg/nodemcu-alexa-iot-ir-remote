#include "iot-arduino-secrets.h"
#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>

const char kDeviceLoginName[]  = "79e87b3f-6747-44b2-8f50-c0149a3528c1";

const char kNetworkID[]       		= SECRET_SSID;    	  // Network kNetworkID (name)
const char kPassword[]        		= SECRET_PASS;        // Network password (use for WPA, or use as key for WEP)
const char kDeviceKey[]       		= SECRET_DEVICE_KEY;  // Secret device password

void OnAcSwitchChange();

CloudSwitch ac_switch;
WiFiConnectionHandler ArduinoIoTPreferredConnection(kNetworkID, kPassword);

void InitIotCloud(){
  ArduinoCloud.setBoardId(kDeviceLoginName);
  ArduinoCloud.setSecretDeviceKey(kDeviceKey);
  ArduinoCloud.addProperty(ac_switch, READWRITE, ON_CHANGE, OnAcSwitchChange);

  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

