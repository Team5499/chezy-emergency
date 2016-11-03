#include "AutoPIDController.h"

AutoPIDController::AutoPIDController()
    :
    gyro(),
    lEncoder(0, 1),
    rEncoder(2, 3),

    // Angular PID constants
    kPa(0.005),
    kIa(0.0001),
    kDa(0.0),

    // Distance PID constants
    kPd(0.005),
    kId(0.0),
    kDd(0.0),
    
    stepZeroDistance(-800),
    stepOneAngle(7.0),
    stepTwoDistance(8),
    
    speedOut(),
    angleOut(),

    aController(kPa, kIa, kDa, &gyro, &angleOut),
    dController(kPd, kId, kDd, &lEncoder, &speedOut)
    

{
    aController.SetPIDSourceType(PIDSourceType::kDisplacement); // Control angle, not angular velocity
    dController.SetPIDSourceType(PIDSourceType::kDisplacement); // Control distance, not velocity.

    aController.SetContinuous(true);
    dController.SetContinuous(false);


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
    double speed = speedOut.getOut(); //!< The desired base speed of the robot wheels.
    double angle = angleOut.getOut(); //!< The difference in desired wheel speeds between left and right.
    
    speed = 0;

    SmartDashboard::PutNumber("Speed", speed);
    SmartDashboard::PutNumber("Angle", angle);

    SmartDashboard::PutNumber("Distance Error", dController.GetError());
    SmartDashboard::PutNumber("Angle Error", aController.GetError());
    
    bot->drivetrain.DriveLR(speed+angle, speed-angle);
    
}
//! This will be called at AutonomousInit(), so that we can keep track of what we have to do.
void AutoPIDController::start()
{
    
    aController.SetSetpoint(90.0);
    dController.SetSetpoint(stepZeroDistance);
    aController.Enable();
    dController.Enable();

    gyro.Reset();

    std::cout << "Starting Autonomous Control." << std::endl;
}
