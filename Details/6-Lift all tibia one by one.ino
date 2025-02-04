
//LIFITIN EACH TIBIA ONE BY ONE

#include <Servo.h>

Servo tibiaServos[6];

int tibiaPins[6] = {24, 27, 30, 33, 36, 39};



void setup(){


  //Attaching the normal femur servos

  for (int i=0; i <6; i++){
    if (i != 2){ //skip leg 3

      tibiaServos[i].attach(tibiaPins[i]);
      tibiaServos[i].write(90);
    }
  }


  delay(2000);

}

void loop(){

  for(int i =0; i<6; i++){
      tibiaServos[i].write(70); //lift...
      delay(1000);
      tibiaServos[i].write(60); //higher...
      delay(1000);
      tibiaServos[i].write(90);
      delay(2000);
  }
}
