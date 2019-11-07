#include "RoboLab1.h"

ObjectDetector::ObjectDetector(int trigerPin,int echoPin){


  this->trigerPin=trigerPin;
  this->echoPin=echoPin;

  pinMode(trigerPin,OUTPUT);
  pinMode(echoPin,INPUT);
  
}

void ObjectDetector::printNewDistance(){

  static unsigned long lastCall=0;

  long currentDistance=getObjectDistance();

  if(currentDistance>=0 && currentDistance<110 && millis()-lastCall>1000){

    Serial.print("Αντικείμενο στα ");
    Serial.print(currentDistance);
    Serial.println(" cm.");
    lastCall=millis();
    
  }
  
}

long ObjectDetector::getObjectDistance(){

  //Υλοποίηση από https://howtomechatronics.com/tutorials/arduino/ultrasonic-sensor-hc-sr04/

  long duration,distance;

  digitalWrite(trigerPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigerPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigerPin,LOW);

  duration=pulseIn(echoPin,HIGH);

  distance= duration*0.034/2;

  return distance;
  
}
