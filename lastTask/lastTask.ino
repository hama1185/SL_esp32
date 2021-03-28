#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  //Serial.begin(9600);
  SerialBT.begin("ESP32test");
}

void loop() {
  if (Serial.available()) {
    String sendData = Serial.readStringUntil(';');
    SerialBT.print(sendData);
  }

  if (SerialBT.available()) {
    String receiveData = SerialBT.readStringUntil(';');
    Serial.print(receiveData);
  }
}
