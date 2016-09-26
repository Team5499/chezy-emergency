#include "AutoController.h"

AutoController::AutoController()
    :
    autoTimer()
{
}

void AutoController::handle(SlothRobot* bot)
{
    //double time = autoTimer.Get();
    bot->drivetrain.Shift(Drivetrain::ShiftState::LOW);
    
}

void AutoController::start() 
{
    autoTimer.Start();
}
