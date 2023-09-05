void setup() {
  for(int i =2; i<8; i++){
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
  Serial.begin(9600);  // Set the baud rate to match the Python script
}

void loop() {
  if (Serial.available() > 0) {
    // Read the incoming command
    String command = Serial.readStringUntil('\n');
    
    // Check the command and take action
    if (command.startsWith("DigitalWrite")) {
      // Example command: "DigitalWrite 3"
      int spaceIndex = command.indexOf(' '); // Find the space character
      if (spaceIndex != -1) {
        String pinString = command.substring(spaceIndex + 1); // Extract the part after the space
        int pinNumber = pinString.toInt(); // Convert the extracted string to an integer

        // Check if the pin number is within the valid range
        if (pinNumber >= 2 && pinNumber <= 7) {
          // Set all pins to LOW before setting the selected pin to HIGH
          for (int i = 2; i <= 7; i++) {
            digitalWrite(i, LOW);
          }
          // Set the selected pin to HIGH
          digitalWrite(pinNumber, HIGH);
        }
      }
    }
  }
}
