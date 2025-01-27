#include <Servo.h>

// Define servo pins and offset
#define LEG_1_SERVO_1 8 
#define LEG_1_SERVO_2 9
#define LEG_1_SERVO_3 10
#define J1_OFFSET 45        //macro that defines an offset of 45 degrees

//Create Servo objects
Servo servo11;                //creates an instance of the 'Servo' class called 'servo11'...
Servo servo12;
Servo servo13;

// Function to move the servos
void move_joint(double j1) {
  if (j1 >= -15 && j1 <= 105) {   //make sure that the servo is within a safe range
    servo11.write(j1 + J1_OFFSET);  // Adjust with offset and move the servo
    servo12.write(j1 + J1_OFFSET);
    servo13.write(j1 + J1_OFFSET);
  }
}

void move_servo11_back() {
  double initial_position_servo1 = 0;
  servo11.write(initial_position_servo1 + J1_OFFSET);
}

void move_servo12_back() {
  double initial_position_servo2 = 0;
  servo12.write(initial_position_servo2 + J1_OFFSET);
}

void move_servo13_back() {
  double initial_position_servo3 = 0;
  servo13.write(initial_position_servo3 + J1_OFFSET);
}

void setup() {
  servo11.attach(LEG_1_SERVO_1, 600, 2600); //...basically callibration
  servo12.attach(LEG_1_SERVO_2, 600, 2600);
  servo13.attach(LEG_1_SERVO_3, 600, 2600);
}

void loop() {
  // Example: Move all servos to position 30 degrees
  double j1 = 30;  // Angle for the joint
  move_joint(j1);  // Call the function with the angle to move all servos
  delay(1000);     // Wait for 1 second

  // Move servo 3 to initial position
  move_servo13_back();
  delay(1000);     // Wait for 1 second

  // Move servo 2 to initial position
  move_servo12_back();
  delay(1000);     // Wait for 1 second

  // Move servo 1 to initial position
  move_servo11_back();
  delay(1000);     // Wait for 1 second

  // Example: Move all servos to position 75 degrees
  j1 = 75;         // New angle for the joint
  move_joint(j1);  // Call the function with the new angle to move all servos
  delay(1000);     // Wait for 1 second

  // Move servo 3 back to initial position
  move_servo13_back();
  delay(1000);     // Wait for 1 second

  // Move servo 2 back to initial position
  move_servo12_back();
  delay(1000);     // Wait for 1 second

  // Move servo 1 back to initial position
  move_servo11_back();
  delay(1000);     // Wait for 1 second
} 
