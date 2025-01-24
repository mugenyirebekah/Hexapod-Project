/*Project Begins

Date: Jan - 24th - 2024

Author: Rebekah Mugenyi

Description:

Notes:

servod11 should be read 'servo 1-1' and refers to the location of the servo...leg 1 servo 1

*/

#include <Servo.h>

// Define servo pin and offset
#define LEG_1_SERVO_1 8 
#define LEG_1_SERVO_2 9
#define J1_OFFSET 45        //macro that defines an offset of 45 degrees


Servo servo11;                //creates an instance of the 'Servo' class called 'servo11'...
Servo servo12;



// Function to move the servo
void move_joint(double j1) {
  if (j1 >= -15 && j1 <= 105) {   //make sure that the servo is within a safe range
    servo11.write(j1 + J1_OFFSET);  // Adjust with offset and move the servo
    servo12.write(j1 + J1_OFFSET);
  }
}

void setup() {

  servo11.attach(LEG_1_SERVO_1, 600, 2600); //...basically callibration
  servo12.attach(LEG_1_SERVO_2, 600, 2600);
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
