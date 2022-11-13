/**
 * NodeMCU Alexa IOT Infrared Remote
 *
 * Convert old devices that are not compatible
 * with Alexa into compatible ones using infrared
 * signals.
 *
 * NodeMCU IOT Platform
 *
 * @file utils.h
 *
 * @brief Utility functions.
 *
 * @author Vlad-Marian Lupu
 *
 * @date August 20, 2022
 */
#ifndef NODEMCU_ALEXA_IOT_IR_REMOTE_INCLUDE_UTILS_H_
#define NODEMCU_ALEXA_IOT_IR_REMOTE_INCLUDE_UTILS_H_

/**
 * Gets the infrared signal associated with the specified button.
 * @param button_name The button name.
 * @return The infrared signal as a string.
 */
String GetSignalString(String button_name) {
  String requested_data = "undefined";
  String url = "http://46.101.246.223:8081/signal?switchName=" + button_name;
  int http_response;

  http_client.begin(wifi_client, url);
  http_client.addHeader("Content-Type", "text/plain");

  http_response = http_client.GET();
  if (http_response > 0) {
	requested_data = http_client.getString();
  }
  http_client.end();
  return requested_data;
}

/**
 * Gets the signal length from the beginning of the infrared signal string.
 * E.g [signal_Length]5543 483 2838 1239 2493...
 * @param data The infrared signal.
 * @return The signal length.
 */
unsigned int GetSignalLength(String &data) {
  String result;

  for (unsigned int index = 0; index < data.length() - 1; ++index) {
	if (data[index] == ']') {
	  result = data.substring(1, index);
	  return result.toInt();
	}
  }
  return 0;
}

/**
 * Converts the infrared signal from string to a uint16_t dynamically allocated array.
 * @param data The infrared signal as a string.
 * @param result The infrared signal as a dynamically allocated uint16_t array.
 */
void StringSignalToRaw(String &data, uint16_t *&result) {
  const unsigned int kSignalLength = GetSignalLength(data);
  unsigned int last_delimiter_position = 0;
  unsigned int elements_counter = 0;
  unsigned int result_index = 0;
  String element;

  free(result);
  result = (uint16_t *)malloc(sizeof(uint16_t) * kSignalLength);

  for (unsigned int index = 0; index < data.length() - 1; ++index) {
	if (data[index] == ']') {
	  last_delimiter_position = index + 1;
	} else if (data[index] == ' ') {
	  element = data.substring(last_delimiter_position, index);
	  last_delimiter_position = index + 1;
	  elements_counter++;
	  result[result_index++] = element.toInt();
	}
  }
}

/**
 * Makes a post request.
 * @param payload The data.
 * @param url The url.
 */
void PostRequest(String &payload, String &url) {
  int response_code = 0;
  String received_payload = "";

  http_client.begin(wifi_client, url);
  http_client.addHeader("Content-Type", "application/json");
  response_code = http_client.POST(payload);

  if (response_code > 0) {
	Serial.printf("[POST Request] Data was successfully sent. (Code %d)\n", response_code);
	received_payload = http_client.getString();
	Serial.println("Received payload:\n<<");
	Serial.println(received_payload);
	Serial.println(">>");
  } else {
	Serial.printf("[POST request] Error. (Code %d)\n", response_code);
  }
  http_client.end();
}

/**
 * Login into the restAPI.
 * @param username The username.
 * @param password The password.
 * @param url The restAPI url.
 */
void LoginToAPI(String username, String password, String url) {
  String payload = "{\"username\": \"" + username + "\",\"password\": \"" + password + "\"}";
  PostRequest(payload, url);
}

#endif //NODEMCU_ALEXA_IOT_IR_REMOTE_INCLUDE_UTILS_H_
