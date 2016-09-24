#include "Shooter.h"


Shooter::Shooter()
    :
    BottomFlyWheel(1),
    TopFlyWheel(3),
    FeedWheel(2),
    ArmPivot(8),
    ArmController(0, 0.08),
    TopController(1, .000003),//, 5300),
    BotController(0, .000001),//, 4800),
    CurrentArmSetpoint(0)
{
}

void Shooter::Lower() {
    ArmPivot.Set(0);
	CurrentArmSetpoint = 0;
	ArmController.setTarget(0);
}
void Shooter::RaiseArm() {
    ArmPivot.Set(ArmController.getOutput());
}
void Shooter::Feed() {
    FeedWheel.Set(1);
}
void Shooter::stopFeed() {
    FeedWheel.Set(0);
}
void Shooter::ShootWheels(){
  TopFlyWheel.Set(TopController.getOutput());
  BottomFlyWheel.Set(-1 * BotController.getOutput());
}
void Shooter::StopWheels() {
    TopFlyWheel.Set(0);
    BottomFlyWheel.Set(0);
    FeedWheel.Set(0);
}

void Shooter::SetArmAngle(double angle) {
    ArmController.setTarget(angle);
}
void Shooter::SetWheelSpeed(double top, double bot) {
    TopController.setTarget(top);
    BotController.setTarget(bot);
}

void Shooter::UpdatePID() {
    TopController.updateSensor();
    BotController.updateSensor();

}
