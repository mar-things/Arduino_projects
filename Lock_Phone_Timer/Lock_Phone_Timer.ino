#include <DigitLedDisplay.h>

#include <Servo.h>
#include <EEPROM.h>
#include <Countimer.h> //https://github.com/inflop/Countimer
#define bt_set    2
#define bt_up     3
#define bt_down   4



#define DIN 7
#define CS 6
#define CLK 5   
DigitLedDisplay ld = DigitLedDisplay(DIN, CS, CLK);

Servo myServo;
Countimer tdown;

int time_s = 0;
int time_m = 0;
int time_h = 0;

int set = 0;
int flag1=0, flag2=0;

//int buzzer = 9;

void setup() {
Serial.begin (9600);
myServo.attach(10);
pinMode(bt_set,   INPUT_PULLUP);
pinMode(bt_up,    INPUT_PULLUP);
pinMode(bt_down,  INPUT_PULLUP);

//pinMode(buzzer, OUTPUT);

/* Set the brightness min:1, max:15 */
ld.setBright(6);
/* Set the digit count */
ld.setDigitLimit(8);


tdown.setInterval(print_time, 999);
eeprom_read();
delay(1000);
// lcd.clear();
}

void print_time(){
time_s = time_s-1;
if(time_s<0){time_s=59; time_m = time_m-1;}
if(time_m<0){time_m=59; time_h = time_h-1;}
}

void tdownComplete(){Serial.print("ok");}

//tdown.stop(); 

void loop(){
   ld.printDigit(12345678); 
  delay(3000);
  ld.clear();

  ld.printDigit(22222222);
  delay(500);
  ld.clear();

  ld.printDigit(44444444);
  delay(500);
  ld.clear();
tdown.run();

if(digitalRead (bt_set) == 0){
if(flag1==0 && flag2==0){flag1=1;
set = set+1;
if(set>3){set=0;}
delay(100); 
}
}else{flag1=0;}

if(digitalRead (bt_up) == 0){
if(set==0){tdown.start(); flag2=1;}
if(set==1){time_s++;}
if(set==2){time_m++;}
if(set==3){time_h++;}
if(time_s>59){time_s=0;}
if(time_m>59){time_m=0;}
if(time_h>99){time_h=0;}
if(set>0){eeprom_write();}
delay(200); 
}

if(digitalRead (bt_down) == 0){
if(set==0){tdown.stop(); flag2=0;}
if(set==1){time_s--;}
if(set==2){time_m--;}
if(set==3){time_h--;}
if(time_s<0){time_s=59;}
if(time_m<0){time_m=59;}
if(time_h<0){time_h=99;}
if(set>0){eeprom_write();}
delay(200); 
}

if(digitalRead (bt_set) == 0){ flag2=1; 
  eeprom_read(); 
  myServo.write(90);
  tdown.restart(); 
  tdown.start();
}

// lcd.setCursor(0,0);
// if(set==0){lcd.print("      Timer     ");}
// if(set==1){lcd.print("  Set Timer SS  ");}
// if(set==2){lcd.print("  Set Timer MM  ");}
// if(set==3){lcd.print("  Set Timer HH  ");}

// lcd.setCursor(4,1);
// if(time_h<=9){lcd.print("0");}
// lcd.print(time_h);
// lcd.print(":");
// if(time_m<=9){lcd.print("0");}
// lcd.print(time_m);
// lcd.print(":");
// if(time_s<=9){lcd.print("0");}
// lcd.print(time_s);
// lcd.print("   ");

if(time_s==0 && time_m==0 && time_h==0 && flag2==1){flag2=0;
tdown.stop(); 
myServo.write(0);
digitalWrite(buzzer, HIGH);
delay(300);
digitalWrite(buzzer, LOW);
delay(200);
digitalWrite(buzzer, HIGH);
delay(300);
digitalWrite(buzzer, LOW);
delay(200);
digitalWrite(buzzer, HIGH);
delay(300);
digitalWrite(buzzer, LOW);
}

if(flag2==1){myServo.write(90);}
else{myServo.write(0);}

delay(1);
}

void eeprom_write(){
EEPROM.write(1, time_s);  
EEPROM.write(2, time_m);  
EEPROM.write(3, time_h);  
}

void eeprom_read(){
time_s =  EEPROM.read(1);
time_m =  EEPROM.read(2);
time_h =  EEPROM.read(3);
}
