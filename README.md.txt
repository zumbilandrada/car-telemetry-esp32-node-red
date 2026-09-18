# ESP32 & Node-RED Real-Time Vehicle Telemetry System

A real-time IoT telemetry project designed to monitor vehicle metrics and location using an **ESP32** microcontroller and a custom **Node-RED Dashboard**.

---

## Features
* **Live Speed Tracking:** Real-time gauge for vehicle speed.
* **RPM & Temperature Monitoring:** Live indicators for engine RPM and temperature.
* **GPS Mapping:** Live tracking of the vehicle's position on a map.
* **JSON Data Processing:** Smooth parsing and formatting of telemetry data sent from the ESP32.

---

## Tech Stack
* **Hardware & Firmware:** ESP32 programmed via **Arduino IDE**.
* **Communication Protocol:** **MQTT Broker** (for transmitting data from ESP32 to Node-RED).
* **Software / Backend:** [Node-RED](https://nodered.org/) with Node-RED Dashboard.

---

## Project Structure
* `esp32_firmware/` - The Arduino code for the ESP32.
* `flow.json` - The exported Node-RED flow containing the gauges and map.
* `assets/` - Folder containing project screenshots and visual documentation.

---

## Visuals & Preview

### 1. Node-RED Dashboard (Speed, RPM & Temperature Gauges)
<p align="center">
  <img src="./assets/dashboard-gauges.jpeg" alt="Node-RED Dashboard Gauges" width="700"/>
</p>

### 2. Live GPS Tracking Map
<p align="center">
  <img src="./assets/gps-map.jpeg" alt="Live GPS Map" width="700"/>
</p>

### 3. Node-RED Flow Schema
<p align="center">
  <img src="./assets/nodered-flow.jpeg" alt="Node-RED Flow Schema" width="700"/>
</p>