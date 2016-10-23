#pragma once
#include "../SlothRobot.h"
#include "GenericController.h"
#include <WPILib.h>
#include <iostream>

class OperatorController : public GenericController
{
private:
    Joystick wheel; //!< Reference to wheel for getting steering input.
    Joystick throttle; //!< Reference to throttle for controlling speed.
    Joystick op; //!< Reference to intake joysyick for raising/lowering the speed and picking up balls.
public:
    OperatorController();
    void handle(SlothRobot* bot);
    void start();
};