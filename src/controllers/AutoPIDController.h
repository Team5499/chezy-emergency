#pragma once
#include "../SlothRobot.h"
#include "GenericController.h"
#include <WPILib.h>
#include <iostream>

class AutoPIDController : public GenericController
{
private:

    // Sensors
    ADXRS450_Gyro gyro; //!< Central gyroscope.
    Encoder lEncoder; //!< Encoder on left wheel.
    Encoder rEncoder; //!< Encoder on right wheel.

    // PID Constants
    const float kPa; //!< Proportional constant for angle.
    const float kIa; //!< Integral constant for angle.
    const float kDa; //!< Derivative constant for angle.
    
    const float kPd; //!< Proportional constant for distance.
    const float kId; //!< Integral constant for distance.
    const float kDd; //!< Derivative constant for distance.

    const float kPw; //!< Proportional constant for wheel correction.
    const float kIw; //!< Integral constant for wheel correction.
    const float kDw; //!< Derivative constant for wheel correction.
    
    // PID Controllers
    PIDController aController; //!< PIDController for angle.
    PIDController dController; //!< PIDController for distance.
    PIDController wlController; //!< PIDController for left wheel.
    PIDController wrController; //!< PIDController for right wheel.

public:

    // Routine measurements
    float stepZeroDistance; //!< Distance (in inches?) of initial drive step.
    float stepOneAngle; //!< Angle (in degrees) to turn towards goal.
    float stepTwoDistance; //!< Distance (in inches?) from turning point to goal-shooting point.

    AutoPIDController();
    void handle(SlothRobot* bot);
    void start();
};