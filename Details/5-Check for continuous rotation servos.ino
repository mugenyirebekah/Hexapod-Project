#include <Servo.h>

Servo servo1; // First suspect servo
Servo servo2; // Second suspect servo

int servo1Pin = 28; 
int servo2Pin = 29; 

void setup() {
  Serial.begin(9600);

  servo1.attach(servo1Pin);
  servo2.attach(servo2Pin);

  Serial.println("Testing servos...");

  // Set both servos to 90 degrees
  servo1.write(90);
  servo2.write(90);
  delay(2000);  

  // Moving servos to 0 degrees
  servo1.write(0);
  servo2.write(0);
  delay(2000);  

  // Moving servos to 180 degrees
  servo1.write(180);
  servo2.write(180);
  delay(2000);  

  
}

void loop() {}
