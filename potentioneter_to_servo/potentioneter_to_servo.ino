#include <Servo.h>
Servo myservo;

int pot;
int servo = 3;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo.attach(3);


}

void loop() {
  // put your main code here, to run repeatedly:
  pot = analogRead(A3);
  Serial.println(pot);

  delay(10);
  int val = map(pot,0,1023,0,255);
  myservo.write(0);
}
