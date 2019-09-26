#include "declareStuff.hpp"

/*
This is the initialization file for your program. You will want to put anything that you want to be done before the
driver control and autonomous peroids. This is also a good place to define all of you motors, sensors, controllers,
and variables. :)
*/

Motor FrontRightM(1, true, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees); //(port, reversed, gearset, encoderUnits)
Motor FrontLeftM(2,  false, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees);
Motor BackRightM(3,  true, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees);
Motor BackLeftM(4,  false, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees);
Motor LiftM1(5,  true, AbstractMotor::gearset::red, AbstractMotor::encoderUnits::degrees);
Motor LiftM2(6,  false, AbstractMotor::gearset::red, AbstractMotor::encoderUnits::degrees);

Controller MasterC; //The name of your controller

ControllerButton liftUpButton(ControllerDigital::R1); //define buttons here
ControllerButton liftDownButton(ControllerDigital::R2);

ChassisControllerIntegrated drive = ChassisControllerFactory::create( //create a chassis that contains your drive motors
  {FrontLeftM, BackLeftM}, {FrontRightM, BackRightM}, //{Left motors}, {Right motors}
  AbstractMotor::gearset::green, //gearset
  {4.15_in, 14.5_in} //{wheel diameter, distance between wheels}
);

MotorGroup LiftG({LiftM1,LiftM2}); //groups the two flywheel motors together so we can control them at the same time

AsyncPosIntegratedController lift = AsyncControllerFactory::posIntegrated(LiftG); //creates a controller for the lift

AsyncMotionProfileController driveController = AsyncControllerFactory::motionProfile(0.75, 1.0, 5.0, drive); //creates a 2D motion profile controller


void initialize() {

}

void disabled() {

}

void competition_initialize() {

}
