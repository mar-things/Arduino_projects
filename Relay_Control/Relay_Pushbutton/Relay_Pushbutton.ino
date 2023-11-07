const int button = 2;
const int relay = 13;
int buttonState = 0;

void setup() {
Serial.begin(9600);
pinMode(relay, OUTPUT);
pinMode(button, INPUT);
}

void loop() {
buttonState = digitalRead(button);
Serial.println(button);


if (buttonState == HIGH) 
  {
  digitalWrite(relay, HIGH);
  }else{
  digitalWrite(relay, LOW);
  }
  
}
