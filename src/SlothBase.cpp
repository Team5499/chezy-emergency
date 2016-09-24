#include "SlothBase.h"

SlothBase::SlothBase()
    :
    bot(),
    operatorController(),
    autoTimer()
{
    std::cout << "Constructed a SlothBase!" << std::endl;
}

void SlothBase::AutonomousInit()
{
    autoTimer.Reset();
}

void SlothBase::AutonomousPeriodic()
{
    if(autoTimer.Get() < 5)
    {
        bot.drivetrain.Shift(Drivetrain::ShiftState::LOW);
        bot.drivetrain.DriveLR(0.6, 0.6);
    }
}

void SlothBase::TeleopPeriodic()
{
    operatorController.handle(&bot);
}

START_ROBOT_CLASS(SlothBase)