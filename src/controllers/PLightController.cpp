#include "Pcontroller.h"

PLightController::PLightController(int sensorPort, double sens, int top) {
    :
    sensor(sensorPort, top),
    kP = sens,
    target = 0
}
double PLightController::getOutput() {
    return (target-sensor.Get()) * kP;
}
void PLightController::setTarget(double t) {
    target = t;
}

void PLightController::updateSensor() {
    sensor.update();
}