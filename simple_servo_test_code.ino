#include <Servo.h>
Servo servo;

void setup() {
  servo.attach(3); // Replace 9 with your servo's control pin
}

void loop() {
  servo.write(90);  // Stop (for continuous rotation)
  delay(2000);

  servo.write(0);   // Full-speed rotation in one direction
  delay(2000);

  servo.write(180); // Full-speed rotation in the other direction
  delay(2000);
}
