#include "Intake.h"

Intake::Intake()
    :
    arm(10),
    roller(9)
{
}

void Intake::SetArm(double value)
{
    arm.Set(value);
}

void Intake::SetRoller(double value)
{
    roller.Set(value);
}