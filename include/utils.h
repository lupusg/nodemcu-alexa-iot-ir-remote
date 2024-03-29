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

#include <IRrecv.h>
#include <IRutils.h>
#include "config.h"
#include "http-client.h"

/**
 * Gets the infrared signal associated with the specified switch.
 * @param switch_id Switch id.
 * @return Infrared signal as a string.
 */
const char *GetSignalData(const char *switch_id) {
  String url(API_SWITCH_URL);
  url += switch_id;

  return HttpGet(url.c_str());
}

/**
 * Gets the signal length from the beginning of the infrared signal string.
 * E.g [signal_Length]5543 483 2838 1239 2493...
 * @param data Infrared signal.
 * @return Infrared signal length.
 */
uint16_t GetSignalLength(const char *data) {
  const char *closing_bracket = strchr(data, ']');
  if (closing_bracket != nullptr) {
	return atoi(data + 1);
  }
  return 0;
}

/**
 * Converts the infrared signal from string to a uint16_t dynamically allocated array.
 * @param data Infrared signal as a string.
 * @param result Infrared signal as a dynamically allocated uint16_t array.
 * @param length Infrared signal length.
 */
void StringSignalToRaw(const char *&data, uint16_t *result, uint16_t &length) {
  unsigned int result_index = 0;

  length = GetSignalLength(data);
//  free(result);
//  result = (uint16_t *)malloc(sizeof(uint16_t) * length);

  char *data_copy = strdup(data);
  char *token = strtok(data_copy, "]");
  token = strtok(nullptr, " "); // skip the size
  while (token != nullptr) {
	result[result_index++] = atoi(token);
	token = strtok(nullptr, " ");
  }
  free(data_copy);
}

/**
 * Converts the infrared signal from a raw array to a string with [length] at the beginning.
 * @param results The infrared signal.
 * @return The infrared signal as a string.
 */
String ResultsToString(decode_results &results) {
  const uint16_t kResultsLength = getCorrectedRawLength(&results);
  uint16_t *decoded_results_arr = resultToRawArray(&results);
  String result("[");
  result += String(kResultsLength);
  result += "]";

  for (uint16_t index = 0; index < kResultsLength; ++index) {
	result += decoded_results_arr[index];
	result += ' ';
  }

  return result;
}

#endif //NODEMCU_ALEXA_IOT_IR_REMOTE_INCLUDE_UTILS_H_
