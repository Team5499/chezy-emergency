#include "AutoController.h"
#include <iterator>

//! Constructor to initialize the timer.
AutoController::AutoController()
    :
    autoTimer()
{
    int rL = 5; //!< Number of steps in the routine.
    double r[rL][5] = {
        {0.0, 0.0, 0.0, 0.0, 0.0},
        {0.5, 1.0, 1.0, 0.0, 0.0},
        {3.0, 0.0, 0.5, -0.2, 0.0},
        {5.0, 0.8, 0.8, 0.0, 0.0},
        {8.0, 0.0, 0.0, 0.0, 1.0},
    };
    for (int x=0; x<rL; x++) {
        for (int y=0; y<5; y++) {
            routine[x][y]=r[x][y];
        }
    }
    
    nextStep = 0;
    nextStepTime = routine[0][0];
    
    
    left = 0.0; 
    right = 0.0;
    arm = 0.0;
    roller = 0.0;
}

//! Autonomously handle the robot.

/**
* Using a timer and precise numbers, run autonomous mode.
* Current autonomous plan is to put the shooter down,
* Go under the low bar, turn, and push a ball into the low goal.
* @param bot The Robot to control.
* @todo run experiments to determine how exact timings for autonomous.
*/
void AutoController::handle(SlothRobot* bot)
{
    double time = autoTimer.Get(); //!< How much time has passed since Autonomous started.
    if (time >= nextStepTime) { // If the elapsed time is greater than the starting time for the "next" step:
        // Check the routine for this step.
        left = routine[nextStep][1];
        right = routine[nextStep][2];
        arm = routine[nextStep][3];
        roller = routine[nextStep][4];

        nextStep++; // OK, we're on the next step now, so we can get ready for the next one.
        nextStepTime = routine[nextStep][0];
        
        
    }
    // Set the motors on every tick. 
    bot->drivetrain.DriveLR(left, right);
    bot->intake.SetArm(arm);
    bot->intake.SetRoller(roller);
    // TODO: Update PID. (Requires sensors)
    
}
//! Start timing.

//! This will be called at AutonomousInit(), so that we can keep track of what we have to do.
void AutoController::start() 
{
    autoTimer.Start();
}
