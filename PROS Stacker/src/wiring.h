#include "main.h"
//intake boi ports
#define LEFT_DRIVE_ONE_PORT 4
#define LEFT_DRIVE_TWO_PORT 19
#define RIGHT_DRIVE_ONE_PORT -11
#define RIGHT_DRIVE_TWO_PORT -18

#define LEFT_INTAKE_PORT 3
#define RIGHT_INTAKE_PORT -16

#define LEFT_INDEXER_PORT 6
#define RIGHT_INDEXER_PORT -8

#define LIFT_PORT 2

auto chassis = ChassisControllerBuilder()
    .withMotors({LEFT_DRIVE_ONE_PORT, LEFT_DRIVE_TWO_PORT}, {RIGHT_DRIVE_ONE_PORT, RIGHT_DRIVE_TWO_PORT})
    .withDimensions(AbstractMotor::gearset::green, {{4_in, 11.9327809104_in}, imev5GreenTPR})
    .withOdometry(StateMode::CARTESIAN)
    .buildOdometry();

//intake boi buttons/motors
ControllerButton btnSuck(ControllerDigital::R2);
ControllerButton btnIndex(ControllerDigital::R1);
ControllerButton btnBoth(ControllerDigital::A);
ControllerButton btnSpit(ControllerDigital::B);
ControllerButton btnLift(ControllerDigital::up);
ControllerButton btnDrop(ControllerDigital::down);
ControllerButton btnKick(ControllerDigital::X);
Motor left_intake(LEFT_INTAKE_PORT);
Motor right_intake(RIGHT_INTAKE_PORT);
Motor left_indexer(LEFT_INDEXER_PORT);
Motor right_indexer(RIGHT_INDEXER_PORT);
Motor lift(LIFT_PORT);
Controller master;
