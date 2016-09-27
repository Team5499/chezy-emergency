#include "SlothRobot.h"

SlothRobot::SlothRobot()
    // Initialize subsystems
    :
    drivetrain(),
    intake(),
    compressor()
{
    std::cout << "Constructed a SlothRobot!" << std::endl;
}