#include "AutoPIDController.h"

AutoPIDController::AutoPIDController()
    :
    gyro(),
    lEncoder(0, 1),
    rEncoder(2, 3),
    distance(&lEncoder, &rEncoder),

    // Angular PID constants
    kPa(0.005),
    kIa(0.0001),
    kDa(0.0),
    kEa(1),

    // Distance PID constants
    kPd(0.005),
    kId(0.0),
    kDd(0.0),
    kEd(10),

    step(0),    
    stepZeroDistance(800),
    stepOneAngle(30),
    stepTwoDistance(700),
    
    speedOut(),
    angleOut(),
    aController(kPa, kIa, kDa, &gyro, &angleOut),
    dController(kPd, kId, kDd, &distance, &speedOut)

{
    aController.SetPIDSourceType(PIDSourceType::kDisplacement); // Control angle, not angular velocity
    dController.SetPIDSourceType(PIDSourceType::kDisplacement); // Control distance, not velocity.

    aController.SetContinuous(true);
    dController.SetContinuous(false);

    lEncoder.SetReverseDirection(false); // Left encoder went negative?

    gyro.Calibrate();
}
//! Autonomously handle the robot.

/**
* Using sensors and PID control, score points without driver input.
* Current autonomous plan is to put the shooter down,
* Go under the low bar, turn, and outtake a ball into the low goal.
* @param bot The Robot to control.
*/
void AutoPIDController::handle(SlothRobot* bot)
{
    /* 
    This is fairly dirty, we need to talk about better solutions for 2017.
    If anyone has a better idea, please tell me because I hate this.
    */
    if (abs(dController.GetError())<kEd && abs(aController.GetError())<kEa) {
        // If we're within acceptable bounds for both angle and distance
        step++;
        // Zero the sensors
        gyro.Reset();
        lEncoder.Reset();
        rEncoder.Reset();

        if (step == 1) 
        {
            
            dController.SetSetpoint(0);
            // TODO: The dController needs an input source capable of giving average across both wheels
            // or the robot will back up when it tries to turn.
            aController.SetSetpoint(stepOneAngle);
        }
        if (step == 2) 
        {
            dController.SetSetpoint(stepTwoDistance);
            aController.SetSetpoint(0);
        }
        if (step == 3) 
        {
            dController.Disable();
            aController.Disable();
            bot->intake.SetRoller(1);
        }
    }
    

    double speed = speedOut.getOut(); //!< The desired base speed of the robot wheels.
    double angle = angleOut.getOut(); //!< The difference in desired wheel speeds between left and right.

    SmartDashboard::PutNumber("Speed", speed);
    SmartDashboard::PutNumber("Angle", angle);

    SmartDashboard::PutNumber("Distance Error", dController.GetError());
    SmartDashboard::PutNumber("Angle Error", aController.GetError());
    
    bot->drivetrain.DriveLR(speed+angle, speed-angle);
    
}
//! This will be called at AutonomousInit(), so that we can keep track of what we have to do.
void AutoPIDController::start()
{
    
    aController.SetSetpoint(0.0);
    dController.SetSetpoint(stepZeroDistance);
    aController.Enable();
    dController.Enable();

    gyro.Reset();

    std::cout << "Starting Autonomous Control." << std::endl;
}
