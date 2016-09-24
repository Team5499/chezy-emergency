#pragma once
#include <WPILib.h>

class PLightController {
private:
    Counter sensor;
    double kP;
    double target;
public:
    PLightController(int sensorPort, double sens);
    void setTarget(double target);
    double getOutput();
    void updateSensor();
};
