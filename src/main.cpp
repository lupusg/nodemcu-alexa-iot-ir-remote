/**
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

extern bool receive;

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

  if(receive){
	  getRawIrResult();
  }
}
