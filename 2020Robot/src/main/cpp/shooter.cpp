#include "Shooter.h"

Shooter::Shooter()
{
    PIDController1.SetFeedbackDevice(encoder1);
    PIDController2.SetFeedbackDevice(encoder2);

    PIDController1.SetSmartMotionAllowedClosedLoopError(tolerance);
    PIDController2.SetSmartMotionAllowedClosedLoopError(tolerance);

    PIDController1.SetP(kp);
    PIDController1.SetI(ki);
    PIDController1.SetD(kd);
    PIDController1.SetIZone(iz);
    PIDController1.SetFF(ff);
    PIDController1.SetOutputRange(min, max);

    PIDController2.SetP(kp);
    PIDController2.SetI(ki);
    PIDController2.SetD(kd);
    PIDController2.SetIZone(iz);
    PIDController2.SetFF(ff);
    PIDController2.SetOutputRange(min, max);
}

void Shooter::shooterOn()
{
    PIDController1.SetReference(targetVel, rev::ControlType::kSmartVelocity);
    PIDController2.SetReference(targetVel, rev::ControlType::kSmartVelocity);
};

void Shooter::shooterOff()
{
    PIDController1.SetReference(0, rev::ControlType::kSmartVelocity);
    PIDController2.SetReference(0, rev::ControlType::kSmartVelocity);
}

void Shooter::setSpeed(double speed)
{
    targetVel = speed;
    motor1.RestoreFactoryDefaults();
    motor2.RestoreFactoryDefaults();
}

void Shooter::display()
{
    frc::SmartDashboard::PutNumber("P Gain", kp);
    frc::SmartDashboard::PutNumber("I Gain", ki);
    frc::SmartDashboard::PutNumber("D Gain", kd);
    frc::SmartDashboard::PutNumber("I Zone", iz);
    frc::SmartDashboard::PutNumber("Feed Forward", ff);
    frc::SmartDashboard::PutNumber("Max Output", min);
    frc::SmartDashboard::PutNumber("Min Output", max);
    frc::SmartDashboard::PutNumber("Set Rotations", 0);
}

void Shooter::read()
{
    kp = frc::SmartDashboard::GetNumber("P Gain", 0.0);
    ki = frc::SmartDashboard::GetNumber("I Gain", 0.0);
    kd = frc::SmartDashboard::GetNumber("D Gain", 0.0);
    iz = frc::SmartDashboard::GetNumber("I Zone", 0.0);
    ff = frc::SmartDashboard::GetNumber("Feed Forward", 0.0);
    max = frc::SmartDashboard::GetNumber("Max Output", 0.0);
    min = frc::SmartDashboard::GetNumber("Min Output", 0.0);
    targetVel = frc::SmartDashboard::GetNumber("Set Rotations", 0.0);

    frc::SmartDashboard::PutNumber("motor1 speed", encoder1.GetVelocity());
    frc::SmartDashboard::PutNumber("motor2 speed", encoder2.GetVelocity());
}