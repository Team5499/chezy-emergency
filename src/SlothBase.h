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
    AutoController autoController;
    
public:
    SlothBase();
    //void DisabledInit() override;
    //void DisabledPeriodic() override;
    
    void TeleopInit() override;
    void TeleopPeriodic() override;
    
    void AutonomousInit() override;
    void AutonomousPeriodic() override;
    
};
