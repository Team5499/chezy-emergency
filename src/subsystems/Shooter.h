#pragma once
#include <WPILib.h>
#include "PController.h"
#include "PLightController.h"

class Shooter {
private:

    CANTalon BottomFlyWheel;
    CANTalon TopFlyWheel;
    CANTalon FeedWheel;
    CANTalon ArmPivot;
    PController ArmController;
    PLightController TopController;
    PLightController BotController;
    double CurrentArmSetpoint;

public: 
    Shooter();

    void UpdatePID();

    void Lower();
    void RaiseArm();
    void Feed();

    void ShootWheels();
    void StopWheels();
    
    void SetArmAngle(double angle);
    void SetWheelSpeed(double top, double bot);


    
};
