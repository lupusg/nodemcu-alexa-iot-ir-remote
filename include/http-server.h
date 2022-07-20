/**
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
void test();

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
  server.on("/test", test);
  server.onNotFound(HandleNotFound);
  server.begin();
  Serial.println("HTTP server started");
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


//TODO: Delete this one too.
/**
 * The handler for the /test endpoint.
 */
void test(){
  Serial.println("works");
}

/**
 * The handler for the 404 not found endpoint.
 */
void HandleNotFound() {
  server.send(404, "text/plain", "Not found");
}

#endif //NODEMCU_ALEXA_IOT_IR_REMOTE_INCLUDE_HTTP_SERVER_H_
