/**
 * NodeMCU Alexa IOT Infrared Remote
 *
 * Convert old devices that are not compatible
 * with Alexa into compatible ones using infrared
 * signals.
 *
 * NodeMCU IOT Platform
 *
 * @file ir-transmitter.h
 *
 * @brief Handles IR Transmitter.
 *
 * @author Vlad-Marian Lupu
 *
 * @date August 18, 2022
 */
#ifndef NODEMCU_ALEXA_IOT_IR_REMOTE_INCLUDE_IR_TRANSMITTER_H_
#define NODEMCU_ALEXA_IOT_IR_REMOTE_INCLUDE_IR_TRANSMITTER_H_

#include <IRsend.h>

IRsend ir_send(IR_TRANSMITTER_PIN);

void InitIrTransmitter(){
  ir_send.begin();
}

#endif //NODEMCU_ALEXA_IOT_IR_REMOTE_INCLUDE_IR_TRANSMITTER_H_
