/*
 * Main file for the Temperature logging IoT node.
 * ---
 * This file requires a collection of header files to run properly.
 * Header files: {WIFI.h(WIFI.cpp), 
 *                MQTT.h(MQTT.cpp)}
 * ---
 * Written by: Radhi SGHAIER, https://github.com/Rad-hi 
 */

#include"WIFI.h"

// Library to interact with the DHT11 sensor
#include <DHT_U.h>
#include <DHT.h>

// Turn ON/OFF debug printing 
#define DEBUG

#ifdef DEBUG
  #define DEBUG_MACRO(STRING)   Serial.print(STRING)
#else
  #define DEBUG_MACRO(STRING)   // Nothing
#endif

// If this is true, two random numbers in the appropriate range will simulate the Temp & Smoke inputs
#define SIMULATE_RANDOM         false

// 115.2K baud serial connection to computer
#define SERIAL_MON_BAUD_RATE    115200

//
#define DHT_PIN                 13
#define DHT_TYPE                DHT11

//
#define SLEEP_TIME              5000000UL  // 10s (uSeconds) (10e6 works too)

// Create a dht sensor object
DHT dht(DHT_PIN, DHT_TYPE);

// Functions' prototypes
float read_temperature(float &);
float read_humidity(float &);
void communicate_();
void go_to_sleep();

// Global variables
float temp_value = 0;
float humi_value = 0;

void setup(){
  
  dht.begin();
  
  #ifdef DEBUG
    Serial.begin(SERIAL_MON_BAUD_RATE);
  #endif

  // Sim
  #if SIMULATE_RANDOM
    randomSeed(analogRead(0)); 
  #endif
  DEBUG_MACRO("--- STARTED ---");
}

void loop() {
  read_temperature(temp_value);
  read_humidity(humi_value);

  
  DEBUG_MACRO("\n");
  DEBUG_MACRO("Temperature value: ");
  DEBUG_MACRO(temp_value);
  DEBUG_MACRO(", Humidity value: ");
  DEBUG_MACRO(humi_value);
  DEBUG_MACRO("\n");
  
  // Send the read value
  communicate_();

  go_to_sleep();
}

void go_to_sleep(){
  
  // Off WiFi
  off_unnecessary();
  
  DEBUG_MACRO("Going to sleep...\n");
   
  // WAKE_RF_DISABLED to keep the WiFi radio disabled when we wake up
  ESP.deepSleepInstant(SLEEP_TIME, WAKE_RF_DISABLED);
}

float read_temperature(float &temp){
  
  #if SIMULATE_RANDOM // Simulate sensor's readings with a random number generator
    temp = random(0, 50);
  #else // Read the sensor values from the two sensors
    temp = dht.readTemperature();
  #endif
  
}

float read_humidity(float &hum){
  
  #if SIMULATE_RANDOM // Simulate sensor's readings with a random number generator
    hum  = random(20, 100);
  #else // Read the sensor values from the two sensors
    hum  = dht.readHumidity();
  #endif
  
}


void communicate_(){

  MQTT_setup();

  DEBUG_MACRO("Connecting to WiFi...\n");
  wake_wifi_up();

  DEBUG_MACRO("Connecting to MQTT broker...\n");
  
  MQTT_connect();
  send_data(String(humi_value).c_str(), HUMIDITY_TOPIC);

  delay(1000);
  MQTT_connect();
  send_data(String(temp_value).c_str(), TEMPERATURE_TOPIC);
  
  DEBUG_MACRO("Sent: "); 
  DEBUG_MACRO(temp_value);
  DEBUG_MACRO(", "); 
  DEBUG_MACRO(humi_value);
  DEBUG_MACRO("\n");
}
