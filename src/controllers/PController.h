#pragma once
#include <WPILib.h>


class PController {
    private:
        Pot sensor;
        double kP;
        double target;
    public:
        void setTarget(double target);
        double getOutput();
}