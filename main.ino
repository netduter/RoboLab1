#include "RoboLab1.h"


TrafficLights* trafficLights=NULL;
FireAlarm* fireAlarm=NULL;
ObjectDetector* objectDetector=NULL;
void setup() {

 

//το Pin 2 ελέγχει το κόκκινο , τα pins 4 κ 3 φτιάχνουν το πορτοκαλί χρώμα (Ο Θεός να το κάνει) , το Pin 7 το κόκκινο
//  , Οι επόμενες τρεις τιμές είναι σε millisecond και ορίζουν πόσο θα διαρκεί το κόκκινο , πορτοκαλί και πράσινο
//χρώμα αντίστοιχα.
  trafficLights=new TrafficLights(2,4,3,7,2000,2000,5000);

//Απο το A0 διαβάζει, στο Pin 8 είναι συνδεδεμένο το Buzzer και το 13 ένα led που ανάβει μόλις
//ανιχνευτεί φωτιά.
  fireAlarm=new FireAlarm(A0,8,13);

  //Triger pin στο 9 echo Pin στο 10
   objectDetector=new ObjectDetector(9,10);
  
  Serial.begin(9600);

}




void loop() {

  
 
   trafficLights->update();
  
   fireAlarm->update();   
   
   objectDetector->printNewDistance();
  
  
   


}
