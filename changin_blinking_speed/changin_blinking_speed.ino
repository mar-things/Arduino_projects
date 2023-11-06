
int Led=4;
int pot= A5;
int time;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Led,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  int val=analogRead(pot);
  Serial.println(val);
  time = map(val,0,1023,20,1000);

  digitalWrite(Led,1);
  delay(time);
  digitalWrite(Led,0);
  delay(time);

}