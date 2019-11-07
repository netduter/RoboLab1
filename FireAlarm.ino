#include "RoboLab1.h"


FireAlarm::FireAlarm(int fireSensorPin,int buzzerPin,int ledAlarmPin ){

  this->fireSensorPin=fireSensorPin;
  this->buzzerPin=buzzerPin;
  this->ledAlarmPin=ledAlarmPin;
  pinMode(buzzerPin,OUTPUT);
  pinMode(ledAlarmPin,OUTPUT);
  
}

void FireAlarm::calibrate(){

  static unsigned long sampleSize=0;

  static unsigned long noiseSum=0;  

  int sensorValue=analogRead(fireSensorPin);
  
  if(sampleSize<MAX_SAMPLE_SIZE){

    noiseSum+=sensorValue;
    sampleSize++;
  }else{

    noiseLevel=noiseSum/sampleSize;
  }

  
 
}

void FireAlarm::checkForFire(){

  int sensorValue=analogRead(fireSensorPin);

//  Serial.println(noiseLevel);
//  Serial.println(sensorValue);

  if(sensorValue<(1-STATISTICAL_SIGNIFICANCE_LEVEL) * noiseLevel){

    digitalWrite(buzzerPin,HIGH);
    digitalWrite(ledAlarmPin,HIGH);

    
  }else{

    digitalWrite(buzzerPin,LOW);
    digitalWrite(ledAlarmPin,LOW);
  }
  
}

void FireAlarm::update(){

  if(noiseLevel==NULL){

    calibrate();
  }else{

    checkForFire();
  }
  
}
