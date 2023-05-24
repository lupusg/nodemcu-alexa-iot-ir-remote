/**
 * NodeMCU Alexa IOT Infrared Remote
 *
 * Convert old devices that are not compatible
 * with Alexa into compatible ones using infrared
 * signals.
 *
 * NodeMCU IOT Platform
 *
 * @file iot-custom-switches.h
 *
 * @brief Handles the OnChange state for all IOT Cloud Switches.
 *
 * @author Vlad-Marian Lupu
 *
 * @date August 17, 2022
 */

#ifndef NODEMCU_ALEXA_IOT_IR_REMOTE_INCLUDE_IOT_CUSTOM_SWITCHES_H_
#define NODEMCU_ALEXA_IOT_IR_REMOTE_INCLUDE_IOT_CUSTOM_SWITCHES_H_

#include <ArduinoIoTCloud.h>
#include "ir-transmitter.h"
#include "http-client.h"
#include "utils.h"

CloudSwitch custom_switch1, custom_switch2, custom_switch3, custom_switch4, custom_switch5, custom_switch6,
	custom_switch7, custom_switch8, custom_switch9, custom_switch10;

void OnCustomSwitch1Change() {
  DEBUG_PRINTLN(F("OnCustomSwitch1Change()"));
  const char *signal_data = GetSignalData("1");
  uint16_t signal_length;

  if (signal_data != nullptr) {
	DEBUG_PRINTLN(ESP.getFreeHeap());
	StringSignalToRaw(signal_data, ir_result, signal_length);
	ir_send.sendRaw(ir_result, signal_length, FREQUENCY);
  } else {
	DEBUG_PRINTLN(F("Undefined signal data"));
  }
}

void OnCustomSwitch2Change() {
  DEBUG_PRINTLN("OnCustomSwitch1Change()");
  const char *signal_data = GetSignalData("2");
  uint16_t signal_length;

  if (signal_data != nullptr) {
	DEBUG_PRINTLN(ESP.getFreeHeap());
	StringSignalToRaw(signal_data, ir_result, signal_length);
	ir_send.sendRaw(ir_result, signal_length, FREQUENCY);
  } else {
	DEBUG_PRINTLN("Undefined signal data");
  }
}

void OnCustomSwitch3Change() {
  DEBUG_PRINTLN("OnCustomSwitch1Change()");
  const char *signal_data = GetSignalData("3");
  uint16_t signal_length;

  if (signal_data != nullptr) {
	DEBUG_PRINTLN(ESP.getFreeHeap());
	StringSignalToRaw(signal_data, ir_result, signal_length);
	ir_send.sendRaw(ir_result, signal_length, FREQUENCY);
  } else {
	DEBUG_PRINTLN("Undefined signal data");
  }
}

void OnCustomSwitch4Change() {
  DEBUG_PRINTLN("OnCustomSwitch1Change()");
  const char *signal_data = GetSignalData("4");
  uint16_t signal_length;

  if (signal_data != nullptr) {
	DEBUG_PRINTLN(ESP.getFreeHeap());
	StringSignalToRaw(signal_data, ir_result, signal_length);
	ir_send.sendRaw(ir_result, signal_length, FREQUENCY);
  } else {
	DEBUG_PRINTLN("Undefined signal data");
  }
}

void OnCustomSwitch5Change() {
  DEBUG_PRINTLN("OnCustomSwitch1Change()");
  const char *signal_data = GetSignalData("5");
  uint16_t signal_length;

  if (signal_data != nullptr) {
	DEBUG_PRINTLN(ESP.getFreeHeap());
	StringSignalToRaw(signal_data, ir_result, signal_length);
	ir_send.sendRaw(ir_result, signal_length, FREQUENCY);
  } else {
	DEBUG_PRINTLN("Undefined signal data");
  }
}

void OnCustomSwitch6Change() {
  DEBUG_PRINTLN("OnCustomSwitch1Change()");
  const char *signal_data = GetSignalData("6");
  uint16_t signal_length;

  if (signal_data != nullptr) {
	DEBUG_PRINTLN(ESP.getFreeHeap());
	StringSignalToRaw(signal_data, ir_result, signal_length);
	ir_send.sendRaw(ir_result, signal_length, FREQUENCY);
  } else {
	DEBUG_PRINTLN("Undefined signal data");
  }
}

void OnCustomSwitch7Change() {
  DEBUG_PRINTLN("OnCustomSwitch1Change()");
  const char *signal_data = GetSignalData("7");
  uint16_t signal_length;

  if (signal_data != nullptr) {
	DEBUG_PRINTLN(ESP.getFreeHeap());
	StringSignalToRaw(signal_data, ir_result, signal_length);
	ir_send.sendRaw(ir_result, signal_length, FREQUENCY);
  } else {
	DEBUG_PRINTLN("Undefined signal data");
  }
}

void OnCustomSwitch8Change() {
  DEBUG_PRINTLN("OnCustomSwitch1Change()");
  const char *signal_data = GetSignalData("8");
  uint16_t signal_length;

  if (signal_data != nullptr) {
	DEBUG_PRINTLN(ESP.getFreeHeap());
	StringSignalToRaw(signal_data, ir_result, signal_length);
	ir_send.sendRaw(ir_result, signal_length, FREQUENCY);
  } else {
	DEBUG_PRINTLN("Undefined signal data");
  }
}

void OnCustomSwitch9Change() {
  DEBUG_PRINTLN("OnCustomSwitch1Change()");
  const char *signal_data = GetSignalData("9");
  uint16_t signal_length;

  if (signal_data != nullptr) {
	DEBUG_PRINTLN(ESP.getFreeHeap());
	StringSignalToRaw(signal_data, ir_result, signal_length);
	ir_send.sendRaw(ir_result, signal_length, FREQUENCY);
  } else {
	DEBUG_PRINTLN("Undefined signal data");
  }
}

void OnCustomSwitch10Change() {
  DEBUG_PRINTLN("OnCustomSwitch10Change()");
  DEBUG_PRINTLN(ESP.getFreeHeap());
}

#endif //NODEMCU_ALEXA_IOT_IR_REMOTE_INCLUDE_IOT_CUSTOM_SWITCHES_H_
