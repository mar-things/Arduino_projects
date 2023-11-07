

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



}
