//PRESENTATION CODE


#include <Servo.h>

Servo allServos[18];

Servo femurServos[6]; //servos for femur movements

Servo femur3;  //leg three continuous servo  
Servo tibia3;  //leg three not continuous servo

int femurPins[6] = {23, 26, 29, 32, 35, 38};


void initializeServos(){      //function to initialize all the servos (standing position)
  
  for (int i=0; i<18; i++){
    allServos[i].attach(i+22);
    allServos[i].write(90);
  }
}


void attachFemurServos(){     //attaching femur servos
  
  for (int i=0; i <6; i++){
      if (i != 2){ //skip leg 3

      femurServos[i].attach(femurPins[i]);
      femurServos[i].write(90);
    }
  }

  delay(2000);

}

void liftFemurOneByOne(){

  for (int i = 0; i<6; i++){
    if(i !=2){
      femurServos[i].write(90); //natural
      delay(1000);
      femurServos[i].write(140); //lift
      delay(1000);
      femurServos[i].write(90); //back to natural
      delay(2000);

    }
  }
}



void setup(){

  initializeServos();
  attachFemurServos();

}

void loop(){

  liftFemurOneByOne();
}


