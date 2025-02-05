//NEW PRESENTATION CODE

#include <Servo.h>

Servo femurServos[6];
Servo tibiaServos[6];

Servo femurContinuous;
Servo tibia3;

int femurPins[6] = {23, 26, 29, 32, 35, 38}; //Legs 1 through 6

int continuousFemurPin = 29;

int tibiaPins[6] = {24, 27, 30, 33, 36, 39};







void setup(){

  //Attaching the normal femur servos

  for (int i=0; i <6; i++){
    if (i != 2){ //skip leg 3

      femurServos[i].attach(femurPins[i]);
      //femurServos[i].write(90);
      
    }
  }

  //Attaching the normal tibia servos

    for (int i=0; i <6; i++){
    if (i != 2){ //skip leg 3

      tibiaServos[i].attach(tibiaPins[i]);
      //tibiaServos[i].write(90);
      
    }
  }
  

  /////////////////Femur Positions

  femurServos[0].write(90); //Femur for leg 1
  femurServos[1].write(80); //Femur for leg 2 >90 = lift
  //femurServos[2].write(90); //Femur for leg 3
  femurServos[3].write(90); //Femur for leg 4
  femurServos[4].write(90); //Femur for leg 5
  femurServos[5].write(90); //Femur for leg 6


  /////////Tibia Positions

  tibiaServos[0].write(90); //Tibia for leg 1
  tibiaServos[1].write(110); //Tibia for leg 2.  <90 = lift
  //tibiaServos[2].write(90); //Tibia for leg 3
  tibiaServos[3].write(110); //Tibia for leg 4
  tibiaServos[4].write(90); //Tibia for leg 5
  tibiaServos[5].write(90); //Tibia for leg 6

  delay(3000); //wait three seconds

  femurServos[1].write(120);
  delay(500); 
  femurServos[1].write(140);
  delay(1000);
  femurServos[1].write(80);
  delay(1000); 

}








void loop(){
/*
  for(int i =0; i<6; i++){
    if(i != 2){
      femurServos[i].write(90); //natural
      delay(1000);
      femurServos[i].write(140); // lift
      delay(1000);
      femurServos[i].write(90);
      delay(2000);
    }
  }
 */
}
