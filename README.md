# DRONE-BASED INVENTORY MANAGEMENT SYSTEM

## Overview
Smart Barcode Scanning Using Drone is an IoT-based warehouse inventory management system that automates barcode scanning using a drone-mounted payload. The system scans 1D barcodes, verifies product locations from Firebase database, and sends real-time Telegram alerts whenever a misplaced item is detected. 

---

## Features
- Drone-mounted barcode scanning system
- Supports 1D barcode scanning
- Real-time inventory synchronization using Firebase
- Automatic validation of expected and actual product locations
- Telegram notifications for inventory mismatches
- Modular payload design for easy integration with drones

---

## Hardware Used
- ESP32
- GM65 Barcode Scanner Module
- F450 Drone Frame
- Pixhawk Flight Controller
- Brushless Motors
- ESCs
- LiPo Batteries
- 5V BEC Step-Down Converter
- 6CH Transmitter & Receiver

---

## Software Used
- Arduino IDE
- Firebase Firestore
- Mission Planner

---

## System Workflow
1. Drone flies to a warehouse shelf.
2. Shelf QR code is scanned.
3. Product barcode is scanned.
4. ESP32 uploads barcode data to Firebase.
5. Firebase compares actual and expected locations.
6. Telegram Bot sends an alert if a mismatch is detected.

---

## Repository Structure

```
├── Code/
├── Circuit Diagram/
├── Images/
├── Documentation/
├── README.md
```

---

## Results
The prototype successfully:
- Scanned warehouse barcodes
- Uploaded inventory data to Firebase
- Detected misplaced items
- Sent real-time Telegram notifications to warehouse managers

---

## Future Improvements
- Autonomous navigation using SLAM
- AI-based computer vision
- Multi-drone warehouse scanning
- ERP integration 

---

## Author
- Chaitanya Bhuptani

---

## License
This project is licensed under the MIT License.
