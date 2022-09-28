
#include <AFMotor.h>

#define left A4
#define right A5

AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(2, MOTOR12_1KHZ);



void setup() {
 
  pinMode(left,INPUT);
  pinMode(right,INPUT);
 
  Serial.begin(9600);
  
}

void loop(){
  Serial.println(digitalRead(left));
  
  Serial.println(digitalRead(right));

 
  if(digitalRead(left)==0 && digitalRead(right)==0){
    motor1.run(FORWARD);
    motor1.setSpeed(150);
    motor2.run(FORWARD);
    motor2.setSpeed(150);
  }
  else if(digitalRead(left)==0 && !analogRead(right)==0){
    motor1.run(FORWARD);
    motor1.setSpeed(200);
    motor2.run(FORWARD);
    motor2.setSpeed(200);
    
  }
  
  else if(!digitalRead(left)==0 && digitalRead(right)==0){

    motor1.run(BACKWARD);
    motor1.setSpeed(200);
    motor2.run(BACKWARD);
    motor2.setSpeed(200);
    //motor3.run(FORWARD);
    //motor3.setSpeed(200);
    //motor4.run(FORWARD);
    //motor4.setSpeed(200);
   
  }
  //line detected by none
  else if(!digitalRead(left)==0 && !digitalRead(right)==0){
    //stop
    motor1.run(RELEASE);
    motor1.setSpeed(0);
    motor2.run(RELEASE);
    motor2.setSpeed(0);
    //motor3.run(RELEASE);
    //motor3.setSpeed(0);
    //motor4.run(RELEASE);
    //motor4.setSpeed(0);
   
  }
  
}
