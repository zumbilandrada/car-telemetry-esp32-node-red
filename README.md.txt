# ESP32 & Node-RED Real-Time Vehicle Telemetry System

A real-time IoT telemetry project designed to monitor vehicle metrics and location using an **ESP32** microcontroller and a custom **Node-RED Dashboard**

---

## Features
* **Live Speed Tracking:** Real-time gauge for vehicle speed.
* **RPM & Temperature Monitoring:** Live indicators for engine RPM and temperature.
* **GPS Mapping:** Live tracking of the vehicle's position on a map.
* **JSON Data Processing:** Smooth parsing and formatting of telemetry data sent from the ESP32.

## Tech Stack
* **Hardware & Firmware:** ESP32 programmed via **Arduino IDE**.
* **Communication Protocol:** **MQTT Broker** (for transmitting data from ESP32 to Node-RED).
* **Software / Backend:** [Node-RED](https://nodered.org/) with Node-RED Dashboard.