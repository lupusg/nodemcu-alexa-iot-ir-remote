/**
 * NodeMCU Alexa IOT Infrared Remote
 *
 * Convert old devices that are not compatible
 * with Alexa into compatible ones using infrared
 * signals.
 *
 * NodeMCU IOT Platform
 *
 * @file http-server.h
 *
 * @brief The HTTP server.
 *
 * @date July 21, 2022
 *
 * @author Vlad-Marian Lupu
 */

#ifndef NODEMCU_ALEXA_IOT_IR_REMOTE_INCLUDE_HTTP_SERVER_H_
#define NODEMCU_ALEXA_IOT_IR_REMOTE_INCLUDE_HTTP_SERVER_H_

#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>
#include "iot-arduino-secrets.h"

ESP8266WebServer server(80);
WiFiClient wifi_client;
HTTPClient http_client;

const char *api_url = "http://192.168.0.104:8081/signal";

void HandleOnConnect();
void HandleNotFound();
void StartReceiving();

bool is_receiving = false;

/**
 * The WiFi connection & webserver setup.
 */
void InitHttpServer() {
  Serial.print("Connecting to ");
  Serial.println(SECRET_SSID);

  WiFi.begin(SECRET_SSID, SECRET_PASS);

  while (WiFi.status() != WL_CONNECTED) {
	delay(1000);
	Serial.print(".");
  }
  Serial.println("Connected to WiFi.");
  Serial.print("AP IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/", HandleOnConnect);
  server.on("/startReceiving", StartReceiving);
  server.onNotFound(HandleNotFound);
  server.begin();
  Serial.println("HTTP server started.");
}

/**
 * The main-loop for the HTTP server.
 */
void HttpServerLoop() {
  server.handleClient();
}

/**
 * The handler for the main page.
 */
void HandleOnConnect() {
  server.send(200, "text/plain", "Hello from ESP8266!");
}

/**
 * The handler for the /test endpoint.
 */
void StartReceiving() {
  is_receiving = !is_receiving;
  if (is_receiving) {
	Serial.println("[HTTP]Receiving IR codes");
  } else {
	Serial.println("[HTTP]Stopped receiving IR codes");
  }
  server.send(200, "text/plain", "received successfully");
}

/**
 * The handler for the 404 not found endpoint.
 */
void HandleNotFound() {
  server.send(404, "text/plain", "Not found");
}

#endif //NODEMCU_ALEXA_IOT_IR_REMOTE_INCLUDE_HTTP_SERVER_H_
