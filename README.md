# ESP8266-based temperature and humidity logging IoT node

## Demo

<image src="images/Demo_Adafruit_IO.gif" width="640">

> Running demo on [Adafruit.io](https://io.adafruit.com/)

## Components

- DHT11 Temperature and Humidity sensor
- ESP8266 12-F barebones SoC
- FTDI Adapter for programming the ESP

## How to use ?

This node reports data to the **private & free** mqtt broker on [Adafruit.io](https://io.adafruit.com/).

The source code has ***5 files*** where we have the **main file**, with two drivers for **MQTT** and one for **WiFi**. You'll have to modify **two files**:
- The **MQTT.h** file must be modified with your credentials in [Adafruit.io](https://io.adafruit.com/) along with the topic names you'll be using.
- The **WIFI.h** file must be modified with your **WIFI's credentials**.

Then (assuming you have/made a profile on Adafruit.io) **two options arise**:

***1)** You only need somewhere to store your data*: Then you're done! You can create the ***feed(s)*** (topic) if you want, but Adafruit.io will create any non-existent topic once your node tries to connect to it.

***2)** You need to visualize the data*: In this case, the ***feed(s)*** must exist before you can create the dashboard that would visualize the data (like the one shown in the demo).