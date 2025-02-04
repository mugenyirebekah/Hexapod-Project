#include <Servo.h>

// Define servos for one leg
Servo hip, femur, tibia;

void setup() {
  Serial.begin(9600);
  
  // Attach servos to their respective pins
  hip.attach(34);
  femur.attach(35);
  tibia.attach(36);

  // Move to neutral position
  hip.write(90);
  femur.write(90);
  tibia.write(90);

  delay(1000); // Allow servos to settle
}

void loop() {
  // Phase 1: Lift leg (Swing Up)
  hip.write(120);   // Move leg forward
  femur.write(120); // Lift femur slightly
  tibia.write(70);  // Bend tibia upward
  delay(500);

  // Phase 2: Place leg down
  femur.write(90);  // Lower femur
  tibia.write(90);  // Straighten tibia
  delay(500);

  // Phase 3: Push backward (Stance Phase)
  hip.write(60);    // Move leg backward
  femur.write(80);  // Adjust femur for balance
  tibia.write(100); // Adjust tibia slightly
  delay(500);

  // Phase 4: Return to neutral
  hip.write(90);
  femur.write(90);
  tibia.write(90);
  delay(500);
}
