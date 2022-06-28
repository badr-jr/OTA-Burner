#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

#include <FirebaseESP8266.h>
#include "credentials_config.h"
// Set these to run example.
#define FIREBASE_HOST "https://ota-stm32-programmer-default-rtdb.europe-west1.firebasedatabase.app"
#define FIREBASE_AUTH "I6bkeF77pz2b8KpJ1VBXZPUaq8aVbhRTlSi4FX8x"
char inChar;
String payload = "";
// Declare the Firebase Data object in the global scope
FirebaseData firebaseData;
String val= "example";
String temp = "";
// Get Request every timerDelay variable value in milliseconds
unsigned long lastTime = 0;
unsigned long timerDelay = 3;
int recordIndex;
int tempIndex = 0;
String recordFrame = "";
String response = "";
void setup() {
  // Setting baudrate to 115200
  Serial.begin(115200);
  // connect to wifi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.println("Connecting");
  // waiting for wifi to be connected
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
  Serial.println("Timer set to 5 seconds (timerDelay variable), it will take 5 seconds before publishing the first reading.");
    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);   // connect to firebase

  Firebase.reconnectWiFi(true);
  delay(1000);
}

void loop() {
  if ((millis() - lastTime) > timerDelay) {
    //Check if wifi is still connected
    if (WiFi.status() == WL_CONNECTED) {
            response = "";
            if (Serial.available())
            {
              response = Serial.readString();
              if (response.indexOf("ok"))
              {
                if (Firebase.getString(firebaseData, String(tempIndex))) {                           // On successful Read operation, function returns 1  
                val = firebaseData.stringData();
                Serial.println((val.substring(0,val.length()-2))+'$');
                tempIndex++;
                } 
                else {
                  Serial.println(firebaseData.errorReason());
                }
              }
            }
      }
      else {
      Serial.println("WiFi Disconnected");
    }
    // Resetting time
    lastTime = millis();
    }
  
    
  }
