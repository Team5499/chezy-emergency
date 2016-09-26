#include "GenericController.h"

AutoController::AutoController()
    :
    autoTimer()
{
}

void AutoController::handle(SlothRobot* bot)
{
    double time = autoTimer.Get();
}

void AutoController::start() 
{
    autoTimer.Start();
}
