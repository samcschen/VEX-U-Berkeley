#include "main.h"
#include "wiring.h"

//Controls the two flapping spinning boys at the front of the robot
void control_intake() {
	if (btnSuck.isPressed()) {
		left_intake.moveVelocity(200);
		right_intake.moveVelocity(200);
	} else if (btnSpit.isPressed()) {
		left_intake.moveVelocity(-200);
		right_intake.moveVelocity(-200);
	} else {
		left_intake.moveVelocity(0);
		right_intake.moveVelocity(0);
	}
}
//Controls the arms letting them lift up and down. Should be a right and left Motor
void control_arm() {
	if (btnLift.isPressed()){
		left_lift.moveVelocity(100);
		right_lift.moveVelocity(100);
	} else if (btnDrop.isPressed()){
		left_lift.moveVelocity(-100);
		right_lift.moveVelocity(-100);
	} else {
		left_lift.moveVelocity(0);
		right_lift.moveVelocity(0);
	}
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
	left_lift.setBrakeMode(AbstractMotor::brakeMode::hold);
	right_lift.setBrakeMode(AbstractMotor::brakeMode::hold);
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

void intake_cube_autonomous(int num_cubes) {
	double prev_max_velocity = chassis->getMaxVelocity();
	chassis->setMaxVelocity(50);
	left_intake.moveVelocity(200);
	right_intake.moveVelocity(200);
	pros::delay(400);
	double distance = 0.5 + (num_cubes - 1) * 5.5;
	chassis->moveDistance(distance * 1_in);
	pros::delay(100);
	left_intake.moveVelocity(0);
	right_intake.moveVelocity(0);
	chassis->moveDistance(distance * -1_in);
	chassis->setMaxVelocity(prev_max_velocity);
}

void output_cube_autonomous() {
	left_intake.moveVelocity(-100);
	right_intake.moveVelocity(-100);
	pros::delay(700);
	left_intake.moveVelocity(0);
	right_intake.moveVelocity(0);
}
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
void autonomous() {
	int direction = 1;//1 is blue, -1 is red
	chassis->moveDistance(1_ft);
	output_cube_autonomous();
	chassis->moveDistance(-1_ft);
	chassis->moveDistance(1_ft);
	output_cube_autonomous();
	chassis->moveDistance(-1_ft);
	chassis->moveDistance(1_ft);
	output_cube_autonomous();
	chassis->moveDistance(-1_ft);
	/*chassis->setState({direction * 2.75_in, 7.25_in, 0_deg});
	chassis->setMaxVelocity(50);
	chassis->driveToPoint({direction * 2.75_in, 16.75_in});
	intake_cube_autonomous(1);
	chassis->driveToPoint({direction * 12_in, 26.75_in});
	chassis->driveToPoint({direction * 16.75_in, 26.75_in});
	intake_cube_autonomous(1);
	chassis->driveToPoint({direction * 36_in, 12_in});
	output_cube_autonomous();
	chassis->driveToPoint({direction * -55_in, 7_in});
	chassis->driveToPoint({direction * -55_in, 50.75_in});
	chassis->turnToAngle(direction * -90_deg);
	chassis->driveToPoint({direction * -66.5_in, 50.75_in});
	intake_cube_autonomous(1);
	chassis->driveToPoint({direction * -60_in, 60.96_in});
	chassis->driveToPoint({direction * -60_in, 12_in});
	chassis->driveToPoint({direction * 	-74_in, 12_in});*/
}

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
	chassis->setMaxVelocity(600);
	while (true) {
		chassis->getModel()->arcade(master.getAnalog(ControllerAnalog::leftY),
                           master.getAnalog(ControllerAnalog::rightX));
		control_arm();
		control_kicker();
		control_intake();
		pros::delay(10);
	}
}
