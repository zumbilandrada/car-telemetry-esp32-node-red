#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>

// Datele tale Wi-Fi
const char* ssid = "DIGI-p96p";
const char* password = "xXKV4655";

// Broker MQTT public pentru teste
const char* mqtt_server = "broker.hivemq.com";
const int mqtt_port = 1883;
const char* mqtt_topic = "autonoma/telemetrie/esp32_car_01";

WiFiClient espClient;
PubSubClient client(espClient);

// Variabile simulare mașină
float carSpeed = 0.0;
int carRpm = 800;
float engineTemp = 20.0;
float latitude = 46.7712;
float longitude = 23.6236;

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Se conectează la: ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWi-Fi conectat!");
  Serial.print("IP adresa: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Se încearcă conexiunea MQTT...");
    String clientId = "ESP32Client-";
    clientId += String(random(0xffff), HEX);
    
    // Corectat: .c_str() în loc de .c0str()
    if (client.connect(clientId.c_str())) {
      Serial.println("conectat!");
    } else {
      Serial.print(" eșuat, rc=");
      Serial.print(client.state());
      Serial.println(" se încearcă din nou în 5 secunde");
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, mqtt_port);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  // Simulare date
  carSpeed += 5.0;
  if (carSpeed > 130.0) { carSpeed = 0.0; }
  carRpm = 800 + (carSpeed * 25);
  if (engineTemp < 90.0) { engineTemp += 0.5; }
  latitude += 0.0001;
  longitude += 0.0001;

  // Creare JSON
  JsonDocument doc; 
  doc["device_id"] = "esp32_car_01";
  doc["speed"] = carSpeed;
  doc["rpm"] = carRpm;
  doc["engine_temp"] = engineTemp;
  doc["gps"]["lat"] = latitude;
  doc["gps"]["lon"] = longitude;
 
  String jsonString;
  serializeJson(doc, jsonString);

  // Publicare pe MQTT
  client.publish(mqtt_topic, jsonString.c_str());
  
  Serial.print("Mesaj publicat: ");
  Serial.println(jsonString);

  delay(1000);
}
