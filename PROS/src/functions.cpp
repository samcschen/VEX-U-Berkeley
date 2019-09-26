#include "declareStuff.hpp"

/*
This is the functions file of the program. Here you can make functions that you can call during for autonomus and driver control.
*/

float velocityToVoltage(int velocity){ //a function you can call to convert a velocity to a voltage
  return velocity*21;
}

void wait(int ms){ //a function you can call to wait a certain amount of ms while still having drive control
  for(int i = 0; i <= ms; i+=5){ //for loop (look it up)
    pros::delay(5); //wait 5 ms so we don't use up too much resources
    drive.arcade(MasterC.getAnalog(ControllerAnalog::leftY), MasterC.getAnalog(ControllerAnalog::leftX)); //prebuilt drive function
  }
}
