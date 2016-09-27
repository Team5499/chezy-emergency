#pragma once
#include <WPILib.h>
#include "../SlothRobot.h"

class GenericController
{   
public:

    virtual ~GenericController() {}; //!< Initialize the controller.
    //! Handle the controls of a robot.
    /**
    * Given a pointer to a robot, handle the subsystems of the robot based on arbitrary rules.
    * For example, a controller might take joystick input, or it might autonomously control the robot.
    * @param bot The robot to be controlled.
    */
    virtual void handle(SlothRobot* bot) = 0;
    //! Prepare the controller to handle the robot.
    /**
    * This function will be called once, right before the handling loop begins.
    */
    virtual void start() = 0; 
};
