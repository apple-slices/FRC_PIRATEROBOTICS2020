// Jason Cheng / Jason Nguyen
#include "Robot.h"

int PIDDriver::drive(double distance, bool testing) {
    // static objects to be reused
    static rev::CANPIDController lPIDController = rev::CANPIDController(lMotor);
    static rev::CANPIDController rPIDController = rev::CANPIDController(rMotor);
    static rev::CANEncoder lEncoder = rev::CANEncoder(lMotor);
    static rev::CANEncoder rEncoder = rev::CANEncoder(rMotor);

    // one-time init stuff
    static bool init = true;
    if (init) {
        lMotor.RestoreFactoryDefaults();
        rMotor.RestoreFactoryDefaults();
        init = false;
        if (testing) {
            frc::SmartDashboard::PutNumber("P Gain", kp);
            frc::SmartDashboard::PutNumber("I Gain", ki);
            frc::SmartDashboard::PutNumber("D Gain", kd);
            frc::SmartDashboard::PutNumber("I Zone", iz);
            frc::SmartDashboard::PutNumber("Feed Forward", ff);
            frc::SmartDashboard::PutNumber("Max Output", min);
            frc::SmartDashboard::PutNumber("Min Output", max);
            frc::SmartDashboard::PutNumber("Set Rotations", 0);
        }
    }

    // tweak constants in testing mode
    if (testing) {
        kp = frc::SmartDashboard::GetNumber("P Gain", 0.0);
        ki = frc::SmartDashboard::GetNumber("I Gain", 0.0);
        kd = frc::SmartDashboard::GetNumber("D Gain", 0.0);
        iz = frc::SmartDashboard::GetNumber("I Zone", 0.0);
        ff = frc::SmartDashboard::GetNumber("Feed Forward", 0.0);
        max = frc::SmartDashboard::GetNumber("Max Output", 0.0);
        min = frc::SmartDashboard::GetNumber("Min Output", 0.0);
        setPt = frc::SmartDashboard::GetNumber("Set Rotations", 0.0);
    }

    // update parameters
    lPIDController.SetP(kp);
    lPIDController.SetI(ki);
    lPIDController.SetD(kd);
    lPIDController.SetIZone(iz);
    lPIDController.SetFF(ff);
    lPIDController.SetOutputRange(min, max);
    lPIDController.SetReference(setPt, rev::ControlType::kPosition);

    rPIDController.SetP(kp);
    rPIDController.SetI(ki);
    rPIDController.SetD(kd);
    rPIDController.SetIZone(iz);
    rPIDController.SetFF(ff);
    rPIDController.SetOutputRange(min, max);
    rPIDController.SetReference(setPt, rev::ControlType::kPosition);

    frc::SmartDashboard::PutNumber("Left motor position", lEncoder.GetPosition());
    frc::SmartDashboard::PutNumber("Right motor position", rEncoder.GetPosition());
}