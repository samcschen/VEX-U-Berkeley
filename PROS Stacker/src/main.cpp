#include "main.h"
#include "wiring.h"

//Controls the two flapping spinning boys at the front of the robot
void control_intake() {
	if (btnSuck.isPressed()) {
		left_intake.moveVelocity(300);
		right_intake.moveVelocity(300);
	} else if (btnSpit.isPressed()) {
		left_intake.moveVelocity(-300);
		right_intake.moveVelocity(-300);
	} else {
		left_intake.moveVelocity(0);
		right_intake.moveVelocity(0);
	}
}
//Controls the arms letting them lift up and down. Should be a right and left Motor
void control_arm() {

}
//Controls the mechanism that allows standing the backplate vertical. One Motor
void control_kicker() {

}
/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");
	left_intake.setBrakeMode(AbstractMotor::brakeMode::hold);
	right_intake.setBrakeMode(AbstractMotor::brakeMode::hold);
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
		chassis->getModel()->arcade(master.getAnalog(ControllerAnalog::leftY),
		                            master.getAnalog(ControllerAnalog::rightX));
    control_intake();
		pros::delay(10);
	}
}
