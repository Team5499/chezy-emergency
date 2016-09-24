#include "SlothBase.h"

SlothBase::SlothBase()
    :
    bot(),
    operatorController()
{
    std::cout << "Constructed a SlothBase!" << std::endl;
}

void SlothBase::AutonomousPeriodic()
{
    bot.drivetrain.Shift(Drivetrain::ShiftState::LOW);
    bot.drivetrain.DriveLR(0.6, 0.6);
}

void SlothBase::TeleopPeriodic()
{
    operatorController.handle(&bot);
}

START_ROBOT_CLASS(SlothBase)