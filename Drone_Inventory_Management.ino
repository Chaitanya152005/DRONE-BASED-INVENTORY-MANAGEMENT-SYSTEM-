#include <Arduino.h>
#include <WiFi.h>
#include <WiFiManager.h>
#include <WiFiClientSecure.h>
#include <Firebase_ESP_Client.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>

// --- OBJECTS ---
FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;
WiFiClientSecure client;

// Telegram Setup
UniversalTelegramBot bot("YOUR_TELEGRAM_BOT_TOKEN", client);
String CHAT_ID = "YOUR_CHAT_ID";

String current_shelf = "NONE";

void setup() {
Serial.begin(115200);
delay(1000);
Serial.println("\n--- SYSTEM BOOTING ---");

Serial2.begin(9600, SERIAL_8N1, 16, 17);

WiFiManager wm;
wm.autoConnect("Drone_Payload_Setup");
Serial.println("WiFi Connected!");

// --- NEW: SYNC TIME FOR SSL ---
configTime(0, 0, "pool.ntp.org");
Serial.print("Syncing Time");
time_t now = time(nullptr);
while (now < 24 * 3600) { // Wait until time is set
delay(500);
Serial.print(".");
now = time(nullptr);
}
Serial.println(" Synced!");

// --- FIREBASE SETUP ---
config.api_key = "YOUR_FIREBASE_API_KEY";
config.service_account.data.client_email = "YOUR_SERVICE_ACCOUNT_EMAIL";
config.service_account.data.project_id = "YOUR_PROJECT_ID";
config.service_account.data.private_key = "YOUR_FIREBASE_PRIVATE_KEY"


Firebase.begin(&config, &auth);
Firebase.reconnectWiFi(true);
Serial.println("Firebase Initialized!");

// --- TELEGRAM SETUP ---
client.setInsecure();
Serial.print("Connecting to Telegram...");
if(bot.sendMessage(CHAT_ID, "🚀 Drone System Online!", "")) {
Serial.println(" SUCCESS!");
} else {
Serial.println(" FAILED.");
}
}

void loop() {
if (Serial2.available()) {
String scan = Serial2.readStringUntil('\r');
scan.trim();
if (scan.length() > 0) {
Serial.print("\n[SCAN]: "); Serial.println(scan);
if (scan.startsWith("QR_")) {
processShelf(scan);
} else {
processProduct(scan);
}
}
}
}

void processShelf(String qr) {
Serial.println("Accessing Firestore (Shelves)...");
String path = "shelves/" + qr;
if (Firebase.Firestore.getDocument(&fbdo, "YOUR_PROJECT_ID", "", path.c_str(), "")) {
FirebaseJson json;
json.setJsonData(fbdo.payload().c_str());
FirebaseJsonData result;
if (json.get(result, "fields/location_name/stringValue")) {
current_shelf = result.stringValue;
Serial.println("--------------------------------");
Serial.print("SUCCESS: Now at Shelf "); Serial.println(current_shelf);
Serial.println("--------------------------------");
}
} else {
Serial.print("Error: "); Serial.println(fbdo.errorReason());
}
}

void processProduct(String barcode) {
if (current_shelf == "NONE") {
Serial.println("Scan Shelf QR first!");
return;
}
Serial.println("Verifying Product: " + barcode);
String path = "Inventorys_DB1/" + barcode;

if (Firebase.Firestore.getDocument(&fbdo, "YOUR_PROJECT_ID", "", path.c_str(), "")) {
FirebaseJson json;
json.setJsonData(fbdo.payload().c_str());
FirebaseJsonData res_loc, res_name;

json.get(res_loc, "fields/expected_location/stringValue");
json.get(res_name, "fields/name/stringValue");

String expected = res_loc.stringValue;
String p_name = (res_name.stringValue == "") ? "Unknown Item" : res_name.stringValue;

if (expected != current_shelf) {
  Serial.println("!!! MISMATCH !!! Sending Telegram...");
  String alert = "⚠️ MISMATCH DETECTED\n\nItem: " + p_name + "\nShould be at: " + expected + "\nFound at: " + current_shelf;
  
  if(bot.sendMessage(CHAT_ID, alert, "")) {
    Serial.println("Telegram Sent!");
  } else {
    Serial.println("Telegram Failed to send.");
  }
} else {
  Serial.println("Verified: Location Correct.");
}


}
}

