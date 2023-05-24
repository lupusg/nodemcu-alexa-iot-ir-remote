/**
 * NodeMCU Alexa IOT Infrared Remote
 *
 * Convert old devices that are not compatible
 * with Alexa into compatible ones using infrared
 * signals.
 *
 * NodeMCU IOT Platform
 *
 * @file restapi-services.h
 *
 * @brief Services for the RestApi.
 *
 * @author Vlad-Marian Lupu
 *
 * @date February 8, 2023
 */
#ifndef NODEMCU_ALEXA_IOT_IR_REMOTE_INCLUDE_RESTAPI_SERVICES_H_
#define NODEMCU_ALEXA_IOT_IR_REMOTE_INCLUDE_RESTAPI_SERVICES_H_

/**
 * Login into the RestfulApi.
 * @param username The username.
 * @param password The password.
 * @param url The RestfulApi url.
 */
void ApiAuth(String username, String password, String url) {
  String response;
  String payload(R"({"username": ")");
  payload += username;
  payload += R"(","password": ")";
  payload += password;
  payload += R"("})";

  http_client.begin(wifi_client, url);
  http_client.addHeader("Content-Type", "application/json");

  DEBUG_PRINT("[ApiAuth] Code: ");
  int http_code = http_client.POST(payload);

  cookie_token = http_client.header("Set-Cookie").c_str(); // update the token
  DEBUG_PRINTLN(cookie_token);

  if (http_code > 0) {
	DEBUG_PRINTLN(http_code);
	if (http_code == HTTP_CODE_OK) {
	  response = http_client.getString();

	  DEBUG_PRINTLN("Response >>>");
	  DEBUG_PRINTLN(response);
	  DEBUG_PRINTLN("<<< Response");
	}
  } else {
	DEBUG_PRINT("[ApiAuth] Failed, error: ");
	DEBUG_PRINTLN(http_client.errorToString(http_code).c_str());
  }
  http_client.end();
}

#endif //NODEMCU_ALEXA_IOT_IR_REMOTE_INCLUDE_RESTAPI_SERVICES_H_
