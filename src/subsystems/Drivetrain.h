#pragma once
#include <WPILib.h>

class Drivetrain {
private:
    CANTalon driveLeft1;
    CANTalon driveLeft2;
    CANTalon driveRight1;
    CANTalon driveRight2;

    DoubleSolenoid shiftLeft;
    DoubleSolenoid shiftRight;
public:
    typedef enum
    {
        HIGH,
        LOW
    } ShiftState;

    Drivetrain();
    void DriveLR(double left, double right);
    void Shift(ShiftState state);
};