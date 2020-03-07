#include "main.h"
#include "wiring.h"

//Controls the two flapping spinning boys at the front of the robot
void control_intake() {
	if (btnBoth.isPressed()) {
		left_intake.moveVelocity(300);
		right_intake.moveVelocity(300);
		left_indexer.moveVelocity(200);
		right_indexer.moveVelocity(200);
		return;
	}
	if (btnSuck.isPressed()) {
		left_intake.moveVelocity(300);
		right_intake.moveVelocity(300);
	} else {
		left_intake.moveVelocity(0);
		right_intake.moveVelocity(0);
	}
	if (btnIndex.isPressed()) {
		left_indexer.moveVelocity(200);
		right_indexer.moveVelocity(200);
	} else {
		left_indexer.moveVelocity(0);
		right_indexer.moveVelocity(0);
	}
}
void place_tower() {
	if (btnSpit.isPressed()) {
		chassis->getModel()->forward(-.01);
		left_intake.moveVelocity(-20);
		right_intake.moveVelocity(-20);
		left_indexer.moveVelocity(-30);
		right_indexer.moveVelocity(-30);
	}
}
//Controls the ramp letting them lift up and down
void control_ramp() {
	if (btnLift.isPressed()){
		lift.moveVelocity(30);
	} else if (btnDrop.isPressed()){
		lift.moveVelocity(-30);
	} else {
		lift.moveVelocity(0);
	}
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
	lift.setBrakeMode(AbstractMotor::brakeMode::hold);
	lift.setEncoderUnits(AbstractMotor::encoderUnits::rotations);
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

void forward_intake() {
	left_intake.moveVelocity(200);
	right_intake.moveVelocity(200);
	left_indexer.moveVelocity(200);
	right_indexer.moveVelocity(200);
}

void disable_intake() {
	left_intake.moveVelocity(0);
	right_intake.moveVelocity(0);
	left_indexer.moveVelocity(0);
	right_indexer.moveVelocity(0);
}
void initialize_ramp() {
	lift.moveRelative(.1, 30);
}
void lift_ramp() {
	lift.moveRelative(1.7, 30);
}
void lower_ramp() {
	lift.moveRelative(-1.6, 10);
}
void score_stack() {
	chassis->getModel()->forward(-.03);
	left_intake.moveVelocity(-20);
	right_intake.moveVelocity(-20);
	left_indexer.moveVelocity(-30);
	right_indexer.moveVelocity(-30);
	pros::delay(5000);
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
	int team = 1;//1 is red, -1 is blue
	chassis->setMaxVelocity(50);
	chassis->setState({team * -2.75_in, 7.5_in, 0_deg});
	forward_intake();
	chassis->driveToPoint({team * -2.75_in, 26.75_in});
	chassis->driveToPoint({team * -24_in, 26.75_in});
	chassis->driveToPoint({team * -24_in, 26.75_in});
	chassis->driveToPoint({team * 17.375_in, 26.75_in});
	chassis->moveDistance(-7_in);

	chassis->setState({team * 10.375_in, 26.75_in, 90_deg});
	chassis->driveToPoint({team * -20_in, 26.75_in});
	chassis->driveToPoint({team * -20_in, 50.75_in});
	chassis->driveToPoint({team * -12_in, 50.75_in});
	chassis->driveToPoint({team * -12_in, 65.375_in});
	chassis->moveDistance(team * -5_in);
	chassis->setState({team * -12_in, 65.375_in, 0_deg});
	chassis->driveToPoint({team * -24_in, 12_in});
	chassis->driveToPoint({team * -24_in, 12_in});
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
		control_ramp();
		control_intake();
		place_tower();
		chassis->getModel()->arcade(master.getAnalog(ControllerAnalog::leftY),
	            master.getAnalog(ControllerAnalog::rightX));
		pros::delay(10);
	}
}
