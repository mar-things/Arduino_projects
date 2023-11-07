#include <Servo.h>
#include <VL53L0X.h>
#include <SerialBT.h>



          
////////////PINS///////////////////////

Servo servoM;

int encL=26;
int encR=27;

int enA = 18;
int in1 = 20;
int in2 = 19;

//int SDA_PIN = 4;
//int SCL_PIN = 5;



///////////////VARIABLES//////////////////////////

int initialL=100;
int initialR=0;

int laser_1;
int laser_2;
int laser_3;
int laser_4;
int laser_5;
int laser_6;
int laser_7;

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
  servoM.attach(28);
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
  if (laser_4<=400 ){
    Forward(0,"straight");
  }
  
 

  


//  SerialBT.print("Left counter: ");
//  SerialBT.print(counter_L);
//  Serial.print(" Right counter: ");
//  Serial.println(counter_R);


  
  

  }
