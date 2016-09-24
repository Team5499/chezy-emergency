#include "OperatorController.h"

OperatorController::OperatorController()
    :
    wheel(0),
    throttle(1)
{
}

void OperatorController::handle(SlothRobot* bot)
{
    double throttle_value = throttle.GetRawAxis(1);
    double wheel_value = wheel.GetRawAxis(0);
    if(throttle_value > -0.05 && throttle_value < 0.05)
    {
        throttle_value = 0;
    }
    if(wheel_value > -0.05 && wheel_value < 0.05)
    {
        wheel_value = 0;
    }
    if(throttle_value < 0)
    {
        wheel_value *= -1;
    }
    bot->drivetrain.DriveLR(throttle_value + wheel_value,
                            throttle_value - wheel_value);

    if(throttle.GetRawButton(4))
    {
        bot->drivetrain.Shift(Drivetrain::ShiftState::HIGH);
    }
    else
    {
        bot->drivetrain.Shift(Drivetrain::ShiftState::LOW);
    }
}