#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

const int ledPin = 2;  // LED Pin
String message = "";

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_Receiver"); // Receiver name
  Serial.println("Bluetooth initiated in Receiver");
  
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
}

void loop() {
  if (SerialBT.available()) {  // Bluetooth data is available
    message = SerialBT.readStringUntil('\n');
    message.trim();
    
    Serial.print("Received message: ");
    Serial.println(message);

    if (message == "ON") {
      digitalWrite(ledPin, HIGH);  // Lights up LED
      Serial.println("LED ON");
    } else {
      digitalWrite(ledPin, LOW);  // Turns off LED
      Serial.println("LED OFF");
    }
  }
}
