/*Project Begins

Date: Jan - 24th - 2024

Author: Rebekah Mugenyi

Description:

*/

#include <Servo.h>

// Define servo pin and offset
#define LEG_1_SERVO_1 8 
#define J1_OFFSET 45        //macro that defines an offset of 45 degrees


Servo servo;                //creates an instance of the 'Servo' class called 'servo'...


// Function to move the servo
void move_joint(double j1) {
  if (j1 >= -15 && j1 <= 105) {   //make sure that the servo is within a safe range
    servo.write(j1 + J1_OFFSET);  // Adjust with offset and move the servo
  }
}

void setup() {

  servo.attach(LEG_1_SERVO_1, 600, 2600); //...basically callibration
}

void loop() {
  // Example: Move servo to position
  double j1 = 30;  // Angle for the joint
  move_joint(j1);  // Call the function with the angle
  delay(1000);     // Wait for 1 second

  // Example: Move servo to another position
  j1 = 75;
  move_joint(j1);
  delay(1000);
}

