#pragma once
#include "../SlothRobot.h"
#include "GenericController.h"
#include <WPILib.h>

class AutoController : public GenericController
{
private:
    Timer autoTimer;
public:
    AutoController();
    void handle(SlothRobot* bot);
    void start();
};