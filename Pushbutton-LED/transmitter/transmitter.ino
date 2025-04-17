#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

const int botonPin = 13;  // Pushbutton pin
int buttonStatus = 0;
String receiverName = "ESP32_Receiver";  // Receiver name
bool connected = false;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_Transmisor", true);  // Transmitter name
  Serial.println("Bluetooth initiated in Transmitter");
  
  pinMode(botonPin, INPUT_PULLUP);
}

void loop() {
  if (!connected) {
    Serial.println("Trying to connect...");

    // Attempt to connect repeatedly until successful
    if (SerialBT.connect(receiverName)) {  // Attempts to connect to the receiver
      connected = true;
      Serial.println("Successful connection to the Receiver!");
    } else {
      Serial.println("Failed to connect. Trying again in 3 seconds...");
      delay(3000);  // Wait before retrying
    }
  }
  
  if (connected) {
    buttonStatus = digitalRead(botonPin);

    if (buttonStatus == LOW) {  // Pushbutton pressed
      SerialBT.println("ON");
      Serial.println("Signal sent: ON");
      delay(20);
    }
    else
    {
      SerialBT.println("OFF");
      Serial.println("Signal sent: OFF");
      delay(20);
    }
  }
}
