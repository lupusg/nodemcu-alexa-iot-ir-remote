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
  const char *signal_data = GetSignalData("custom_switch1");
  uint16_t signal_length;

  if (signal_data != nullptr) {
	DEBUG_PRINTLN(signal_data);

	StringSignalToRaw(signal_data, result, signal_length);
	ir_send.sendRaw(result, signal_length, FREQUENCY);
  } else {
	DEBUG_PRINTLN(F("Undefined signal data"));
  }
}

void OnCustomSwitch2Change() {
  DEBUG_PRINTLN("OnCustomSwitch2Change()");
  const char *signal_data = GetSignalData("custom_switch2");
  uint16_t signal_length;

  if (signal_data != nullptr) {
	DEBUG_PRINTLN(signal_data);

	StringSignalToRaw(signal_data, result, signal_length);
	ir_send.sendRaw(result, signal_length, FREQUENCY);
  } else {
	DEBUG_PRINTLN(F("Undefined signal data"));
  }
}

void OnCustomSwitch3Change() {
  DEBUG_PRINTLN("OnCustomSwitch3Change()");
  const char *signal_data = GetSignalData("custom_switch3");
  uint16_t signal_length;

  if (signal_data != nullptr) {
	DEBUG_PRINTLN(signal_data);

	StringSignalToRaw(signal_data, result, signal_length);
	ir_send.sendRaw(result, signal_length, FREQUENCY);
  } else {
	DEBUG_PRINTLN(F("Undefined signal data"));
  }
}

void OnCustomSwitch4Change() {
  DEBUG_PRINTLN("OnCustomSwitch4Change()");
  const char *signal_data = GetSignalData("custom_switch4");
  uint16_t signal_length;

  if (signal_data != nullptr) {
	DEBUG_PRINTLN(signal_data);

	StringSignalToRaw(signal_data, result, signal_length);
	ir_send.sendRaw(result, signal_length, FREQUENCY);
  } else {
	DEBUG_PRINTLN(F("Undefined signal data"));
  }
}

void OnCustomSwitch5Change() {
  DEBUG_PRINTLN("OnCustomSwitch5Change()");
  const char *signal_data = GetSignalData("custom_switch5");
  uint16_t signal_length;

  if (signal_data != nullptr) {
	DEBUG_PRINTLN(signal_data);

	StringSignalToRaw(signal_data, result, signal_length);
	ir_send.sendRaw(result, signal_length, FREQUENCY);
  } else {
	DEBUG_PRINTLN(F("Undefined signal data"));
  }
}

void OnCustomSwitch6Change() {
  DEBUG_PRINTLN("OnCustomSwitch6Change()");
  const char *signal_data = GetSignalData("custom_switch6");
  uint16_t signal_length;

  if (signal_data != nullptr) {
	DEBUG_PRINTLN(signal_data);

	StringSignalToRaw(signal_data, result, signal_length);
	ir_send.sendRaw(result, signal_length, FREQUENCY);
  } else {
	DEBUG_PRINTLN(F("Undefined signal data"));
  }
}

void OnCustomSwitch7Change() {
  DEBUG_PRINTLN("OnCustomSwitch7Change()");
  const char *signal_data = GetSignalData("custom_switch7");
  uint16_t signal_length;

  if (signal_data != nullptr) {
	DEBUG_PRINTLN(signal_data);

	StringSignalToRaw(signal_data, result, signal_length);
	ir_send.sendRaw(result, signal_length, FREQUENCY);
  } else {
	DEBUG_PRINTLN(F("Undefined signal data"));
  }
}

void OnCustomSwitch8Change() {
  DEBUG_PRINTLN("OnCustomSwitch8Change()");
  const char *signal_data = GetSignalData("custom_switch8");
  uint16_t signal_length;

  if (signal_data != nullptr) {
	DEBUG_PRINTLN(signal_data);

	StringSignalToRaw(signal_data, result, signal_length);
	ir_send.sendRaw(result, signal_length, FREQUENCY);
  } else {
	DEBUG_PRINTLN(F("Undefined signal data"));
  }
}

void OnCustomSwitch9Change() {
  DEBUG_PRINTLN("OnCustomSwitch9Change()");
  const char *signal_data = GetSignalData("custom_switch9");
  uint16_t signal_length;

  if (signal_data != nullptr) {
	DEBUG_PRINTLN(signal_data);

	StringSignalToRaw(signal_data, result, signal_length);
	ir_send.sendRaw(result, signal_length, FREQUENCY);
  } else {
	DEBUG_PRINTLN(F("Undefined signal data"));
  }
}

void OnCustomSwitch10Change() {
  DEBUG_PRINTLN("OnCustomSwitch10Change()");
  const char *signal_data = GetSignalData("custom_switch10");
  uint16_t signal_length;

  if (signal_data != nullptr) {
	DEBUG_PRINTLN(signal_data);

	StringSignalToRaw(signal_data, result, signal_length);
	ir_send.sendRaw(result, signal_length, FREQUENCY);
  } else {
	DEBUG_PRINTLN(F("Undefined signal data"));
  }
}

#endif //NODEMCU_ALEXA_IOT_IR_REMOTE_INCLUDE_CUSTOM_SWITCHES_H_
