#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// WiFi credentials
const char* ssid = "iQOO Neo7 Pro";
const char* password = "123456789";

// MQTT Broker
const char* mqtt_server = "broker.emqx.io";
const int mqtt_port = 1883;
const char* mqtt_topic = "home/led";
const char* clientID = "NodeMCU_BuiltinLED";

// Use built-in LED (GPIO2 / D4)
const int ledPin = LED_BUILTIN;

WiFiClient espClient;
PubSubClient client(espClient);

void setup_wifi() {
  delay(10);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
  }
}

void callback(char* topic, byte* payload, unsigned int length) {
  String message;
  for (int i = 0; i < length; i++) {
    message += (char)payload[i];
  }
  if (message == "ON" || message == "1") {
    digitalWrite(ledPin, LOW);  // Turn ON
  } else if (message == "OFF" || message == "2") {
    digitalWrite(ledPin, HIGH); // Turn OFF
  }
}

void reconnect() {
  while (!client.connected()) {
    if (client.connect(clientID)) {
      client.subscribe(mqtt_topic);
    } else {
      delay(5000);
    }
  }
}

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH); // Start with LED OFF
  setup_wifi();
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}