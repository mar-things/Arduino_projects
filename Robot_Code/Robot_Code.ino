#include <Servo.h>
#include <Adafruit_VL53L0X.h>
#include <SerialBT.h>

Adafruit_VL53L0X lox = Adafruit_VL53L0X();

          
////////////PINS///////////////////////

int servoM = 28;

int encL=26;
int encR=27;

int enA = 18;
int in1 = 20;
int in2 = 19;

//int SDA_PIN = 4;
//int SCL_PIN = 5;

int xSHUT1 = 6;
int xSHUT2 = 7;
int xSHUT3 = 8;
int xSHUT4 = 9;
int xSHUT5 = 10;
int xSHUT6 = 11;
int xSHUT7 = 12;

///////////////VARIABLES//////////////////////////

int initialL=100;
int initialR=0;
int distance;
volatile int counter_L = 0;
volatile int counter_R = 0;
char Incoming_value = 0;
String command;

///////////////FUNCTIONS//////////////////////////

void pwr_status();
void Forward();
void Backward();
void Counter();
void tof_init();
void tof_display();
void ISR_countL();
void ISR_countR();


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void setup() {
  
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(encL,INPUT);
  pinMode(encR,INPUT);
  pinMode(enA,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(servoM,OUTPUT);
  attachInterrupt(digitalPinToInterrupt(encL), ISR_countL, RISING);
  attachInterrupt(digitalPinToInterrupt(encR), ISR_countR, RISING);
  tof_init();
  

  SerialBT.begin();

}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void loop(){

  //pwr_status();


  
  tof_display();
  Forward(130,"left");
  
  if (distance<=400 ){
    Forward(0,"straight");
  }

//  SerialBT.print("Left counter: ");
//  SerialBT.print(counter_L);
//  Serial.print(" Right counter: ");
//  Serial.println(counter_R);

int sensorValue = analogRead(27);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  // print out the value you read:
  Serial.println(voltage);
  delay(100);
  
  

  }
