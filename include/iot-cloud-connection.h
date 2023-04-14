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

#include "arduino-config.h"
#include "custom-switches.h"

WiFiConnectionHandler ArduinoIoTPreferredConnection(SECRET_SSID, SECRET_PASS);

/**
 * IOT Cloud initialization.
 */
void InitIotCloud(){
  ArduinoCloud.setBoardId(DEVICE_LOGIN_NAME);
  ArduinoCloud.setSecretDeviceKey(SECRET_DEVICE_KEY);

  ArduinoCloud.addProperty(custom_switch1, READWRITE, ON_CHANGE, OnCustomSwitch1Change);
  ArduinoCloud.addProperty(custom_switch2, READWRITE, ON_CHANGE, OnCustomSwitch2Change);
  ArduinoCloud.addProperty(custom_switch3, READWRITE, ON_CHANGE, OnCustomSwitch3Change);
  ArduinoCloud.addProperty(custom_switch4, READWRITE, ON_CHANGE, OnCustomSwitch4Change);
  ArduinoCloud.addProperty(custom_switch5, READWRITE, ON_CHANGE, OnCustomSwitch5Change);
  ArduinoCloud.addProperty(custom_switch6, READWRITE, ON_CHANGE, OnCustomSwitch6Change);
  ArduinoCloud.addProperty(custom_switch7, READWRITE, ON_CHANGE, OnCustomSwitch7Change);
  ArduinoCloud.addProperty(custom_switch8, READWRITE, ON_CHANGE, OnCustomSwitch8Change);
  ArduinoCloud.addProperty(custom_switch9, READWRITE, ON_CHANGE, OnCustomSwitch9Change);
  ArduinoCloud.addProperty(custom_switch10, READWRITE, ON_CHANGE, OnCustomSwitch10Change);

  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  setDebugMessageLevel(4);
  ArduinoCloud.printDebugInfo();
}

#endif //NODEMCU_ALEXA_IOT_IR_REMOTE_INCLUDE_IOT_CLOUD_CONNECTION_H_