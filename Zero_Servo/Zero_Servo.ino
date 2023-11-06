

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 130;    // variable to store the servo position

void setup() {
  myservo.attach(28);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
}

void loop() {

    myservo.write(pos);              // tell servo to go to position in variable 'pos'


      // read the input on analog pin 0:
  int sensorValue = analogRead(27);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  // print out the value you read:
  Serial.println(voltage);
  delay(100);
}
