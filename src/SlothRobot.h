#pragma once
#include <WPILib.h>
#include "subsystems/Drivetrain.h"
#include "subsystems/Intake.h"
#include <iostream>

class SlothRobot
{
private:
public:
    SlothRobot();
    //! List subsystems
    Drivetrain drivetrain;
    Intake intake;
    Compressor compressor;

};
