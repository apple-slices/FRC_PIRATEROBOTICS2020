// Jason Cheng / Jason Nguyen
#include "Robot.h"

int PIDDriver::drive(bool testing) {
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
    flController.SetP(kp);
    flController.SetI(ki);
    flController.SetD(kd);
    flController.SetIZone(iz);
    flController.SetFF(ff);
    flController.SetOutputRange(min, max);
    flController.SetReference(setPt, rev::ControlType::kPosition);

    frController.SetP(kp);
    frController.SetI(ki);
    frController.SetD(kd);
    frController.SetIZone(iz);
    frController.SetFF(ff);
    frController.SetOutputRange(min, max);
    frController.SetReference(setPt, rev::ControlType::kPosition);

    blController.SetP(kp);
    blController.SetI(ki);
    blController.SetD(kd);
    blController.SetIZone(iz);
    blController.SetFF(ff);
    blController.SetOutputRange(min, max);
    blController.SetReference(setPt, rev::ControlType::kPosition);

    brController.SetP(kp);
    brController.SetI(ki);
    brController.SetD(kd);
    brController.SetIZone(iz);
    brController.SetFF(ff);
    brController.SetOutputRange(min, max);
    brController.SetReference(setPt, rev::ControlType::kPosition);
}