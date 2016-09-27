#pragma once
#include "../SlothRobot.h"
#include "GenericController.h"
#include <WPILib.h>

class AutoController : public GenericController
{
private:
    Timer autoTimer; //!< Timer to keep track of when to turn/shoot/whatever.
public:
    AutoController();
    void handle(SlothRobot* bot);
    void start();
};