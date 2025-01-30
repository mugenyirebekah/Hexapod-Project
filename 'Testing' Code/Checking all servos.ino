//Checking all servos (zero)

//should be in a natural standing position

#include <Servo.h>

Servo servos[18];

void setup() {
  Serial.begin(9600);
  for (int n = 0; n < 18; n++) {
    servos[n].attach(n + 23, 600, 2600); // Adjust PWM range if necessary
    servos[n].write(90); // Center all servos
  }
  Serial.println("Servos set to neutral (90 degrees).");
}

void loop() {}

