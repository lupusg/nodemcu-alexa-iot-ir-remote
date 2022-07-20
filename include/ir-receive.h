/**
 * @file ir-receive.h
 *
 * @brief IR remote receiver header file.
 * 		  Adapted from IRremoteESP8266 library by Ken Shirriff & David Conran.
 *
 * @see https://github.com/crankyoldgit/IRremoteESP8266/tree/master/examples/IRrecvDumpV2
 *
 * @author Vlad-Marian Lupu
 *
 * @date July 16, 2022
 */

#ifndef NODEMCU_ALEXA_IOT_IR_REMOTE_INCLUDE_IR_RECEIVE_H_
#define NODEMCU_ALEXA_IOT_IR_REMOTE_INCLUDE_IR_RECEIVE_H_

#include <cassert>
#include <IRrecv.h>
#include <IRremoteESP8266.h>
#include <IRac.h>
#include <IRtext.h>
#include <IRutils.h>
#include <IRsend.h>

#include "arduino-config.h"

const uint16_t kCaptureBufferSize = 1024;

// kTimeout is the Nr. of milli-Seconds of no-more-data before we consider a
// message ended.
// This parameter is an interesting trade-off. The longer the timeout, the more
// complex a message it can capture. e.g. Some device protocols will send
// multiple message packets in quick succession, like Air Conditioner remotes.
// Air Coniditioner protocols often have a considerable gap (20-40+ms) between
// packets.
// The downside of a large timeout value is a lot of less complex protocols
// send multiple messages when the remote's button is held down. The gap between
// them is often also around 20+ms. This can result in the raw data be 2-3+
// times larger than needed as it has captured 2-3+ messages in a single
// capture. Setting a low timeout value can resolve this.
// So, choosing the best kTimeout value for your use particular case is
// quite nuanced. Good luck and happy hunting.
// NOTE: Don't exceed kMaxTimeoutMs. Typically 130ms.
#if DECODE_AC
// Some A/C units have gaps in their protocols of ~40ms. e.g. Kelvinator
// A value this large may swallow repeats of some protocols
const uint8_t kTimeout = 50;
#else   // DECODE_AC
// Suits most messages, while not swallowing many repeats.
const uint8_t kTimeout = 15;
#endif  // DECODE_AC

// Set the smallest sized "UNKNOWN" message packets we actually care about.
// This value helps reduce the false-positive detection rate of IR background
// noise as real messages. The chances of background IR noise getting detected
// as a message increases with the length of the kTimeout value. (See above)
// The downside of setting this message too large is you can miss some valid
// short messages for protocols that this library doesn't yet decode.
//
// Set higher if you get lots of random short UNKNOWN messages when nothing
// should be sending a message.
// Set lower if you are sure your setup is working, but it doesn't see messages
// from your device. (e.g. Other IR remotes work.)
// NOTE: Set this value very high to effectively turn off UNKNOWN detection.
const uint16_t kMinUnknownSize = 12;

// How much percentage lee way do we give to incoming signals in order to match
// it?
// e.g. +/- 25% (default) to an expected value of 500 would mean matching a
//      value between 375 & 625 inclusive.
// Note: Default is 25(%). Going to a value >= 50(%) will cause some protocols
//       to no longer match correctly. In normal situations you probably do not
//       need to adjust this value. Typically that's when the library detects
//       your remote's message some of the time, but not all of the time.
const uint8_t kTolerancePercentage = kTolerance;  // kTolerance is normally 25%

IRrecv ir_receiver(IR_RECEIVER_PIN, kCaptureBufferSize, kTimeout, true);
decode_results results;

/**
 * IR receiver initialization.
 */
void InitIrReceive() {
#if DECODE_HASH
  ir_receiver.setUnknownThreshold(kMinUnknownSize);    		// Ignore messages with less than minimum on or off pulses.
#endif                                                				// DECODE_HASH
  ir_receiver.setTolerance(kTolerancePercentage);    		// Override the default tolerance.
  ir_receiver.enableIRIn();                                			// Start the receiver
}

/**
 * Check if there is a IR signal received.
 * @return A pointer to a dynamically allocated uint16_t array.
 */
uint16_t* getRawIrResult() {
  if (ir_receiver.decode(&results)) {
	Serial.println(resultToSourceCode(&results));
	ir_receiver.resume();
	return resultToRawArray(&results);
  }
  return nullptr;
}

#endif //NODEMCU_ALEXA_IOT_IR_REMOTE_INCLUDE_IR_RECEIVE_H_
