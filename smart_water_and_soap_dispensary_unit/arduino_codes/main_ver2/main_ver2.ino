#include <HCSR04.h>
int wPump = 7;
int sPump = 8;
float pDistance;

int red = 4;
int yellow = 5;
int green = 6;

UltraSonicDistanceSensor distanceSensor(13, 12);  // Initialize sensor that uses digital pins 13 and 12.

void setup () {
  Serial.begin(9600);  // We initialize serial connection so that we could print values from sensor.

  pinMode(wPump, OUTPUT);
  pinMode(sPump, OUTPUT);

  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);

}

void loop () {

 
    

  if (Serial.available() > 0) {
    String palm_size = Serial.readStringUntil('\n'); // Read the incoming data

     pDistance = distanceSensor.measureDistanceCm();
     
    if (pDistance >= 30 && pDistance <= 35) {

      digitalWrite(green, HIGH);
      digitalWrite(red, LOW);
      digitalWrite(yellow, LOW);

      Serial.println(palm_size);

      digitalWrite(sPump, HIGH);
      int SoapQTTY = calculate_soap_qtty(palm_size.toInt());
      delay(SoapQTTY);
      digitalWrite(sPump, LOW);
      delay(3000);


      digitalWrite(wPump, HIGH);
      int WaterQTTY = calculate_water_qtty(palm_size.toInt());
      delay(WaterQTTY);
      digitalWrite(wPump, LOW);
      delay(3000);

      
      digitalWrite(green, LOW);


    }


      if (pDistance < 30) {
        digitalWrite(yellow, HIGH);
        delay(200);
        digitalWrite(yellow, LOW);
        delay(200);
      }

      if (pDistance > 35) {
        digitalWrite(red, HIGH);
        delay(200);
        digitalWrite(red, LOW);
        delay(200);
      }



    //    Serial.print("Received: ");
    //    Serial.println(incomingData);
  } else {
    digitalWrite(red, HIGH);
  }




}


int calculate_soap_qtty(int palm_size) {

  if (palm_size >= 500 && palm_size <= 600) {
    return 5000;
  }

  else if (palm_size >= 601 && palm_size <= 700) {
    return 6000;
  }

  else if (palm_size >= 701 && palm_size <= 800) {
    return 7000;
  }
  else if (palm_size >= 801 && palm_size <= 900) {
    return 8000;
  }

  else if (palm_size >= 901 && palm_size <= 1000) {
    return 9000;
  }

  else if (palm_size >= 1001 && palm_size <= 1100) {
    return 10000;
  }
  else if (palm_size >= 1101 && palm_size <= 1200) {
    return 12000;
  }

  else {
    return 5000;
  }



}

int calculate_water_qtty(int palm_size) {


  if (palm_size >= 500 && palm_size <= 600) {
    return 15000;
  }

  else if (palm_size >= 601 && palm_size <= 700) {
    return 16000;
  }

  else if (palm_size >= 701 && palm_size <= 800) {
    return 17000;
  }
  else if (palm_size >= 801 && palm_size <= 900) {
    return 18000;
  }

  else if (palm_size >= 901 && palm_size <= 1000) {
    return 19000;
  }

  else if (palm_size >= 1001 && palm_size <= 1100) {
    return 20000;
  }
  else if (palm_size >= 1101 && palm_size <= 1200) {
    return 21000;
  }

  else {
    return 5000;
  }

}
