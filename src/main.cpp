/**
 * NodeMCU Alexa IOT Infrared Remote
 *
 * Convert old devices that are not compatible
 * with Alexa into compatible ones using infrared
 * signals.
 *
 * NodeMCU IOT Platform
 *
 * @file main.cpp
 *
 * @brief The file that handles the main program.
 *
 * @date July 11, 2022
 *
 * @author Vlad-Marian Lupu
 */

#include <Arduino.h>
#include "thing-ac-switch.h"
#include "arduino-config.h"
#include "ir-receive.h"
#include "http-server.h"

extern bool is_receiving;

void setup() {
  delay(1000);
  Serial.begin(BAUD_RATE);
  InitAcSwitch();
  InitIotCloud();
  InitIrReceive();
  InitHttpServer();
//  Serial.print(WiFi.status());
}

void loop() {
  ArduinoCloud.update();
  HttpServerLoop();

  if(is_receiving){
	HandleIrResults();
  }
}
