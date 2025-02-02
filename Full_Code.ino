//hexapod code using inverse kinematics (external)
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

#define STEP_RADIUS 15

Servo servos[18];

int wave[6][6] = {
  {1, 0, 0, 0, 0, 0},
  {0, 1, 0, 0, 0, 0},
  {0, 0, 1, 0, 0, 0},
  {0, 0, 0, 1, 0, 0},
  {0, 0, 0, 0, 1, 0},
  {0, 0, 0, 0, 0, 1},
};

int ripple_phases[6][6] = {
  {1, 1, 0, 0, 0, 0},
  {0, 0, 1, 1, 0, 0},
  {0, 0, 0, 0, 1, 1},
  {0, 0, 0, 1, 1, 0},
  {1, 0, 0, 0, 0, 1},
  {0, 1, 1, 0, 0, 0},
};



/*
         , - ~ ~ ~ - ,
     , '               ' ,
    ,                     ,
    '----~----->-----~----'
  -1.0 -0.5   0.0   0.5  1.0
*/

double x = 0.0;
double y = 0.0;
double z = 0.0;

void setup()
{
  Serial.begin(9600);
  delay(15000);
  for(int n=0; n < 18; n++)
    servos[n].attach(n+23, 600, 2600);
  for(int leg=0; leg < 6; leg++){
    move_xyz(leg, 0, 0, 0);
  }
  delay(1000);
}

void move_joints(int leg, double j1, double j2, double j3)
{
  if (j1>=-15 && j1<=105 && j2>=0 && j2<=90 && j3>=0 && j3<=90){
    servos[leg*3].write(j1 + J1_OFFSET);
    servos[leg*3+1].write(j2 + J2_OFFSET);
    servos[leg*3+2].write(j3 + J3_OFFSET);
  } else {
    Serial.print("Out of bounds servo command on leg ");
    Serial.print(leg);
    Serial.print(": ");
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

  double l = sqrt(x*x + y*y + z*z);
  double j1 = atan(x/y);
  double j2 = acos((FEMUR_L*FEMUR_L - TIBIA_L*TIBIA_L + l*l) / (2*FEMUR_L*l)) + atan(z / sqrt(x*x + y*y));
  double j3 = acos((FEMUR_L*FEMUR_L + TIBIA_L*TIBIA_L - l*l) / (2*FEMUR_L*TIBIA_L));

  j1 = 45 + j1*(180/PI);
  j2 = 30 + j2*(180/PI);
  j3 = 90 + 30 - TIBIA_ANGLE - j3*(180/PI);

  //Serial.print(j1);
  //Serial.print(" ");
  //Serial.print(j2);
  //Serial.print(" ");
  //Serial.println(j3);
  move_joints(leg, j1, j2, j3);
}

double x_start[6] = {0.0};
double y_start[6] = {0.0};
double x_target[6] = {0.0};
double y_target[6] = {0.0};


/* starting phases for ripple */
int phase[6] = {0, 4, 2, 5, 1, 3};

double phase_targets[6] = {0.5, 1.0, 0.5, 0.0, -0.5, -1.0};
double leg_directions[6] = {-PI/6, -PI/2, -(5*PI)/6, (5*PI)/6, PI/2, PI/6};


void loop()
{
  // get targets
  for(int leg=0; leg < 6; leg++){
    double v_mag = 2*STEP_RADIUS*phase_targets[phase[leg]];
    double v_dir = 0.0;
    x_target[leg] = v_mag*sin(v_dir+leg_directions[leg]);
    y_target[leg] = v_mag*cos(v_dir+leg_directions[leg]);
  }

  for (double t=0.0; t < 1.0; t+=0.02){
    for (int leg=0; leg < 6; leg++){
      x = (1-t)*x_start[leg] + t*x_target[leg];
      y = (1-t)*y_start[leg] + t*y_target[leg];
      if (phase[leg] == 0) // swing up
        z = 3*STEP_RADIUS*sqrt(1-(1-t)*(1-t));
      else if (phase[leg] == 1) // swing down
        z = 3*STEP_RADIUS*sqrt(1-(t*t));
      else // stance
        z = 0;
      move_xyz(leg, x, y, z);
    }
    //delay(10);
  }

  // save end positions, increment phases
  for (int leg=0; leg < 6; leg++){
    phase[leg] = (phase[leg]+1) % 6;
    x_start[leg] = x_target[leg];
    y_start[leg] = y_target[leg];
  }
}

