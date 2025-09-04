# 🌐 ESP32 Sensor Web Dashboard

A **practice IoT project** using **ESP32** that hosts a web server to display real-time sensor data.
The webpage shows **Temperature, Humidity, and Soil Moisture** values, and also provides a button to **take a picture** from the ESP32-CAM (if connected).

---

## ✨ Features

* 📡 ESP32 runs its own web server
* 🔄 Auto-refresh page every 3 seconds
* 🌡️ Displays Temperature, Humidity & Moisture data
* 📷 Button to capture an image
* 🎨 Simple, styled HTML interface

---

## 🛠️ Hardware Used

* ESP32 (or ESP32-CAM)
* DHT11/DHT22 Sensor (for Temp & Humidity)
* Soil Moisture Sensor
* (Optional) ESP32-CAM for camera feature

---

## 🚀 How To Use

1. Upload the Arduino code to ESP32 using Arduino IDE.
2. Connect ESP32 to Wi-Fi or set it as an Access Point.
3. Open the serial monitor to get the **IP address**.
4. Open a browser and type the IP address.
5. View real-time sensor data and take pictures directly from the webpage.

---

## 🖥️ Web Interface Preview

```html
<h1>ESP32 Sensor Data</h1>
<p>Temperature (C): 25</p>
<p>Humidity (%): 60</p>
<p>Moisture Value: 450</p>
<button>Take a Picture</button>
```

---

## 🔮 Future Improvements

* Add charts for live sensor readings 📊
* Store data in cloud or database
* Mobile-friendly dashboard
* Control actuators (Fan, Pump, etc.)

---

✨ This is just a **practice project**, but it’s a great step into learning **ESP32 Web Servers & IoT Dashboards** 🚀
