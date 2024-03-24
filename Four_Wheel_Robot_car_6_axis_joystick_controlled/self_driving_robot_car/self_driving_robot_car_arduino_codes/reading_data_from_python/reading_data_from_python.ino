void setup() {
  Serial.begin(9600); // Initialize serial communication at 9600 baud rate
}

void loop() {
  if (Serial.available() > 0) {
    String incomingData = Serial.readStringUntil('\n'); // Read the incoming data

    // Process the received data
    // In this example, we'll simply print it to the Serial Monitor
    Serial.print("Received: ");
    Serial.println(incomingData);
  }
}
