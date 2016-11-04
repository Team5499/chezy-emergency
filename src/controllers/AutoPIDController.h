#pragma once
#include "../SlothRobot.h"
#include "GenericController.h"
#include <WPILib.h>
#include "../ManualPID.h"

class AutoPIDController : public GenericController
{
private:

    // Timer for first step:
    Timer autoTimer;
    // Sensors
    ADXRS450_Gyro gyro; //!< Central gyroscope.
    Encoder lEncoder; //!< Encoder on left wheel.
    Encoder rEncoder; //!< Encoder on right wheel.
    TwoEncoders distance;

    // PID Constants
    const float kPa; //!< Proportional constant for angle.
    const float kIa; //!< Integral constant for angle.
    const float kDa; //!< Derivative constant for angle.
    const float kEa; //!< Acceptable absolute error to consider a turn complete.
    
    const float kPd; //!< Proportional constant for distance.
    const float kId; //!< Integral constant for distance.
    const float kDd; //!< Derivative constant for distance.
    const float kEd; //!< Acceptable absolute error to consider a distance drive complete.

    int step; //!< Current step of routine.

public:

    // Routine measurements
    float stepZeroDistance; //!< Distance (in inches?) of initial drive step.
    float stepOneAngle; //!< Angle (in degrees) to turn towards goal.
    float stepTwoDistance; //!< Distance (in inches?) from turning point to goal-shooting point.

    ManualPIDOut speedOut; //!< Interface for recieving Manual Output from distance PID.
    ManualPIDOut angleOut; //!< Interface for receieving Manual Output from angle PID.

    // PID Controllers
    PIDController aController; //!< PIDController for angle.
    PIDController dController; //!< PIDController for distance.

    AutoPIDController();
    void handle(SlothRobot* bot);
    void start();

};