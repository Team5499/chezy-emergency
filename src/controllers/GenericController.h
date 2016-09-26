#pragma once
#include <WPILib.h>

class SlothRobot;

class GenericController
{   
public:
    virtual ~GenericController() {};
    virtual void handle(SlothRobot* bot) = 0;
    virtual void start() = 0;
};
