#include <Servo.h>
#define encoder0PinA 3
#define encoder0PinB 2
#define button 4

Servo servo1, servo2, servo3, servo4, servo5;
int servoPos[] = {0, 0, 0, 0, 0};
int servoIndex = 0;
int encoder0Pos = 0;
int lastEncoder0Pos = 0;
int buttonState = 0;

void setup() {
  servo1.attach(8);
  servo2.attach(9);
  servo3.attach(10);
  servo4.attach(11);
  servo5.attach(12);
  pinMode(encoder0PinA, INPUT);
  pinMode(encoder0PinB, INPUT);
  pinMode(button, INPUT);
}

void loop() {
  digitalRead(button);
  digitaRead(encoder0Pos);
  buttonState = digitalRead(button);
  if (buttonState == HIGH) {
    servoIndex = (servoIndex + 1) % 5;
    while (digitalRead(button) == HIGH) {};
  }
  encoder0Pos = encoder0Pos + (digitalRead(encoder0PinA) == digitalRead(encoder0PinB) ? -1 : 1);
  if (encoder0Pos != lastEncoder0Pos) {
    servoPos[servoIndex] = constrain(servoPos[servoIndex] + (encoder0Pos - lastEncoder0Pos), 0, 180);
    switch (servoIndex) {
      case 0:
        servo1.write(servoPos[servoIndex]);
        break;
      case 1:
        servo2.write(servoPos[servoIndex]);
        break;
      case 2:
        servo3.write(servoPos[servoIndex]);
        break;
      case 3:
        servo4.write(servoPos[servoIndex]);
        break;
      case 4:
        servo5.write(servoPos[servoIndex]);
        break;
    }
    lastEncoder0Pos = encoder0Pos;
  }
}
