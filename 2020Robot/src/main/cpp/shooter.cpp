// Jason Cheng

#include "Robot.h"

int Shooter::spinShooter(bool testing) {
    // one-time init stuff
    static bool init = true;
    if (init && testing) {
        init = false;
        // write values to smartdashboard
        frc::SmartDashboard::PutNumber("P Gain", kp);
        frc::SmartDashboard::PutNumber("I Gain", ki);
        frc::SmartDashboard::PutNumber("D Gain", kd);
        frc::SmartDashboard::PutNumber("I Zone", iz);
        frc::SmartDashboard::PutNumber("Feed Forward", ff);
        frc::SmartDashboard::PutNumber("Max Output", min);
        frc::SmartDashboard::PutNumber("Min Output", max);
        frc::SmartDashboard::PutNumber("Set Rotations", 0);
    }

    // tweak constants in testing mode
    if (testing) {
        frc::SmartDashboard::PutNumber("FL motor position", encoder1.GetPosition());
        frc::SmartDashboard::PutNumber("FR motor position", encoder1.GetPosition());
        frc::SmartDashboard::PutNumber("FL moter velocity", encoder2.GetVelocity());
        frc::SmartDashboard::PutNumber("FR moter velocity", encoder2.GetVelocity());
        kp = frc::SmartDashboard::GetNumber("P Gain", 0.0);
        ki = frc::SmartDashboard::GetNumber("I Gain", 0.0);
        kd = frc::SmartDashboard::GetNumber("D Gain", 0.0);
        iz = frc::SmartDashboard::GetNumber("I Zone", 0.0);
        ff = frc::SmartDashboard::GetNumber("Feed Forward", 0.0);
        max = frc::SmartDashboard::GetNumber("Max Output", 0.0);
        min = frc::SmartDashboard::GetNumber("Min Output", 0.0);
        setPt = frc::SmartDashboard::GetNumber("Set Rotations", 0.0);
    }

    // update parameters so pid controllers know what to do
    PIDController1.SetP(kp);
    PIDController1.SetI(ki);
    PIDController1.SetD(kd);
    PIDController1.SetIZone(iz);
    PIDController1.SetFF(ff);
    PIDController1.SetOutputRange(min, max);
    PIDController1.SetReference(setPt, rev::ControlType::kPosition);

    PIDController2.SetP(kp);
    PIDController2.SetI(ki);
    PIDController2.SetD(kd);
    PIDController2.SetIZone(iz);
    PIDController2.SetFF(ff);
    PIDController2.SetOutputRange(min, max);
    PIDController2.SetReference(setPt, rev::ControlType::kPosition);
}