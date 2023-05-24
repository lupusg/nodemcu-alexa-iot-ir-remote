/**
 * NodeMCU Alexa IOT Infrared Remote
 *
 * Convert old devices that are not compatible
 * with Alexa into compatible ones using infrared
 * signals.
 *
 * NodeMCU IOT Platform
 *
 * @file http_client-wifi_client.h
 *
 * @brief The HTTP wifi_client.
 *
 * @date May 23, 2023
 *
 * @author Vlad-Marian Lupu
 */

#ifndef NODEMCU_ALEXA_IOT_IR_REMOTE_INCLUDE_HTTP_CLIENT_H_
#define NODEMCU_ALEXA_IOT_IR_REMOTE_INCLUDE_HTTP_CLIENT_H_

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

#include "config.h"

WiFiClient wifi_client;
HTTPClient http_client;
String cookie_token;

void InitHttpClient() {
  const char *header_keys[] = {
	  "Set-Cookie", "Cookie"};
  size_t header_keys_size = sizeof(header_keys) / sizeof(char *);

  DEBUG_PRINTLN("Connecting to wifi");
  WiFi.begin(SECRET_SSID, SECRET_PASS);

  while (WiFi.status() != WL_CONNECTED) {
	delay(500);
	DEBUG_PRINT(".");
  }
  DEBUG_PRINTLN("");
  DEBUG_PRINT("Connected! IP address: ");
  DEBUG_PRINTLN(WiFi.localIP());

  http_client.collectHeaders(header_keys, header_keys_size);
}

const char *HttpGet(const char *url) {
  String requested_data("");
  if ((WiFi.status() == WL_CONNECTED)) {
	http_client.begin(wifi_client, url);
	http_client.addHeader("Content-Type", "plain");
	http_client.addHeader("Cookie", cookie_token);
//	DEBUG_PRINTLN(cookie_token);

	DEBUG_PRINT("[HttpGet] Code: ");
	int http_code = http_client.GET();

	if (http_code > 0) {
	  DEBUG_PRINTLN(http_code);

	  if (http_code == HTTP_CODE_OK) {
		requested_data = http_client.getString();
		DEBUG_PRINTLN("Requested data: >>>");
		DEBUG_PRINTLN(requested_data);
		DEBUG_PRINTLN("<<< Requested data");
	  }
	} else {
	  DEBUG_PRINT("\n[HttpGet] Failed, error: ");
	  DEBUG_PRINTLN(http_client.errorToString(http_code).c_str());
	}
	http_client.end();
  }
  return requested_data.c_str();
}

const char *HttpPost(const char *url, String &payload) {
  String response("");
  if ((WiFi.status() == WL_CONNECTED)) {
	http_client.begin(wifi_client, url);
	http_client.addHeader("Content-Type", "text/plain");
	http_client.addHeader("Cookie", cookie_token);

	DEBUG_PRINT("[HttpPost] Code: ");
	int http_code = http_client.POST(payload);

	if (http_code > 0) {
	  DEBUG_PRINTLN(http_code);

	  if (http_code == HTTP_CODE_OK) {
		response = http_client.getString();
		DEBUG_PRINTLN("Response >>>");
		DEBUG_PRINTLN(response);
		DEBUG_PRINTLN("<<< Response");
	  }
	} else {
	  DEBUG_PRINT("[HttpPost] Failed, error: ");
	  DEBUG_PRINTLN(http_client.errorToString(http_code).c_str());
	}
	http_client.end();
  }
  return payload.c_str();
}

#endif //NODEMCU_ALEXA_IOT_IR_REMOTE_INCLUDE_HTTP_CLIENT_H_
