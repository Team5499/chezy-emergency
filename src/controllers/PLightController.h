#pragma once
#include <WPILib.h>


class PController {
    private:
        LightSensor sensor;
        double kP;
        double target;
    public:
        void setTarget(double target);
        double getOutput();
        void updateSensor();
}