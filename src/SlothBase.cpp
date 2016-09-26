#include "SlothBase.h"

SlothBase::SlothBase()
    :
    bot(),
    operatorController(),
    autoController()
{
    std::cout << "Constructed a SlothBase!" << std::endl;
}

void SlothBase::AutonomousInit()
{
    autoController.start();
}

void SlothBase::AutonomousPeriodic()
{
    autoController.handle(&bot);
}
void SlothBase::TeleopInit()
{
    OperatorController.start();
}

void SlothBase::TeleopPeriodic()
{
    operatorController.handle(&bot);
}

START_ROBOT_CLASS(SlothBase)
