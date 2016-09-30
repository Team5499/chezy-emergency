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
    
    Drivetrain drivetrain; //!< Drivetrain subsystem.
    Intake intake; //!< Intake subsystem.
    Compressor compressor;

};
