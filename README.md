# MQTT LED Control using NodeMCU & EMQX

Control the built-in LED on NodeMCU (ESP8266) via MQTT using EMQX Broker.

## Features
- Uses built-in LED (no external hardware)
- MQTT control with EMQX broker
- Serial Monitor debug output

## WiFi
SSID: emqx
Password: emqx

## MQTT
- Broker: broker.emqx.io
- Port: 1883
- Topic: home/led
- Messages:
  - `ON` / `1` → LED ON
  - `OFF` / `2` → LED OFF

## How to Use
1. Open `mqtt_led_builtin.ino` in Arduino IDE
2. Select NodeMCU board and correct port
3. Upload code to your board
4. Open Serial Monitor to see status
5. Use MQTTX client or app to send messages to `home/led`

Enjoy testing your IoT project!
