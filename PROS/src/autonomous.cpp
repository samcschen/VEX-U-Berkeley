#include "declareStuff.hpp"

/*
This is the autonomous section of the program. Write your autonomous task here.
*/

 void redFrontAuton1(){

 }

 void redFrontAuton2(){

 }

 void redBackAuton1(){

 }

 void redBackAuton2(){

 }

 void blueFrontAuton1(){

 }

 void blueFrontAuton2(){

 }

 void blueBackAuton1(){

 }

 void blueBackAuton2(){
   //This generates a path between the points given. You can have more than 2 points. Format is {y distance, x distance, angle}.
   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{3.5_ft, 0_ft, 0_deg}}, "A");
   //You have to set the target in order for the robot to actually move.
   driveController.setTarget("A");
   //The code continues to run after setting a target, so you must call waitUntilSettled in order to prevent the code from continuing.
   driveController.waitUntilSettled();
   //You can also control the drive directly by running functions such as turnAngle or moveDistance. These functions do wait until completion.
   drive.turnAngle(180_deg);
   drive.moveDistance(1_ft);
   drive.moveDistance(-5_in);
 }

 void autonomous() { //when autonomous starts this runs
   blueBackAuton2(); //run the second blue back auton
 }
