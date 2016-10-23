#include "Drivetrain.h"

//! Drivetrain constructor.

//! This initializes the hardware references for our wheels and shifting.
Drivetrain::Drivetrain()
    :
    driveLeft1(1),
    driveLeft2(2),
    driveRight1(3),
    driveRight2(4),
    shiftLeft(4, 5),
    shiftRight(6, 7),
    currentState(ShiftState::LOW)
    
{
    std::cout << "Drivetrain initialized!" << std::endl;
}

//! Set the motors for the right and left wheels.
/**
* @param left wheel speed for the left motor.
* @param right wheel speed for the right motor.
*/
void Drivetrain::DriveLR(double left, double right)
{
    driveLeft1.Set(-1 * left);
    driveLeft2.Set(-1 * left);
    driveRight1.Set(right);
    driveRight2.Set(right);
}

//! Shift the drivetrain to HIGH or LOW.
/**
* @param state the mode to shift to.
*/
void Drivetrain::Shift(ShiftState state)
{
    // Only log when we change shift state
    std::string newState = state==ShiftState::HIGH ? "HIGH" : "LOW";
    if (state != currentState) {
        std::cout << "Shifting into " << newState  << std::endl;
    }
    currentState = state;

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