#include "main.h"
#define LEFT_DRIVE_ONE_PORT 9
#define LEFT_DRIVE_TWO_PORT 17
#define RIGHT_DRIVE_ONE_PORT 10
#define RIGHT_DRIVE_TWO_PORT 18

pros::Motor left_drive_one (LEFT_DRIVE_ONE_PORT, MOTOR_GEARSET_36);
pros::Motor left_drive_two (LEFT_DRIVE_TWO_PORT, MOTOR_GEARSET_36);
pros::Motor right_drive_one (RIGHT_DRIVE_ONE_PORT, MOTOR_GEARSET_36);
pros::Motor right_drive_two (RIGHT_DRIVE_TWO_PORT, MOTOR_GEARSET_36);
pros::Controller master(pros::E_CONTROLLER_MASTER);


/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");
}
void activate_motors(double angularPower, double linearPower){
    double rightPwm = linearPower;
    double leftPwm = linearPower;
    leftPwm -= angularPower;
    rightPwm += angularPower;
    if (leftPwm > 100){
        rightPwm -= leftPwm - 100;
        leftPwm = 100;
    }
    else if (rightPwm > 100){
        leftPwm -= rightPwm - 100;
        rightPwm = 100;
    }
    else if (leftPwm < -100){
        rightPwm += -100 - leftPwm;
        leftPwm = -100;
    }
    else if (rightPwm < -100){
        leftPwm += -100 - rightPwm;
        rightPwm = -100;
    }
    left_drive_one.move_velocity(leftPwm);
    left_drive_two.move_velocity(leftPwm);
    right_drive_one.move_velocity(rightPwm);
    right_drive_two.move_velocity(rightPwm);
}
void drive_normal(){
	double SENSITIVITY_CONSTANT = -0.35;
  double linearPower = master.get_analog(ANALOG_LEFT_Y);
  double angularPower = master.get_analog(ANALOG_RIGHT_X) * SENSITIVITY_CONSTANT;
  if (fabs(linearPower) < 10.0f) {
		linearPower = 0;
	}
	if (fabs(angularPower) < 1) {
		angularPower = 0;
	}
	activate_motors(angularPower, linearPower);
}
/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {

	while (true) {
		drive_normal();
		pros::delay(20);
	}
}
