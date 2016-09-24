#include "Shooter.h"


Shooter::Shooter()
    :
    TopFlyWheel(2),
    BottomFlyWheel(1),
    FeedWheel(3),
    ArmPivot(8),
    ArmController(0, 0.08),
    TopController(1, .000003, 5300),
    BotController(0, .000001, 4800),
    CurrentArmSetPoint = 0
{
}

void Shooter::Lower() {
    ArmPivot.set(0);
	CurrentArmSetpoint = 0;
	ArmController.setTarget(0);
}
void Shooter::RaiseArm() {
    ArmPivot.set(ArmController.getOutput());
}
void Shooter::Feed(); {
    FeedWheel.set(1);
}
void Shooter::ShootWheels(){
	TopFlyWheel.set(TopController.getOutput());
	BottomFlyWheel.set(-1 * BotlController.getOutput());
}
void Shooter::StopWheels() {
    TopFlyWheel.set(0);
	BottomFlyWheel.set(0);
	FeedWheel.set(0);
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