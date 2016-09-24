#pragma once
#include <WPILib.h>
#include "SlothRobot.h"
#include "controllers/OperatorController.h"
#include <iostream>

class SlothBase : public IterativeRobot
{
private:
    SlothRobot bot;
    OperatorController operatorController;
public:
    SlothBase();
    /*
    void DisabledInit() override;
    void AutonomousInit() override;
    void TeleopInit() override;
    void DisabledPeriodic() override;
    void AutonomousPeriodic() override;
    */
    void TeleopPeriodic() override;
};
