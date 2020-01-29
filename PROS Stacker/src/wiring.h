#include "main.h"
#define LEFT_DRIVE_ONE_PORT 9
#define LEFT_DRIVE_TWO_PORT 17
#define RIGHT_DRIVE_ONE_PORT -10
#define RIGHT_DRIVE_TWO_PORT -18

#define LEFT_INTAKE_PORT 7
#define RIGHT_INTAKE_PORT -8

auto chassis = ChassisControllerBuilder()
    .withMotors({LEFT_DRIVE_ONE_PORT, LEFT_DRIVE_TWO_PORT}, {RIGHT_DRIVE_ONE_PORT, RIGHT_DRIVE_TWO_PORT})
    .withDimensions(AbstractMotor::gearset::green, {{4_in, 11.9327809104_in}, imev5GreenTPR})
    .withOdometry()
    .buildOdometry();

ControllerButton btnSuck(ControllerDigital::A);
ControllerButton btnSpit(ControllerDigital::B);
Motor left_intake(LEFT_INTAKE_PORT);
Motor right_intake(RIGHT_INTAKE_PORT);
Controller master;
