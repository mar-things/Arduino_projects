#include <SoftwareSerial.h> 

SoftwareSerial BTSerial(10, 11); // RX, TX

void setup() {
  BTSerial.begin(9600); // Setting the baud rate
  Serial.begin(9600);
  Serial.println("Bluetooth Test");
}

void loop() {
  if (BTSerial.available()) {
    Serial.write(BTSerial.read());
  }
  if (Serial.available()) {
    BTSerial.write(Serial.read());
  }
}
