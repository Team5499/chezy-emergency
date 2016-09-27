#include "AutoController.h"

//! Constructor to initialize the timer.
AutoController::AutoController()
    :
    autoTimer() 
{
}
//! Autonomously handle the robot.

/**
* Using a timer and precise numbers, run autonomous mode.
* Current autonomous plan is to put the shooter down,
* Go under the low bar, turn, and push a ball into the low goal.
* @param bot The Robot to control.
* @todo run experiments to determine how exact timings for autonomous.
*/
void AutoController::handle(SlothRobot* bot)
{
    //double time = autoTimer.Get();
    // Start in low gear
    bot->drivetrain.Shift(Drivetrain::ShiftState::LOW);
    
}
//! Start timing.

//! This will be called at AutonomousInit(), so that we can keep track of what we have to do.
void AutoController::start() 
{
    autoTimer.Start();
}
