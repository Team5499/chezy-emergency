#include "Pcontroller.h"

PController::PController(int sensorPort, double sens) {
    :
    sensor(sensorPort),
    kP = sens,
    target = 0
}
double PController::getOutput() {
    return (target-sensor.Get()) * kP;
}
void PController::setTarget(double t) {
    target = t;
}