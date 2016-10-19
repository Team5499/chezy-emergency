#include "Intake.h"

//! Intake constructor.

//! This initializes the hardware references for our pivot arm and grabber-roller.
Intake::Intake()
    :
    arm(10),
    roller(11)
{
}
//! Set the turn speed of the pivot arm.
/**
* @param value the speed of the motor.
* @todo setup PID to control angle.
*/
void Intake::SetArm(double value)
{
    arm.Set(value);
}
//! Set the speed of the Roller.
/** 
* @param value the speed of the roller.
* Note that we do NOT need PID for this, as it turns continuously.
*/
void Intake::SetRoller(double value)
{
    roller.Set(value);
}