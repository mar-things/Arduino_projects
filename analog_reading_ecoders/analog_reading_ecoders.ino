
int encL = 26;
int encR = 27;

void setup() {
  pinMode(encL,INPUT);
  pinMode(encR,INPUT);
  Serial.begin(9600);
 

}

void loop() {
  
  Serial.println(analogRead(encL));
  delay(100);
  

}
