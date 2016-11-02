#include "Intake.h"

//! Intake constructor.

//! This initializes the hardware references for our pivot arm and grabber-roller.
Intake::Intake()
    :
    arm(10),
    roller(11)
{
    std::cout << "Intake initialized!" << std::endl;
}
//! Set the turn speed of the pivot arm.
/**
* @param value the speed of the motor.
*/
void Intake::SetArm(double value)
{
    arm.Set(value);
}
//! Set the speed of the Roller.
/** 
* @param value the speed of the roller.
*/
void Intake::SetRoller(double value)
{
    roller.Set(value);
}