#include "SlothBase.h"

SlothBase::SlothBase()
    :
    bot(),
    operatorController()
{
    std::cout << "Constructed a SlothBase!" << std::endl;
}

void SlothBase::TeleopPeriodic()
{
    operatorController.handle(&bot);
}

START_ROBOT_CLASS(SlothBase)