const int button = 2;
const int relay = 13;
int buttonState = 0;
int val;

void setup() {
Serial.begin(9600);
pinMode(relay, OUTPUT);
pinMode(button, INPUT);
}

void loop() {
buttonState = digitalRead(button);
Serial.println(button);


if (buttonState == HIGH && val == LOW) {
    digitalWrite(relay, HIGH);
    val = HIGH;
    delay(500);
  } else if (buttonState == HIGH && val == HIGH) {
    
    digitalWrite(relay, LOW);
    val = LOW;
    delay(500);
  }

  
}
