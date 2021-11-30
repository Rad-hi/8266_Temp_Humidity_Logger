#ifndef __WIFI_H__
  #define __WIFI_H__
  
  #include"MQTT.h" 

  // WiFi data
  #define WLAN_SSID               "YOUR_WIFIs_NAME"
  #define WLAN_PASSWD             "YOUR_WIFIs_PASSWORD"

  // 
  #define WIFI_TIMEOUT            20000UL // 20 seconds timeout to connect to WiFi
  
  void off_unnecessary();
  void wake_wifi_up();
#endif
