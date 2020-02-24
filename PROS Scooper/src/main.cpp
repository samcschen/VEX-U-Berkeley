#include "main.h"
#include "wiring.h"

//Controls the gripper mechanism. TBD
void control_gripper() {
		if (btnGrab.isPressed()) {
			left_gripper.moveVelocity(100);
			right_gripper.moveVelocity(100);
		} else if (btnRelease.isPressed()) {
			left_gripper.moveVelocity(-100);
			right_gripper.moveVelocity(-100);
		} else {
			left_gripper.moveVelocity(0);
			right_gripper.moveVelocity(0);
		}
}
//Controls the arms letting them lift up and down. Should be a right and left Motor
void control_arm() {
	if (btnLift.isPressed()){
		left_lift.moveVelocity(100);
		right_lift.moveVelocity(100);
	} else if (btnDrop.isPressed()){
		left_lift.moveVelocity(-40);
		right_lift.moveVelocity(-40);
	} else {
		left_lift.moveVelocity(0);
		right_lift.moveVelocity(0);
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
	left_gripper.setBrakeMode(AbstractMotor::brakeMode::hold);
	right_gripper.setBrakeMode(AbstractMotor::brakeMode::hold);
	left_lift.setBrakeMode(AbstractMotor::brakeMode::hold);
	right_lift.setBrakeMode(AbstractMotor::brakeMode::hold);
	left_lift.setEncoderUnits(AbstractMotor::encoderUnits::rotations);
	right_lift.setEncoderUnits(AbstractMotor::encoderUnits::rotations);
	left_gripper.setBrakeMode(AbstractMotor::brakeMode::hold);
	right_gripper.setBrakeMode(AbstractMotor::brakeMode::hold);
	left_gripper.setEncoderUnits(AbstractMotor::encoderUnits::rotations);
	right_gripper.setEncoderUnits(AbstractMotor::encoderUnits::rotations);
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
void lift_arm() {
	left_lift.moveRelative(3.5,100);
	right_lift.moveRelative(3.5,100);
	pros::delay(4000);
}
void lower_arm() {
 left_lift.moveRelative(-3.5,70);
 right_lift.moveRelative(-3.5,70);
}
void close_grabber() {
	left_gripper.moveRelative(-4, 70);
	right_gripper.moveRelative(-4, 70);
}
void open_grabber() {
	left_gripper.moveRelative(4, 70);
	right_gripper.moveRelative(4, 70);
}
void autonomous() {
	int direction = 1; //1 is blue, -1 is red
	close_grabber();
	/*chassis->moveDistance(-1_ft);
	chassis->moveDistance(1_ft);
	chassis->moveDistance(-1_ft);
	chassis->moveDistance(1_ft);
	chassis->moveDistance(-1_ft);*/
	/*chassis->setState({direction * -16.75_in, 7.25_in, 0_deg});
	chassis->setMaxVelocity(50);
	close_grabber();
	chassis->driveToPoint({direction * -16.75_in, 37_in});
	chassis->driveToPoint({direction * 0_in, 37_in});
	chassis->turnToAngle(direction * 180_deg);
	lift_arm();
	chassis->driveToPoint({direction * 0_in, 35_in});
	open_grabber();
	chassis->driveToPoint({direction * 0_in, 37_in});
	lower_arm();//Goal is to get a single cube*/
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
	while (true) {
		chassis->getModel()->arcade(master.getAnalog(ControllerAnalog::leftY),
		                            master.getAnalog(ControllerAnalog::rightX));

		control_arm();
		control_gripper();
		pros::delay(10);
	}
}
