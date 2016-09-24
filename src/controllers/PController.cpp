#include "Pcontroller.h"

PController::PController(uint32_t sensorPort, double sens)
    :
    sensor(sensorPort),
    kP(sens),
    target (0)
{
}
double PController::getOutput() {
    return (target-sensor.GetValue()) * kP;
}
void PController::setTarget(double t) {
    target = t;
}