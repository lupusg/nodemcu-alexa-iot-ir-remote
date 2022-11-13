/**
 * NodeMCU Alexa IOT Infrared Remote
 *
 * Convert old devices that are not compatible
 * with Alexa into compatible ones using infrared
 * signals.
 *
 * NodeMCU IOT Platform
 *
 * @file arduino-config.h
 *
 * @brief Arduino configuration file that contains general arduino settings, pins etc.
 *
 * @date July 19, 2022
 *
 * @author Vlad-Marian Lupu
 */

#ifndef NODEMCU_ALEXA_IOT_IR_REMOTE_INCLUDE_ARDUINO_CONFIG_H_
#define NODEMCU_ALEXA_IOT_IR_REMOTE_INCLUDE_ARDUINO_CONFIG_H_

// Board config
#define BAUD_RATE 115200       		// Baud rate for serial communication
#define IR_TRANSMITTER_PIN 4   		// Pin for IR transmitter
#define IR_RECEIVER_PIN 14			// Pin for IR receiver
#define FREQUENCY 38				// IR transmitter frequency

// IOT Config
#define SECRET_SSID ""							// SSID of the WiFi network
#define SECRET_PASS ""							// Password of the WiFi network
#define SECRET_DEVICE_KEY ""					// IOT Cloud Secret Device Key
#define DEVICE_LOGIN_NAME ""    				// IOT Device ID

// Server config
#define WEBSERVER_PORT 80

// RestAPI config
#define API_URL ""
#define API_USERNAME ""
#define API_PASSWORD ""


#endif //NODEMCU_ALEXA_IOT_IR_REMOTE_INCLUDE_ARDUINO_CONFIG_H_
