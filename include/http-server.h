#ifndef NODEMCU_ALEXA_IOT_IR_REMOTE_INCLUDE_HTTP_SERVER_H_
#define NODEMCU_ALEXA_IOT_IR_REMOTE_INCLUDE_HTTP_SERVER_H_

#include <ESP8266WebServer.h>
#include <Hash.h>

#include "config.h"

ESP8266WebServer server(WEBSERVER_PORT);

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
  ServerRouting();

  server.collectHeaders("Cookie", "Set-Cookie");
  server.begin();

  DEBUG_PRINTLN("HTTP server started.");
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
	  DEBUG_PRINTLN("[ToggleReceiving] Receiving IR codes");
	} else {
	  DEBUG_PRINTLN("[ToggleReceiving] Stopped receiving IR codes");
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
  String message;

  if (server.hasHeader("Cookie")) {
	DEBUG_PRINT("Found cookie: ");
	String cookie = server.header("Cookie");
	DEBUG_PRINTLN(cookie);
  }

  if (server.hasArg("username") && server.hasArg("password")) {
	DEBUG_PRINT("Found parameter: ");

	if (server.arg("username") == String(API_USERNAME) && server.arg("password") == String(API_PASSWORD)) {
	  server.sendHeader("Location", "/");
	  server.sendHeader("Cache-Control", "no-cache");

	  String token = sha1(String(API_USERNAME) + ":" + String(API_PASSWORD));
	  server.sendHeader("Set-Cookie", "ESPSESSIONID=" + token);

	  server.send(301);
	  DEBUG_PRINTLN("Log in Successful");
	  return;
	}
	message = "Wrong username/password! try again.";
	DEBUG_PRINTLN("Log in Failed");
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
  DEBUG_PRINTLN("Disconnected.");
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
  if (server.hasHeader("Cookie")) {
	DEBUG_PRINT("Found cookie: ");
	String cookie = server.header("Cookie");
	DEBUG_PRINTLN(cookie);

	String token = sha1(String(API_USERNAME) + ":" + String(API_PASSWORD));

	if (cookie.indexOf("ESPSESSIONID=" + token) != -1) {
	  DEBUG_PRINTLN("Authentication Successful");
	  return true;
	}
  }
  DEBUG_PRINTLN("Authentication Failed");
  server.send(401, F("application/json"), "({\"msg\": \"You must authenticate!\"})");
  return false;
}

#endif //NODEMCU_ALEXA_IOT_IR_REMOTE_INCLUDE_HTTP_SERVER_H_
