#pragma once
#include <WPILib.h>
#include "subsystems/Drivetrain.h"
#include <iostream>

class SlothRobot
{
private:
public:
    SlothRobot();
    Drivetrain drivetrain;
    Compressor compressor;
};
