
// Include the Servo library
#include <Servo.h> 

// Declare the Servo pin
int servoPin = 3;
// Create a servo object
Servo Servo1;

void setup() {
  // We need to attach the servo to the used pin number
  Servo1.attach(servoPin);
}


String getValue(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length()-1;

  for(int i=0; i<=maxIndex && found<=index; i++){
    if(data.charAt(i)==separator || i==maxIndex){
        found++;
        strIndex[0] = strIndex[1]+1;
        strIndex[1] = (i == maxIndex) ? i+1 : i;
    }
  }

  return found>index ? data.substring(strIndex[0], strIndex[1]) : "";
}

void loop() {
  
  String computerText = Serial.readStringUntil('@');
  computerText.trim();
  if (computerText.length() == 0) {
    return;
  }
  // 92-0-130
  String command = getValue(computerText, ' ',0);

    if (command == "right" || command == "رايت" || command == "Right") {
Servo1.write(180); 
   delay(1000);     }
    if (command == "left" || command == "Left" || command == "لفت") {
    Servo1.write(0); 
   delay(1000); 
    }

    Serial.println(command);
  Serial.println("WORKING");
  delay(1000);

}
