// Pin 2: Input for reading the button
// Output for controlling the direction of the motor 
// Pin A6 & A7 motor direction (Potentiometers)



int y_axis = 0;
int x_axis = 0;
int R_motor_FWD ;
int R_motor_REV ;
int L_motor_FWD ;
int L_motor_REV ;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
 
  pinMode(y_axis,INPUT);
  pinMode(x_axis,INPUT);
  pinMode(R_motor_FWD,OUTPUT);
  pinMode(R_motor_REV,OUTPUT);
  pinMode(L_motor_FWD,OUTPUT);
  pinMode(L_motor_REV,OUTPUT);
}

void loop() {
  y_axis=analogRead(A7);
  x_axis=analogRead(A6);
  
  R_motor_FWD = map(y_axis,470,0,0,255);
  R_motor_REV = map(y_axis,550,1023,0,255);
  L_motor_FWD = map(y_axis,470,0,0,255);
  L_motor_REV = map(y_axis,550,1023,0,255);
    
  analogWrite(6,R_motor_FWD);
  analogWrite(9,R_motor_REV);
  analogWrite(11,L_motor_FWD);
  analogWrite(10,L_motor_REV);
 
}
