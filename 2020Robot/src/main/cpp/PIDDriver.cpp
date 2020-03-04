// Jason Cheng / Jason Nguyen
#include "Robot.h"

int PIDDriver::drive(bool testing) {
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
        frc::SmartDashboard::PutNumber("FL motor position", flEncoder.GetPosition());
        frc::SmartDashboard::PutNumber("FR motor position", frEncoder.GetPosition());
        frc::SmartDashboard::PutNumber("BL motor position", blEncoder.GetPosition());
        frc::SmartDashboard::PutNumber("BR motor position", brEncoder.GetPosition());

        frc::SmartDashboard::PutNumber("FL moter velocity", flEncoder.GetVelocity());
        frc::SmartDashboard::PutNumber("FR moter velocity", frEncoder.GetVelocity());
        frc::SmartDashboard::PutNumber("BL moter velocity", blEncoder.GetVelocity());
        frc::SmartDashboard::PutNumber("BR moter velocity", brEncoder.GetVelocity());
        
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
    flPIDController.SetP(kp);
    flPIDController.SetI(ki);
    flPIDController.SetD(kd);
    flPIDController.SetIZone(iz);
    flPIDController.SetFF(ff);
    flPIDController.SetOutputRange(min, max);
    flPIDController.SetReference(setPt, rev::ControlType::kPosition);

    frPIDController.SetP(kp);
    frPIDController.SetI(ki);
    frPIDController.SetD(kd);
    frPIDController.SetIZone(iz);
    frPIDController.SetFF(ff);
    frPIDController.SetOutputRange(min, max);
    frPIDController.SetReference(setPt, rev::ControlType::kPosition);

    blPIDController.SetP(kp);
    blPIDController.SetI(ki);
    blPIDController.SetD(kd);
    blPIDController.SetIZone(iz);
    blPIDController.SetFF(ff);
    blPIDController.SetOutputRange(min, max);
    blPIDController.SetReference(setPt, rev::ControlType::kPosition);

    brPIDController.SetP(kp);
    brPIDController.SetI(ki);
    brPIDController.SetD(kd);
    brPIDController.SetIZone(iz);
    brPIDController.SetFF(ff);
    brPIDController.SetOutputRange(min, max);
    brPIDController.SetReference(setPt, rev::ControlType::kPosition);
}