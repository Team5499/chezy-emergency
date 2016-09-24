#include "SlothRobot.h"

SlothRobot::SlothRobot()
    :
    drivetrain(),
    intake(),
    shooter(),
    compressor()
{
    std::cout << "Constructed a SlothRobot!" << std::endl;
}