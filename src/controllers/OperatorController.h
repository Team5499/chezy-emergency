#pragma once
#include "../SlothRobot.h"
#include "GenericController.h"
#include <WPILib.h>

class OperatorController : public GenericController
{
private:
    Joystick wheel;
    Joystick throttle;
    Joystick op;
public:
    OperatorController();
    void handle(SlothRobot* bot);
    void start;
};