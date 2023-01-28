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
 * 		  API Auth adapted from https://www.mischianti.org/2020/11/17/web-server-on-esp8266-add-secure-rest-back-end-5/
 *
 * @date July 21, 2022
 *
 * @author Vlad-Marian Lupu
 */

#ifndef NODEMCU_ALEXA_IOT_IR_REMOTE_INCLUDE_HTTP_SERVER_H_
#define NODEMCU_ALEXA_IOT_IR_REMOTE_INCLUDE_HTTP_SERVER_H_

#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>
#include <Arduino_DebugUtils.h>
#include <Hash.h>
#include "arduino-config.h"

ESP8266WebServer server(WEBSERVER_PORT);
WiFiClient wifi_client;
HTTPClient http_client;

const char *api_url = API_SIGNAL_URL;
String cookie_token;

void ServerRouting();
void HandleOnConnect();
void HandleToggleReceiving();
void HandleNotFound();
void HandleLogin();
void HandleLogout();

bool IsAuthenticated();

bool is_receiving = false;

/**
 * WiFi connection & webserver setup.
 */
void InitHttpServer() {
  const char * header_keys[] = {
	  "User-Agent","Set-Cookie","Cookie","Date","Content-Type","Connection"} ;
  size_t header_keys_size = sizeof(header_keys)/sizeof(char*);

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

  ServerRouting();

  http_client.collectHeaders(header_keys,header_keys_size);
  server.collectHeaders("Cookie", "Set-Cookie");

  server.begin();
  Serial.println("HTTP server started.");
}

/**
 * Main-loop for the HTTP server.
 */
void HttpServerLoop() {
  server.handleClient();
}

/**
 * All server routes.
 */
void ServerRouting() {
  server.on("/login", HTTP_POST, HandleLogin);
  server.on("/logout", HTTP_GET, HandleLogout);

  server.on("/toggle-receiving", HandleToggleReceiving);

  server.on("/", HandleOnConnect);
  server.onNotFound(HandleNotFound);
}

/**
 * The handler for the main page.
 */
void HandleOnConnect() {
  if (IsAuthenticated()) {
	server.send(200, "text/plain", "Hello from ESP8266!");
  }
}

/**
 * The handler for the /test endpoint.
 */
void HandleToggleReceiving() {
  if (IsAuthenticated()) {
	is_receiving = !is_receiving;
	if (is_receiving) {
	  Serial.println("[HTTP]Receiving IR codes");
	} else {
	  Serial.println("[HTTP]Stopped receiving IR codes");
	}
	server.send(200, "text/plain", "Toggle successfully");
  }
}

/**
 * The handler for the 404 not found endpoint.
 */
void HandleNotFound() {
  server.send(404, "text/plain", "Not found.");
}

/**
 * The login handler.
 * Stores the token 'ESPSESSIONID=sha1(username:password)' as a cookie.
 */
void HandleLogin() {
  Serial.println("Handle login");
  String message;

  if (server.hasHeader("Cookie")) {
	Serial.print("Found cookie: ");
	String cookie = server.header("Cookie");
	Serial.println(cookie);
  }

  if (server.hasArg("username") && server.hasArg("password")) {
	Serial.print("Found parameter: ");

	if (server.arg("username") == String(API_USERNAME) && server.arg("password") == String(API_PASSWORD)) {
	  server.sendHeader("Location", "/");
	  server.sendHeader("Cache-Control", "no-cache");

	  String token = sha1(String(API_USERNAME) + ":" + String(API_PASSWORD));
	  server.sendHeader("Set-Cookie", "ESPSESSIONID=" + token);

	  server.send(301);
	  Serial.println("Log in Successful");
	  return;
	}
	message = "Wrong username/password! try again.";
	Serial.println("Log in Failed");
	server.sendHeader("Location", "/login.html?message=" + message);
	server.sendHeader("Cache-Control", "no-cache");
	server.send(301);
	return;
  }
}

/**
 * The logout handler.
 */
void HandleLogout() {
  Serial.println("Disconnection");
  server.sendHeader("Location", "/login.html?msg=User disconnected");
  server.sendHeader("Cache-Control", "no-cache");
  server.sendHeader("Set-Cookie", "ESPSESSIONID=0");
  server.send(301);
}

/**
 * Checks if the token 'ESPSESSIONID=sha1(username:password' is present in the request cookie.
 * @return True if it is, false otherwise.
 */
bool IsAuthenticated() {
  Serial.println("Enter is_authenticated");
  if (server.hasHeader("Cookie")) {
	Serial.print("Found cookie: ");
	String cookie = server.header("Cookie");
	Serial.println(cookie);

	String token = sha1(String(API_USERNAME) + ":" + String(API_PASSWORD));

	if (cookie.indexOf("ESPSESSIONID=" + token) != -1) {
	  Serial.println("Authentication Successful");
	  return true;
	}
  }
  Serial.println("Authentication Failed");
  server.send(401, F("application/json"), "({\"msg\": \"You must authenticate!\"})");
  return false;
}

#endif //NODEMCU_ALEXA_IOT_IR_REMOTE_INCLUDE_HTTP_SERVER_H_
