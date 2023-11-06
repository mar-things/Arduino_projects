/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>

Servo myservo2;
Servo myservo3;
Servo myservo4;
Servo myservo6;// create servo object to control a servo

int potpin = A7;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin

void setup() {
  myservo2.attach(2);
  myservo3.attach(3);
  myservo4.attach(4);
  myservo6 .attach(6);// attaches the servo on pin 9 to the servo object
}

void loop() {
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 180);     // scale it for use with the servo (value between 0 and 180)
  myservo2.write(val);
  myservo3.write(val);
  myservo4.write(val);
  myservo6.write(val);// sets the servo position according to the scaled value
  delay(15);                           // waits for the servo to get there
}
