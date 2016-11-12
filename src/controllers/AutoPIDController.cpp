#include "AutoPIDController.h"

AutoPIDController::AutoPIDController()
    :
    autoTimer(),

    // Sensors & sensor managers
    gyro(),
    lEncoder(0, 1),
    rEncoder(2, 3),
    distance(&lEncoder, &rEncoder),

    // Angular PID constants
    kPa(0.05),
    kIa(0.0),
    kDa(0.0),
    kEa(3.0),
    kVa(2.0),

    // Distance PID constants
    kPd(0.015),
    kId(0.0),
    kDd(0.0),
    kEd(20.0),
    kVd(125.0),

    step(-1),
    stepZeroDistance(950),
    stepOneAngle(60),
    stepTwoDistance(560),
    
    speedOut(),
    angleOut(),
    aController(kPa, kIa, kDa, &gyro, &angleOut),
    dController(kPd, kId, kDd, &distance, &speedOut)

{
    aController.SetPIDSourceType(PIDSourceType::kDisplacement); // Control angle, not angular velocity
    dController.SetPIDSourceType(PIDSourceType::kDisplacement); // Control distance, not velocity.

    aController.SetContinuous(true);
    dController.SetContinuous(false);

    aController.SetAbsoluteTolerance(kEa);
    dController.SetAbsoluteTolerance(kEd);

    aController.SetToleranceBuffer(5);
    dController.SetToleranceBuffer(5);

    rEncoder.SetReverseDirection(true); // Right encoder went negative?

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
    SmartDashboard::PutNumber("Current Step", step);
    /* 
    This is fairly dirty, we need to talk about better solutions for 2017.
    If anyone has a better idea, please tell me because I hate this.
    */
    if (step == -1) {
        bot->intake.SetArm(-.55);
        if (autoTimer.Get() > 0.75) {
            autoTimer.Stop();
            bot->intake.SetArm(0);
            step++;

            aController.SetSetpoint(0.0);
            dController.SetSetpoint(stepZeroDistance); //Drive Straight
            aController.Enable();
            dController.Enable();
    
        }
        return;
    }
    if ((dController.OnTarget() && std::fabs(distance.GetRate()) < kVd)
     && (aController.OnTarget() && std::fabs(gyro.GetRate()) < kVa) && step != 5499) {
        std::cout << "Moving on to step " << step+1 << std::endl;
        std::cout << "Current Angle error: " << aController.GetError() << std::endl;
        std::cout << "Current Distance error: " << dController.GetError() << std::endl;
        // If we're within acceptable bounds for both angle and distance
        step++;
        // Zero the sensors
        dController.Reset();
        aController.Reset();
        gyro.Reset();
        distance.Reset();
        dController.Enable();
        aController.Enable();

        if (step == 1) //Turn to angle
        {
            dController.SetSetpoint(0);
            aController.SetSetpoint(stepOneAngle);
        }
        if (step == 2) //Drive straight again
        {
            dController.SetSetpoint(stepTwoDistance);
            aController.SetSetpoint(0);
        }
        if (step == 3) //Outtake
        {
            dController.SetSetpoint(0);
            aController.Disable();
            bot->intake.SetRoller(-1);
            step = 5499;
        }

    }
    

    double speed = speedOut.getOut(); //!< The desired base speed of the robot wheels.
    double angle = angleOut.getOut(); //!< The difference in desired wheel speeds between left and right.

    SmartDashboard::PutNumber("Distance", distance.PIDGet());
    SmartDashboard::PutNumber("Angle", gyro.GetAngle());

    SmartDashboard::PutNumber("Angular Velocity", gyro.GetRate());
    SmartDashboard::PutNumber("Velocity", distance.GetRate());
    
    SmartDashboard::PutNumber("Angle AvgError", aController.GetAvgError());
    SmartDashboard::PutNumber("Distance AvgError", dController.GetAvgError());

    bot->drivetrain.DriveLR(speed+angle, speed-angle);
    
}
//! This will be called at AutonomousInit(), so that we can keep track of what we have to do.
void AutoPIDController::start()
{
    step = -1;
    autoTimer.Stop();
    autoTimer.Reset();
    autoTimer.Start();
    gyro.Reset();
    distance.Reset();

    std::cout << "Starting Autonomous Control." << std::endl;
}

void AutoPIDController::posthumous() {
    std::cout << "Ended on step " << step << std::endl;
    std::cout << "Final Relative Angle: " << gyro.PIDGet() << std::endl;
    std::cout << "Final Angle error: " << aController.GetError() << std::endl;
    std::cout << "Final Relative Distance: " << distance.PIDGet() << std::endl;
    std::cout << "Final Distance error: " << dController.GetError() << std::endl;
    
    // Make sure controllers aren't running in background
    aController.Disable();
    dController.Disable();
    
}