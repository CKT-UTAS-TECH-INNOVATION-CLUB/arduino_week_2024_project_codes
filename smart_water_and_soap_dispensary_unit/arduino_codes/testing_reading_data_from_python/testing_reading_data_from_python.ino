void setup () {
  Serial.begin(9600); 
}

void loop () {

  if (Serial.available() > 0) {

     String palm_size = Serial.readStringUntil('\n'); // Read the incoming data

    Serial.println(palm_size);

  }else{
    
    Serial.println("No data read from python !!!");
    }



}
