#include "Drivetrain.h"

Drivetrain::Drivetrain()
    :
    driveLeft1(6),
    driveLeft2(7),
    driveRight1(4),
    driveRight2(5),
    shiftLeft(0, 1),
    shiftRight(2, 3)
{
}

void Drivetrain::DriveLR(double left, double right)
{
    driveLeft1.Set(left);
    driveLeft2.Set(left);
    driveRight1.Set(right);
    driveRight2.Set(right);
}

void Drivetrain::Shift(ShiftState state)
{
    switch(state)
    {
        case ShiftState::HIGH:
        shiftLeft.Set(DoubleSolenoid::Value::kForward);
        shiftRight.Set(DoubleSolenoid::Value::kForward);
        break;
        case ShiftState::LOW:
        shiftLeft.Set(DoubleSolenoid::Value::kReverse);
        shiftRight.Set(DoubleSolenoid::Value::kReverse);
        break;
    }
}