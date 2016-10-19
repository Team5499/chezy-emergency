#pragma once
#include "../SlothRobot.h"
#include "GenericController.h"
#include <WPILib.h>

class AutoController : public GenericController
{
private:
    Timer autoTimer; //!< Timer to keep track of when to turn/shoot/whatever.

    bool finished;
    double routine[5][1+4]; //!< 2D Array to store the routine. 1+4 rows because 4 outputs and 1 timestamp.
    int nextStep; //!< The next step to execute.
    int nextStepTime; //!< Time to execute next step. Stored in this variable for optimization.

    double left; //!< Speed of left wheels for the current step.
    double right; //!< Speed of right wheels for the current step.
    double arm; //!< Speed of intake arm pivot for the current step.
    double roller; //!< Speed of intake roller for the current step.

public:
    AutoController();
    void resetRoutine();
    void handle(SlothRobot* bot);
    void start();
};