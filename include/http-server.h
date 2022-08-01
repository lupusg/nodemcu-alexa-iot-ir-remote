/**
 * NodeMCU Alexa IOT Infrared Remote
 *
 * Convert old devices that are not compatible
 * with Alexa into compatible ones using infrared
 * signals.
 *
 * @file http-server.h
 *
 * @brief The file that handles the HTTP server.
 *
 * @date July 21, 2022
 *
 * @author Vlad-Marian Lupu
 */

#ifndef NODEMCU_ALEXA_IOT_IR_REMOTE_INCLUDE_HTTP_SERVER_H_
#define NODEMCU_ALEXA_IOT_IR_REMOTE_INCLUDE_HTTP_SERVER_H_

#include <ESP8266WebServer.h>

ESP8266WebServer server(80);

void HandleOnConnect();
void HandleNotFound();
void StartReceiving();

bool receive = false;

/**
 * The WiFi connection & webserver setup.
 */
void InitHttpServer() {
  Serial.print("Connecting to ");
  Serial.println(kNetworkID);

  WiFi.begin(kNetworkID, kPassword);
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
  receive = !receive;
  if(receive){
	  Serial.println("[HTTP]Receiving IR codes");
  } else {
	  Serial.println("[HTTP]Stopped receiving IR codes");
  }
  server.send(200, "text/plain", "received succesfully");
}


/**
 * The handler for the 404 not found endpoint.
 */
void HandleNotFound() {
  server.send(404, "text/plain", "Not found");
}

#endif //NODEMCU_ALEXA_IOT_IR_REMOTE_INCLUDE_HTTP_SERVER_H_
