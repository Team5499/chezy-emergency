#include "OperatorController.h"

//! Initialize joysticks on driver station.
OperatorController::OperatorController()
    :
    wheel(0),
    throttle(1),
    op(2)
{
    std::cout << "Initialized Operator Controller." << std::endl;
}
//! Handle the robot based on Operator controls.
/**
* Poll the Operator station and update all subsystems from the Robot.
* @param bot The bot to be handled.
*/
void OperatorController::handle(SlothRobot* bot)
{
    /* Throttle / wheel control */
    double throttle_value = throttle.GetRawAxis(1); //!< Read throttle controls.
    double wheel_value = wheel.GetRawAxis(0); //!< Read 
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
    double intakearm = op.GetRawAxis(1);
    bot->intake.SetArm(intakearm/1.25);
    
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

//! Boilerplate.
void OperatorController::start()
{
    std::cout << "Starting Operator Control." << std::endl;
}