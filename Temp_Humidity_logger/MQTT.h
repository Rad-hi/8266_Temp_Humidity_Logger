#ifndef __MQTT_H__
  #define __MQTT_H__
  
  #include<ESP8266WiFi.h>
  #include <PubSubClient.h>  // https://github.com/knolleary/pubsubclient/
  
  #define BROKER            "io.adafruit.com"
  #define MQTT_PORT         1883
  #define MQTT_USER         "Radhi" // User name in adafruit.io
  #define MQTT_PASSWORD     "YOUR_ADAFRUIT_IO_KEY" // MQTT Key in adafruit.io
  #define TEMPERATURE_TOPIC "USER_NAME_HERE/feeds/Temperature" // User_Name/feeds/Topic_Name_Of_Choice
  #define HUMIDITY_TOPIC    "USER_NAME_HERE/feeds/Humidity"
  #define MQTT_ID           "ANY_UNIQUE_TAG" // Create fixed ID for your ESP8266 board
                                      	     // If connected to the broker once with an ID, never change it!
  
  void MQTT_setup();
  void MQTT_connect();
  void MQTT_subscribe(const char *);
  void MQTT_callback(char*, byte*, unsigned int);
  void send_data(const char*, const char *);
  bool mqtt_state();
#endif
