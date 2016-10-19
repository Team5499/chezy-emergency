#include "SlothBase.h"

SlothBase::SlothBase()
    :
    bot(),
    operatorController(),
    autoController()
{
    std::cout << "Constructed a SlothBase!" << std::endl;
}

// Autonomous Methods
void SlothBase::AutonomousInit()
{
    autoController.resetRoutine();
    autoController.start();
}
void SlothBase::AutonomousPeriodic()
{
    autoController.handle(&bot);
}
// Teleop Methods
void SlothBase::TeleopInit()
{
    operatorController.start();
}
void SlothBase::TeleopPeriodic()
{
    operatorController.handle(&bot);
}
// Test Methods
void SlothBase::TestInit()
{
    
}
void SlothBase::TestPeriodic()
{

}
START_ROBOT_CLASS(SlothBase)
