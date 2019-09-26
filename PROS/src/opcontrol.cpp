#include "declarestuff.hpp" //adds your motors, sensors, controllers, variables, and functions to the file

const int NUM_HEIGHTS = 5; //how many different preset positions you have for the lift
const int height0 = 0; //the first preset position. Relative to the starting position.
const int height1 = 180; //the second preset position. Relative to the starting position.
const int height2 = 350; //the third preset position. Relative to the starting position.
const int height3 = 600; //the fourth preset position. Relative to the starting position.
const int height4 = 700; //the fifth preset position. Relative to the starting position.

const int heights[NUM_HEIGHTS] = {height0, height1, height2, height3, height4}; //an array of all the heights you have

int goalHeight = 0; //the current height the lift is at


void driveControl(void* param){ //a task that runs at the same time as the other tasks
  while (true) { //infinite loop
    pros::delay(5); //short delay of 5 ms so that we don't use too much resources
    drive.arcade(MasterC.getAnalog(ControllerAnalog::leftY), MasterC.getAnalog(ControllerAnalog::leftX)); //prebuilt drive controller
  }
}


void liftControl(void* param){ //a task that runs at the same time as the other tasks
  while (true) { //infinite loop
    pros::delay(5); //short delay of 5 ms so that we don't use too much resources
    if (liftUpButton.changedToPressed() && goalHeight < NUM_HEIGHTS - 1) {//if you press the lift up button and the lift isn't at its max height
      goalHeight++; //set the height of the lift to the next higher height
      lift.setTarget(heights[goalHeight]); //move the lift to the set height
    } else if (liftDownButton.changedToPressed() && goalHeight > 0) {//if you press the lift down button and the lift isn't at its min height
      goalHeight--; //set the height of the lift to the next lower height
      lift.setTarget(heights[goalHeight]); //move the lift to the set height
    }
  }
}


void opcontrol() { //This runs immediatly after the initialization
  pros::Task driveControlTask (driveControl, NULL, TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, ""); //starts the drive control task
  pros::Task liftControlTask (liftControl, NULL, TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, ""); //starts the lift control task
}
