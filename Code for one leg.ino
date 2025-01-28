
//Stripped code...for one leg...from 'main'

#include <Servo.h>

#define PI 3.1415
#define FEMUR_L 60
#define TIBIA_L 95.334
#define TIBIA_ANGLE 17.543
#define Y_OFFSET 50
#define Z_OFFSET -90

#define J1_OFFSET 45
#define J2_OFFSET 0
#define J3_OFFSET 90

Servo servos[3];

double x = 0.0;
double y = 0.0;
double z = 0.0;

void setup()
{
  Serial.begin(9600);
  delay(15000);
  for (int n = 0; n < 3; n++)
    servos[n].attach(n + 23, 600, 2600);
  move_xyz(0, 0, 0, 0);
  delay(1000);
}

void move_joints(int leg, double j1, double j2, double j3)
{
  if (j1 >= -15 && j1 <= 105 && j2 >= 0 && j2 <= 90 && j3 >= 0 && j3 <= 90)
  {
    servos[leg * 3].write(j1 + J1_OFFSET);
    servos[leg * 3 + 1].write(j2 + J2_OFFSET);
    servos[leg * 3 + 2].write(j3 + J3_OFFSET);
  }
  else
  {
    Serial.print("Out of bounds servo command: ");
    Serial.print(j1);
    Serial.print(" ");
    Serial.print(j2);
    Serial.print(" ");
    Serial.println(j3);
  }
}

void move_xyz(int leg, double x, double y, double z)
{
  // inverse kinematics
  y += Y_OFFSET;
  z += Z_OFFSET;

  double l = sqrt(x * x + y * y + z * z);
  double j1 = atan(x / y);
  double j2 = acos((FEMUR_L * FEMUR_L - TIBIA_L * TIBIA_L + l * l) / (2 * FEMUR_L * l)) + atan(z / sqrt(x * x + y * y));
  double j3 = acos((FEMUR_L * FEMUR_L + TIBIA_L * TIBIA_L - l * l) / (2 * FEMUR_L * TIBIA_L));

  j1 = 45 + j1 * (180 / PI);
  j2 = 30 + j2 * (180 / PI);
  j3 = 90 + 30 - TIBIA_ANGLE - j3 * (180 / PI);

  move_joints(leg, j1, j2, j3);
}

void loop()
{
  double x_target = 15.0;
  double y_target = 15.0;
  double z_target = 0.0;

  for (double t = 0.0; t < 1.0; t += 0.02)
  {
    x = (1 - t) * 0.0 + t * x_target;
    y = (1 - t) * 0.0 + t * y_target;
    z = 3 * STEP_RADIUS * sqrt(1 - (1 - t) * (1 - t)); // swing up
    move_xyz(0, x, y, z);
    delay(10);
  }

  for (double t = 0.0; t < 1.0; t += 0.02)
  {
    x = (1 - t) * x_target + t * 0.0;
    y = (1 - t) * y_target + t * 0.0;
    z = 3 * STEP_RADIUS * sqrt(1 - t * t); // swing down
    move_xyz(0, x, y, z);
    delay(10);
  }
}
