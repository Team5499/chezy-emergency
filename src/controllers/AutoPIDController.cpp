#include "AutoPIDController.h"

AutoPIDController::AutoPIDController()
    :
    gyro(0),
    lEncoder(1, 2),
    rEncoder(3, 4),

    kPa(0.1),
    kIa(0.0),
    kDa(0.0),

    kPd(0.1),
    kId(0.0),
    kDd(0.0),

    kPw(0.1),
    kIw(0.0),
    kDw(0.0),
    
    aController(kPa, kIa, kDa, &gyro, 0),
    dController(kPd, kId, kDd, &lEncoder, 0),
    wlController(kPw, kIw, kDw, &lEncoder, 0),
    wrController(kPw, kIw, kDw, &rEncoder, 0),
    stepZeroDistance(10),
    stepOneAngle(7.0),
    stepTwoDistance(8)

{
    aController.SetPIDSourceType(PIDSourceType::kDisplacement);
    dController.SetPIDSourceType(PIDSourceType::kDisplacement);
    wlController.SetPIDSourceType(PIDSourceType::kRate);
    wrController.SetPIDSourceType(PIDSourceType::kRate);
}
//! Autonomously handle the robot.

/**
* Using sensors and PID control, score points without driver input.
* Current autonomous plan is to put the shooter down,
* Go under the low bar, turn, and push a ball into the low goal.
* @param bot The Robot to control.
*/
void AutoPIDController::handle(SlothRobot* bot)
{
    float throttle = dController.Get();
    float wheel = aController.Get();
    wlController.SetPID(kPw, kIw, kDw, throttle+wheel);
    wrController.SetPID(kPw, kIw, kDw, throttle-wheel);

    bot->drivetrain.DriveLR(wlController.Get(), wrController.Get());
    
}
//! This will be called at AutonomousInit(), so that we can keep track of what we have to do.
void AutoPIDController::start()
{
    gyro.Calibrate();
    aController.SetSetpoint(0.0);
    dController.SetSetpoint(stepZeroDistance);
    std::cout << "Starting Autonomous Control." << std::endl;
}
