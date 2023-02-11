/**
 * NodeMCU Alexa IOT Infrared Remote
 *
 * Convert old devices that are not compatible
 * with Alexa into compatible ones using infrared
 * signals.
 *
 * NodeMCU IOT Platform
 *
 * @file custom-switches.h
 *
 * @brief Handles the OnChange state for all IOT Cloud Switches.
 *
 * @author Vlad-Marian Lupu
 *
 * @date August 17, 2022
 */

#ifndef NODEMCU_ALEXA_IOT_IR_REMOTE_INCLUDE_CUSTOM_SWITCHES_H_
#define NODEMCU_ALEXA_IOT_IR_REMOTE_INCLUDE_CUSTOM_SWITCHES_H_

#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>
#include "http-server.h"
#include "ir-transmitter.h"
#include "utils.h"

CloudSwitch custom_switch1, custom_switch2, custom_switch3, custom_switch4, custom_switch5, custom_switch6,
	custom_switch7, custom_switch8, custom_switch9, custom_switch10;
uint16_t *result;

void OnCustomSwitch1Change() {
  DEBUG_PRINTLN("OnCustomSwitch1Change()");
  String signal_data = GetSignalData("custom_switch1");

  StringSignalToRaw(signal_data, result);
  ir_send.sendRaw(result, GetSignalLength(signal_data), FREQUENCY);
}

void OnCustomSwitch2Change() {
  DEBUG_PRINTLN("OnCustomSwitch2Change()");
  String signal_data = GetSignalData("custom_switch2");

  StringSignalToRaw(signal_data, result);
  ir_send.sendRaw(result, GetSignalLength(signal_data), FREQUENCY);
}

/*void OnCustomSwitch3Change(){
  Serial.println("3");
}

void OnCustomSwitch4Change(){
  Serial.println("4");
}

void OnCustomSwitch5Change(){
  Serial.println("5");
}

void OnCustomSwitch6Change(){
  Serial.println("6");
}

void OnCustomSwitch7Change(){
  Serial.println("7");
}

void OnCustomSwitch8Change(){
  Serial.println("8");
}

void OnCustomSwitch9Change(){
  Serial.println("9");
}

void OnCustomSwitch10Change(){
  Serial.println("10");
}*/

#endif //NODEMCU_ALEXA_IOT_IR_REMOTE_INCLUDE_CUSTOM_SWITCHES_H_
