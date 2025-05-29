# 🌿 Arduino Smart Farm + Laser Security System (with IoT)

This project is a complete **Smart Farming System** built using **Arduino** and **Blynk IoT**, integrating automated **plant watering**, **real-time environmental monitoring**, and a **laser-based intrusion detection system** that alerts the user through the **Blynk app**.

---

## 🌟 Features

### 🪴 Smart Farming
- 🌱 **Soil Moisture Monitoring**  
  Continuously checks soil condition using a moisture sensor.
  
- 💧 **Automated Watering**  
  Activates a water pump/valve when soil gets dry.

- 🌡️ **Optional Temperature & Humidity Monitoring**  
  With DHT11/DHT22 sensor for a complete environmental view.

### 📲 IoT Dashboard (via Blynk)
- Realtime data monitoring on smartphone
- Soil moisture and temp/humidity displayed
- Notification alerts for irrigation and intrusions

### 🔐 Laser Security System
- 🔦 **Laser + LDR Sensor for Perimeter Security**  
  Laser beam setup detects any breach by monitoring light intensity via an LDR.

- 🔔 **Buzzer Alarm**  
  Audible alert when intrusion is detected.

- 📩 **Instant Blynk Notification**  
  Message sent to user's phone when the laser beam is interrupted.

---

## 🛠️ Hardware Components

| Component               | Purpose                            |
|------------------------|------------------------------------|
| Arduino Uno/Nano/Mega  | Microcontroller                    |
| Soil Moisture Sensor   | Detects soil dryness               |
| Relay Module           | Controls water pump/valve          |
| Water Pump/Solenoid    | Performs irrigation                |
| DHT11/DHT22            | (Optional) Enviro monitoring       |
| LDR + Laser Module     | Intrusion detection                |
| Buzzer                 | Alarm for security breach          |
| ESP8266 (or built-in)  | Wi-Fi for Blynk IoT                |
| Jumper Wires, Breadboard | Circuit connections              |
| Power Supply           | 5V/9V/12V as needed                |

---

## 📲 Blynk Setup Guide

1. Download the **Blynk IoT app** (Android/iOS)
2. Create a new project, select your board and Wi-Fi
3. Add widgets:
   - Gauges for soil moisture, temperature, humidity
   - Notification widget for intrusion alerts
   - Labels or LEDs for system status
4. Copy the **Auth Token** and update it in the Arduino sketch

---
