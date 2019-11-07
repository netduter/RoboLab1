#include "RoboLab1.h"


TrafficLights::TrafficLights(int redPin,int rgbRedPin,int rgbGreenPin,int greenPin ,
int greenDuration,int orangeDuration,int redDuration){


  this->redPin=redPin;
  pinMode(redPin,OUTPUT);
  this->rgbRedPin=rgbRedPin;
  pinMode(rgbRedPin,OUTPUT);
  this->rgbGreenPin=rgbGreenPin;
  pinMode(rgbGreenPin,OUTPUT);
  this->greenPin=greenPin;
  pinMode(greenPin,OUTPUT);

  this->greenDuration=greenDuration;
  this->orangeDuration=orangeDuration;
  this->redDuration=redDuration;

  
  this->lightsCounter=millis();
}


void TrafficLights::update(){


  if(millis()-this->lightsCounter<=this->greenDuration){

    digitalWrite(this->redPin,HIGH);
    digitalWrite(this->rgbRedPin,LOW);
    digitalWrite(this->rgbGreenPin,LOW);
    digitalWrite(this->greenPin,LOW);
    
  }else if(millis()-this->lightsCounter>=this->greenDuration && millis()-this->lightsCounter<=this->greenDuration+
  this->orangeDuration){

    digitalWrite(this->redPin,HIGH);
    analogWrite(this->rgbRedPin,LOW);
    analogWrite(this->rgbGreenPin,LOW);
    digitalWrite(this->greenPin,LOW);
    
  }else{

    if(millis()-lightsCounter<=greenDuration+redDuration){

      digitalWrite(this->redPin,LOW);
      digitalWrite(this->rgbRedPin,LOW);
      digitalWrite(this->rgbGreenPin,LOW);
      digitalWrite(this->greenPin,HIGH);
    }else{

      
      digitalWrite(this->redPin,LOW);
      analogWrite(this->rgbRedPin,orangeRed);
      analogWrite(this->rgbGreenPin,orangeGreen);
      digitalWrite(this->greenPin,HIGH);
      
    }

   
  
  }

  if(millis()-this->lightsCounter>this->greenDuration+this->redDuration+this->orangeDuration){

    lightsCounter=millis();
  }
  
}
