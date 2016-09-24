#pragma once
#include <WPILib.h>
#include "subsystems/Drivetrain.h"
#include "subsystems/Intake.h"
#include "subsystems/Shooter.h"
#include <iostream>

class SlothRobot
{
private:
public:
    SlothRobot();
    Drivetrain drivetrain;
    Intake intake;
    Shooter shooter;
    Compressor compressor;

};
