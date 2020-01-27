#include "main.h"
#define LEFT_DRIVE_ONE_PORT 9
#define LEFT_DRIVE_TWO_PORT 17
#define RIGHT_DRIVE_ONE_PORT -10
#define RIGHT_DRIVE_TWO_PORT -18


auto chassis = ChassisControllerBuilder()
    .withMotors({LEFT_DRIVE_ONE_PORT, LEFT_DRIVE_TWO_PORT}, {RIGHT_DRIVE_ONE_PORT, RIGHT_DRIVE_TWO_PORT})
    .withDimensions(AbstractMotor::gearset::green, {{4_in, 11.9327809104_in}, imev5GreenTPR})
    .withOdometry()
    .buildOdometry();

Controller master;
