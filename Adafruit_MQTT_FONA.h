// The MIT License (MIT)
//
// Copyright (c) 2015 Adafruit Industries
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
#ifndef _ADAFRUIT_MQTT_FONA_H_
#define _ADAFRUIT_MQTT_FONA_H_

#include <Adafruit_FONA.h>
#include "Adafruit_MQTT.h"

#define MQTT_FONA_INTERAVAILDELAY 100
#define MQTT_FONA_QUERYDELAY 500


// FONA-specific version of the Adafruit_MQTT class.
// Note that this is defined as a header-only class to prevent issues with using
// the library on non-FONA platforms (since Arduino will include all .cpp files
// in the compilation of the library).
class Adafruit_MQTT_FONA : public Adafruit_MQTT {
 public:
  Adafruit_MQTT_FONA(Adafruit_FONA *f, const char *server, uint16_t port,
                       const char *cid, const char *user, const char *pass):
    Adafruit_MQTT(server, port, cid, user, pass),
    fona(f)
  {}

  Adafruit_MQTT_FONA(Adafruit_FONA *f, const char *server, uint16_t port,
                     const char *user="", const char *pass=""):
    Adafruit_MQTT(server, port, user, pass),
    fona(f)
  {}

  bool connectServer();

  bool disconnectServer();

  bool connected();

  uint16_t readPacket(uint8_t *buffer, uint16_t maxlen, int16_t timeout);

  bool sendPacket(uint8_t *buffer, uint16_t len);

 private:
  uint32_t serverip;
  Adafruit_FONA *fona;
};

#endif