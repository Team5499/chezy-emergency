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

/*
    // Update PID Controllers
    bot->shooter.UpdatePID();
    if(op.GetRawButton(8)){
        // Batter Shot
        bot->shooter.SetWheelSpeed(3800.0, 2500.0);
        bot->shooter.SetArmAngle(20.35);
    } else if(op.GetRawButton(10)){
        // Cleat Shot
        bot->shooter.SetWheelSpeed(5100.0, 5000.0);
        bot->shooter.SetArmAngle(35);
    } else if (op.GetRawButton(9)) {
        // Turn Off Shooters
        bot->shooter.SetWheelSpeed(0.0, 0.0);
        bot->shooter.Lower();
    }

    if (op.GetRawButton(1)) {
        bot->shooter.Feed();
    } else {
        bot->shooter.stopFeed();
    }

    bot->shooter.RaiseArm();
    bot->shooter.ShootWheels();
*/
