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
├── Images/
   ├──Block Diagram<img width="775" height="588" alt="image" src="https://github.com/user-attachments/assets/e6c8606b-2c87-4337-bcd8-57cc7dc92233" />
   ├──Circuit Diagram<img width="779" height="626" alt="image" src="https://github.com/user-attachments/assets/d7189553-9f44-4dce-92e5-1af6a6ac9171" />
   ├──Drone<img width="772" height="579" alt="image" src="https://github.com/user-attachments/assets/3b8958d0-828d-4624-b4dc-7f235380294d" />
   ├──Payload<img width="757" height="713" alt="image" src="https://github.com/user-attachments/assets/4971ba31-8b22-4a40-b901-944d8e723a76" />
   ├──Drone with Payload<img width="757" height="713" alt="image" src="https://github.com/user-attachments/assets/94beafac-e423-48e9-a00b-9670330d933d" />

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
Chaitanya Bhuptani

---

## License
This project is licensed under the MIT License.
