#include "main.h"
//lifter boi ports
#define LEFT_DRIVE_ONE_PORT 8
#define LEFT_DRIVE_TWO_PORT 12
#define RIGHT_DRIVE_ONE_PORT -9
#define RIGHT_DRIVE_TWO_PORT -13

#define LEFT_GRABBER_PORT -1
#define RIGHT_GRABBER_PORT 7

#define LEFT_LIFT_PORT -6
#define RIGHT_LIFT_PORT 4

auto chassis = ChassisControllerBuilder()
    .withMotors({LEFT_DRIVE_TWO_PORT, LEFT_DRIVE_ONE_PORT}, {RIGHT_DRIVE_TWO_PORT, RIGHT_DRIVE_ONE_PORT})
    .withDimensions(AbstractMotor::gearset::green, {{4_in, 11.9327809104_in}, imev5GreenTPR})
    .withOdometry(StateMode::CARTESIAN)
    .buildOdometry();

//intake boi buttons/motors
ControllerButton btnGrab(ControllerDigital::A);
ControllerButton btnRelease(ControllerDigital::B);
ControllerButton btnLift(ControllerDigital::up);
ControllerButton btnDrop(ControllerDigital::down);
Motor left_gripper(LEFT_GRABBER_PORT);
Motor right_gripper(RIGHT_GRABBER_PORT);
Motor left_lift(LEFT_LIFT_PORT);
Motor right_lift(RIGHT_LIFT_PORT);
Controller master;
