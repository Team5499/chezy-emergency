#include "OperatorController.h"

OperatorController::OperatorController()
    :
    wheel(0),
    throttle(1),
    op(2)
{
}

void OperatorController::handle(SlothRobot* bot)
{
    /* Throttle / wheel control */
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
    bot->drivetrain.DriveLR(throttle_value + wheel_value,
                            throttle_value - wheel_value);

    /* Shifting */
    if(throttle.GetRawButton(4))
    {
        bot->drivetrain.Shift(Drivetrain::ShiftState::HIGH);
    }
    else
    {
        bot->drivetrain.Shift(Drivetrain::ShiftState::LOW);
    }

    /* Intake */
    bot->intake.SetArm(op.GetRawAxis(1));
    if(op.GetRawButton(4))
    {
        bot->intake.SetRoller(1);
    }
    else if(op.GetRawButton(3))
    {
        bot->intake.SetRoller(-1);
    }
    else
    {
        bot->intake.SetRoller(0);
    }

    
}
