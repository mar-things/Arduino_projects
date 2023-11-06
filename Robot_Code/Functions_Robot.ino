///////////////////////////////////////FUNCTIONS/////////////////////////////////////
  
void pwr_status() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);                       
  digitalWrite(LED_BUILTIN, LOW);   
  delay(1000); 

}


void ISR_countL()  
{
  counter_L++;
   
} 
 

void ISR_countR()  
{
  counter_R++; 
}


void Forward(int speed,String dir) {
  
        
    analogWrite(enA,speed);
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    
    if (dir == "left"){
      analogWrite(servoM,120);
    }else if (dir == "right"){
      analogWrite(servoM,60);
    }else if(dir == "straight"){
      analogWrite(servoM,90);
    }
    
}

void Backward(int speed,String dir) {
    analogWrite(enA,speed);
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
    
      if (dir == "left"){
      analogWrite(servoM,120);
    }else if (dir == "right"){
      analogWrite(servoM,60);
    }else if (dir == "straight"){
      analogWrite(servoM,90);
    }
}







void Counter() {
  
  int stateLast ;//= digitalRead(encL);
  int stateCurrent;
  int rotationCount = 0;
  int stateCount = 0;
  int stateCountTotal = 0;
  int statesPerRotation = 7;
  int distancePerStep;
  int wDiameter = 77; // Wheel Diameter in mm
  int wdistance;
  

  distancePerStep = wDiameter/statesPerRotation;
  
   //Counter
   while(1){
    stateCurrent = digitalRead(encL);
    
      if (stateCurrent != stateLast){
        stateLast = stateCurrent;
        stateCount++;
        stateCountTotal++;
      }
      if (stateCount == statesPerRotation){
        rotationCount++;
        stateCount = 0;
      }
   }
  
    wdistance = distancePerStep*stateCountTotal;
    Serial.print("distance: ");
    Serial.println(wdistance);
}






