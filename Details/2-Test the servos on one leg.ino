
/*L1S1 = Leg 1 servo 1

*/


#include <Servo.h>

Servo L1S1;  
Servo L1S2;
Servo L1S3;


int pos = 0;    // variable to store the servo position

void setup() {
  Serial.begin(9600);

  L1S1.attach(22);
  L1S2.attach(23);
  L1S3.attach(24);

  delay(3000); //wait three seconds before zeroing the servos  

  L1S1.write(0);
  Serial.println("Servo 1 - zeroed");
  delay(3000);
  L1S2.write(0);
  Serial.println("Servo 2 - zeroed");
  delay(3000);
  L1S3.write(24); 
  Serial.println("Servo 3 - zeroed");
  delay(3000);
  Serial.println("All servos are zeroed");

}

void loop() {

  //Move leg one servo one

  for (pos = 0; pos <= 30; pos += 1) { // goes from 0 degrees to 30 degrees
    // in steps of 1 degree
    L1S1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(30);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 30; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    L1S1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }

  //Move leg one servo two

    for (pos = 0; pos <= 30; pos += 1) { // goes from 0 degrees to 30 degrees
    // in steps of 1 degree
    L1S2.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 30; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    L1S2.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }

    //Move leg one servo three

    for (pos = 0; pos <= 30; pos += 1) { // goes from 0 degrees to 30 degrees
    // in steps of 1 degree
    L1S3.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 30; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    L1S3.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }


}

