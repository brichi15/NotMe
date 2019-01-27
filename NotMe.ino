#include "Servo.h"

Servo myServo;
int serialData = 0;
int bval = 0;
int button = 2;

                      ///////////////////functions/////////////////////
int sRead(){
  int serialData = 0;
  if(Serial.available() > 0){
    serialData = Serial.read();
  }

  return serialData;
}

                      //////////////////////setup and loop//////////////
void setup() {
  Serial.begin(9600); 
  myServo.attach(9);
  pinMode(button,INPUT);
  myServo.write(2);
}

void loop() {
  
  serialData = sRead();
  bval = digitalRead(button);
  
  if(serialData||bval){
    myServo.write(2);
    delay(2000);
  }

  myServo.write(178);
}
