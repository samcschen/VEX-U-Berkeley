#include "main.h"
//intake boi ports
#define LEFT_DRIVE_ONE_PORT 9
#define LEFT_DRIVE_TWO_PORT 17
#define RIGHT_DRIVE_ONE_PORT -10
#define RIGHT_DRIVE_TWO_PORT -18

#define LEFT_INTAKE_PORT 7
#define RIGHT_INTAKE_PORT -8

#define LEFT_LIFT_PORT -3
#define RIGHT_LIFT_PORT 4

#define KICKER_PORT 19

auto chassis = ChassisControllerBuilder()
    .withMotors({LEFT_DRIVE_ONE_PORT, LEFT_DRIVE_TWO_PORT}, {RIGHT_DRIVE_ONE_PORT, RIGHT_DRIVE_TWO_PORT})
    .withDimensions(AbstractMotor::gearset::green, {{4_in, 11.9327809104_in}, imev5GreenTPR})
    .withOdometry()
    .buildOdometry();

//intake boi buttons/motors
ControllerButton btnSuck(ControllerDigital::A);
ControllerButton btnSpit(ControllerDigital::B);
ControllerButton btnLift(ControllerDigital::up);
ControllerButton btnDrop(ControllerDigital::down);
ControllerButton btnKick(ControllerDigital::X);
Motor left_intake(LEFT_INTAKE_PORT);
Motor right_intake(RIGHT_INTAKE_PORT);
Motor left_lift(LEFT_LIFT_PORT);
Motor right_lift(RIGHT_LIFT_PORT);
Controller master;
