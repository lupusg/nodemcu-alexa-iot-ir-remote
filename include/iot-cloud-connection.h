/**
 * NodeMCU Alexa IOT Infrared Remote
 *
 * Convert old devices that are not compatible
 * with Alexa into compatible ones using infrared
 * signals.
 *
 * NodeMCU IOT Platform
 *
 * @file iot-cloud-connection.h
 *
 * @brief The file that handles the connection to the IOT cloud.
 *
 * @date July 16, 2022
 *
 * @author Vlad-Marian Lupu
 */

#ifndef	NODEMCU_ALEXA_IOT_IR_REMOTE_INCLUDE_IOT_CLOUD_CONNECTION_H_
#define NODEMCU_ALEXA_IOT_IR_REMOTE_INCLUDE_IOT_CLOUD_CONNECTION_H_

#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>
#include "iot-arduino-secrets.h"

const char kDeviceLoginName[]  = "79e87b3f-6747-44b2-8f50-c0149a3528c1";

const char kNetworkID[]       		= SECRET_SSID;    	  // Network kNetworkID (name)
const char kPassword[]        		= SECRET_PASS;        // Network password (use for WPA, or use as key for WEP)
const char kDeviceKey[]       		= SECRET_DEVICE_KEY;  // Secret device password

void OnAcSwitchChange();

CloudSwitch ac_switch;
WiFiConnectionHandler ArduinoIoTPreferredConnection(kNetworkID, kPassword);

/**
 * IOT Cloud initialization.
 */
void InitIotCloud(){
  ArduinoCloud.setBoardId(kDeviceLoginName);
  ArduinoCloud.setSecretDeviceKey(kDeviceKey);
  ArduinoCloud.addProperty(ac_switch, READWRITE, ON_CHANGE, OnAcSwitchChange);

  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

#endif //NODEMCU_ALEXA_IOT_IR_REMOTE_INCLUDE_IOT_CLOUD_CONNECTION_H_