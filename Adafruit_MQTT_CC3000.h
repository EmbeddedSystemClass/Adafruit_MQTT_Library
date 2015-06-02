#ifndef _ADAFRUIT_MQTT_CC3000_H_
#define _ADAFRUIT_MQTT_CC3000_H_


#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_CC3000.h"
#include <Adafruit_CC3000.h>

// delay in ms between calls of available()
#define MQTT_CC3000_INTERAVAILDELAY 10  


class Adafruit_MQTT_CC3000 : public Adafruit_MQTT {
 public:
  Adafruit_MQTT_CC3000(Adafruit_CC3000 *cc3k, const char *server, uint16_t port, const char *cid, const char *user, const char *pass);
  int8_t connect(void);
  uint16_t readPacket(uint8_t *buffer, uint8_t maxlen, int16_t timeout, boolean checkForValidPubPacket = false);
  int32_t close(void);

  boolean publish(const char *topic, char *payload, uint8_t qos);
  boolean ping(uint8_t time);

  boolean subscribe(Adafruit_MQTT_Subscribe *sub);

  Adafruit_MQTT_Subscribe *readSubscription(int16_t timeout=0);
 
 private:
  Adafruit_CC3000 *cc3000;
  Adafruit_CC3000_Client mqttclient;
};


#endif