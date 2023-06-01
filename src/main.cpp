#include "http-client.h"
#include "http-server.h"
#include "arduino-iot-cloud.h"
#include "ir-transmitter.h"
#include "restapi-services.h"
#include "ir-receiver.h"

//extern bool is_receiving;
#define LED 2
void setup() {
  Serial.begin(BAUD_RATE);
  InitIrReceiver();
  InitHttpClient();
  InitHttpServer();
  InitArduinoIotCloud();
  InitIrTransmitter();

  ApiAuth(REST_API_USERNAME, REST_API_PASSWORD, API_LOGIN_URL);
  pinMode(LED, OUTPUT);
}

void loop() {
  ArduinoCloud.update();
  HttpServerLoop();

  if (is_receiving) {
	HandleIrResults();
	digitalWrite(LED, LOW);
  } else {
	digitalWrite(LED, HIGH);
  }
}