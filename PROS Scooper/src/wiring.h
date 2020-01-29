#include "main.h"
//lifter boi ports
#define LEFT_DRIVE_ONE_PORT 9
#define LEFT_DRIVE_TWO_PORT 17
#define RIGHT_DRIVE_ONE_PORT -10
#define RIGHT_DRIVE_TWO_PORT -18

#define LEFT_GRABBER_PORT 7
#define RIGHT_GRABBER_PORT -8

#define LEFT_LIFT_PORT -3
#define RIGHT_LIFT_PORT 4

auto chassis = ChassisControllerBuilder()
    .withMotors({LEFT_DRIVE_ONE_PORT, LEFT_DRIVE_TWO_PORT}, {RIGHT_DRIVE_ONE_PORT, RIGHT_DRIVE_TWO_PORT})
    .withDimensions(AbstractMotor::gearset::green, {{4_in, 11.9327809104_in}, imev5GreenTPR})
    .withOdometry()
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
