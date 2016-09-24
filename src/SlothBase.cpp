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
    bot.intake.SetArm(0.5);
    
}

void SlothBase::AutonomousPeriodic()
{
    double time = autoTimer.Get();
    if(time>2) {
         if (time < 2.1) {
            bot.intakke.SetArm(0);
        }
        else if (time < 7) {
            bot.drivetrain.Shift(Drivetrain::ShiftState::LOW);
            bot.drivetrain.DriveLR(0.6, 0.6);
        }
        else if (time < 12) {
            bot.drivetrain.Shift(Drivetrain::ShiftState::LOW);
            bot.drivetrain.DriveLR(-0.6, -0.6);
        }
        else {
            bot.drivetrain.DriveLR(0, 0);
        }

    }
}

void SlothBase::TeleopPeriodic()
{
    operatorController.handle(&bot);
}

START_ROBOT_CLASS(SlothBase)