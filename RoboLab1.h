#ifndef __EXERCISE_1__
#define  __EXERCISE_1__

class TrafficLights{


  private:

    // O συνδυασμός των δυο τιμών πρέπει κανονικά να παράγει
    // το πορτοκαλί χρώμα https://www.rapidtables.com/web/color/orange-color.html
    const int orangeRed=255;
    const int orangeGreen=165;

    //Πόσο χρόνο θα κρατάει το κάθε φανάρι σε millisecond
    int greenDuration=0, orangeDuration=0 ,redDuration=0;


    //Τα πινάκια που θα χρησιμοποιηθούν για να ελέγξουν το φανάρι.
    int redPin=-1, rgbRedPin=-1, rgbGreenPin=-1, greenPin=-1;

    //Η κλάση θα κρατάει τον χρόνο και θα ανάβει κόκκινο πορτοκαλί ή πράσινο.
    unsigned long long lightsCounter=0;


  public:

    //redPin για το κόκκινο φανάρι , rgbRedPin το pin για την rgb led που αφορά το χειρισμό της 
    //κόκκινης απόχρωσης , rgbGreenPin για την πράσινη απόχρωση, greenPin το πράσινο led.
    TrafficLights(int redPin,int rgbRedPin,int rgbGreenPin,int greenPin,
    int greenDuration, int orangeDuration, int redDuration);

    //Αλλάζει το πoio φανάρι είναι αναμμένο.
    void update();
};

class FireAlarm{

  public:
  //fireSensorPin : ο πιν του αισθητήρα που λαμβάνουμε τιμές για την ύπαρξη φωτιάς
  //buzzerPin το pin που θα σημάνει συναγερμό μόλις ανιχνευτεί φωτιά
   FireAlarm(int fireSensorPin,int buzzerPin,int ledAlarmPin );
   void update();

  private:

   
   int fireSensorPin=NULL;
   int buzzerPin=NULL;
   int ledAlarmPin=NULL;


   void calibrate();

   int noiseLevel=NULL;

   const int MAX_SAMPLE_SIZE=100;
   //Η κλάση θα ξεκινάει και θα βρίσκει την στάθμη της υπέρυθρης ακτινοβολίας.
   //Θα παίρνει ένα δείγμα μετρήσεων και αν κάποια από τις επόμενες μετρήσεις 
   //διαφέρει σημαντικά από το δείγμα θα σημαίνει συναγερμό.
   

   //Ελέγχει αν υπάρχει φωτιά στο χώρο
   void checkForFire();

   //Επίπεδο σημαντικότητας για την λήψη αποφάσεων.
   const float STATISTICAL_SIGNIFICANCE_LEVEL=0.02;
};


class ObjectDetector{

  public:

    ObjectDetector(int trigerPin,int echoPin);

    long getObjectDistance();
    void printNewDistance();

  private:

    int trigerPin=-1,echoPin=-1;

  
  
};






#endif
