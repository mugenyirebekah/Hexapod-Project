//normal...stanidng position

#include <Servo.h>

Servo servos[18];

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 18; i++) {
    servos[i].attach(i + 22); // Start from pin 22
    servos[i].write(90); // Set to middle position
  }
}

void loop() {}
