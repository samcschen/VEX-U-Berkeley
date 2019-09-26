#ifndef headerTest
#define headerTest
#include "main.h"

extern Motor FrontRightM;
extern Motor FrontLeftM;
extern Motor BackRightM;
extern Motor BackLeftM;
extern Motor LiftM1;
extern Motor LiftM2;

extern Controller MasterC;

extern ControllerButton liftUpButton;
extern ControllerButton liftDownButton;

extern AsyncPosIntegratedController lift;
extern ChassisControllerIntegrated drive;

extern MotorGroup LiftG;

extern AsyncMotionProfileController driveController;

extern const int NUM_HEIGHTS;
extern const int height1;
extern const int height2;
extern const int height3;
extern const int height4;

extern const int heights[];

extern int goalHeight;

float velocityToVoltage(int velocity);
void wait(int ms);
void testFlywheel();
#endif
