#include "PLightController.h"

PLightController::PLightController(int sensorPort, double sens)
    :
    sensor(sensorPort),
    kP(sens),
    target(0)
{
}
double PLightController::getOutput() {

  double pv = sensor.Get() / sensor.GetPeriod();
  return (target - pv) * kP;
  sensor.Reset();
}
void PLightController::setTarget(double t) {
    target = t;
}

void PLightController::updateSensor() {
  //double rpm = 60.0 / (sensor.GetPeriod());
}
