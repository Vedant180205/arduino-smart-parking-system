# 🚗 Arduino Smart Parking System

This project is a smart parking system built using Arduino and controlled via Bluetooth. The car operates in manual mode through an Android app, but when the `"PARK"` command is received, it performs an **autonomous parking sequence** using sensor data and pre-programmed logic.

---

## 🧠 How It Works

- The robotic car is Bluetooth-controlled.
- When the command `"PARK"` is sent via the mobile app, the Arduino triggers a parking routine.
- The car uses sensors (like ultrasonic and IR) to park itself into a designated spot without user control.

---

## 🔧 Components Used

- Arduino UNO / ESP32 DevKit
- HC-05 Bluetooth Module
- Ultrasonic Sensor (for obstacle detection)
- IR Sensor (for parking zone detection)
- Motor Driver Module (L298N or similar)
- 2 DC Motors + 1 caster wheel
- Chassis, wheels, wires, etc.

---

## 🧾 Features

- Manual control via Bluetooth app
- Trigger-based autonomous parking
- Sensor-based positioning and control
- Smooth transition from manual to auto mode

---

## 📁 Files in this Repo

- `smart_parking.ino` – Main Arduino code

---

## 🚀 Future Improvements

- Add more parking patterns (reverse, parallel)
- Use multiple ultrasonic sensors for better accuracy
- Display parking status on an LCD or over Bluetooth

---

## 📜 License

This project is licensed under the MIT License – you are free to use, modify, and share it.

---

## 🙋‍♂️ Author

**Vedant Patil**  
Second Year ECS Student  
Shah & Anchor Kuttchi Engineering College
