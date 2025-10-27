# Temperature-controller
This project is a Temperature Controller System built using an Arduino, DHT11 temperature sensor, and a motor (or fan) driver module. The system continuously monitors the surrounding temperature using the DHT11 sensor and automatically turns ON/OFF the motor or fan based on preset temperature conditions.
# 🌡️ Temperature Controller using Arduino

## 📘 Overview
This project is a **Temperature Controller System** built using an **Arduino**, **DHT11 temperature sensor**, and a **motor (or fan) driver module**.  
It continuously monitors the ambient temperature and automatically controls a **heater (LED)** and **fan speed** based on the temperature range.  
The system also displays real-time temperature and humidity on an **LCD screen**.

---

## ⚙️ Features
- Real-time **temperature and humidity monitoring** using DHT11 sensor  
- **Automatic fan speed control** (Low / Medium / High)  
- **Heater (LED)** turns ON when temperature falls below 27°C  
- **LCD display** for live temperature and humidity readings  
- Simple, cost-effective, and easy to build project  

---

## 🧠 Working Principle
1. The **DHT11 sensor** measures the surrounding temperature and humidity.  
2. The Arduino reads this data and checks the temperature range.  
3. Based on the temperature, the system automatically controls the **heater (LED)** and **fan speed** using the motor driver.

### 🔥 Temperature Control Logic
| Temperature Range | Action | Description |
|--------------------|---------|-------------|
| Below **27°C** | Heater (LED) ON | Indicates heating mode (cold condition) |
| **27°C – 29°C** | Fan ON (Low Speed) | Mild cooling |
| **30°C – 32°C** | Fan ON (Medium Speed) | Moderate cooling |
| Above **32°C** | Fan ON (High Speed) | Maximum cooling |

4. The **LCD display** continuously shows real-time temperature and humidity readings.

---

## 🔌 Components Used
| Component | Quantity | Description |
|------------|-----------|-------------|
| Arduino Uno / Nano / ESP32 | 1 | Microcontroller board |
| DHT11 Sensor | 1 | Temperature and humidity sensor |
| L293D Motor Driver | 1 | Motor driver IC or module |
| DC Motor / Fan | 1 | Output fan |
| 16x2 I2C LCD | 1 | Display module |
| LED + Resistor | 1 | Used as heater indicator |
| Jumper Wires | - | For connections |
| Breadboard | 1 | Prototype setup |

---

## 🧾 Required Libraries
Make sure you have the following libraries installed in your Arduino IDE:
```cpp
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
