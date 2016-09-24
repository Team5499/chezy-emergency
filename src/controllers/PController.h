#pragma once
#include <WPILib.h>

class PController {
private:
    AnalogInput sensor;
    double kP;
    double target;
public:
    PController(uint32_t sensorPort, double sens);
    void setTarget(double target);
    double getOutput();
};
