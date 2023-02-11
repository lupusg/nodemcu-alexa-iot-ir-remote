/**
 * NodeMCU Alexa IOT Infrared Remote
 *
 * Convert old devices that are not compatible
 * with Alexa into compatible ones using infrared
 * signals.
 *
 * NodeMCU IOT Platform
 *
 * @file services.h
 *
 * @brief Services for signals & RestfulApi.
 *
 * @author Vlad-Marian Lupu
 *
 * @date February 8, 2023
 */
#ifndef NODEMCU_ALEXA_IOT_IR_REMOTE_INCLUDE_SERVICES_H_
#define NODEMCU_ALEXA_IOT_IR_REMOTE_INCLUDE_SERVICES_H_

/**
 * Sends the ir signal (as a string) to the restfulApi.
 * @param signal The infrared signal.
 */
void AddSignal(String &signal){
  http_client.begin(wifi_client, API_SIGNAL_URL);
  http_client.addHeader("Content-Type", "text/plain");

  int post_response = http_client.POST(signal);
  if (post_response > 0) {
	DEBUG_PRINTLN("[AddSignal] Data was successfully sent.");
  } else {
	DEBUG_PRINTLN("[AddSignal] Error.");
  }
  http_client.end();
}

/**
 * Login into the RestfulApi.
 * @param username The username.
 * @param password The password.
 * @param url The RestfulApi url.
 */
void LoginToApi(String username, String password, String url) {
  int response_code = 0;
  String received_payload = "";
  String payload = "{\"username\": \"" + username + "\",\"password\": \"" + password + "\"}";

  http_client.begin(wifi_client, url);
  http_client.addHeader("Content-Type", "application/json");
  response_code = http_client.POST(payload);

  cookie_token = http_client.header("Set-Cookie").c_str(); // update the token

  if (response_code > 0) {
	DEBUG_PRINT("[POST Request] Data was successfully sent. Code:");
	DEBUG_PRINTLN(response_code);

	received_payload = http_client.getString();

	DEBUG_PRINTLN("Received payload:\n<<");
	DEBUG_PRINTLN(received_payload);
	DEBUG_PRINTLN(">>");
  } else {
	DEBUG_PRINT("[POST Request] Error. Code: ");
	DEBUG_PRINT(response_code);
  }
  http_client.end();
}

#endif //NODEMCU_ALEXA_IOT_IR_REMOTE_INCLUDE_SERVICES_H_
