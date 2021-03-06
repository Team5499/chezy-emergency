#pragma once
#include <WPILib.h>
#include "SlothRobot.h"
#include "controllers/OperatorController.h"
#include "controllers/AutoPIDController.h"
#include <iostream>

class SlothBase : public IterativeRobot
{
private:
    SlothRobot bot;
    OperatorController operatorController;
    AutoPIDController autoController;
    
public:
    SlothBase();
    //void DisabledInit() override;
    //void DisabledPeriodic() override;
    
    void TeleopInit() override;
    void TeleopPeriodic() override;
    
    void AutonomousInit() override;
    void AutonomousPeriodic() override;

    void TestInit() override;
    void TestPeriodic() override;
    
};
