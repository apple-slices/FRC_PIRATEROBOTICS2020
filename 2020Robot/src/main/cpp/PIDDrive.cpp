// Jason Cheng / Jason Nguyen

#include "PIDDrive.h"

    int PIDDrive::drive(double distance, rev::CANEncoder &encoder1, rev::CANEncoder &encoder2, rev::CANSparkMax &wheel1, rev::CANSparkMax &wheel2, bool testing) {
    // constants
    static double kp = 0.0;
    static double ki = 0.0;
    static double kd = 0.0;
    static double iz = 0.0;
    static double ff = 0.0;
    static double min = 0.0;
    static double max = 0.0;
    static double setPt = 0.0;

    // static objects to be reused
    static rev::CANPIDController pid1 = rev::CANPIDController(wheel1);
    static rev::CANPIDController pid2 = rev::CANPIDController(wheel2);

    // init stuff
    static bool init = true;
    if (init) {
        wheel1.RestoreFactoryDefaults();
        wheel2.RestoreFactoryDefaults();
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
        kp = frc::SmartDashboard::GetNumber("P Gain", 0);
        ki = frc::SmartDashboard::GetNumber("I Gain", 0);
        kd = frc::SmartDashboard::GetNumber("D Gain", 0);
        iz = frc::SmartDashboard::GetNumber("I Zone", 0);
        ff = frc::SmartDashboard::GetNumber("Feed Forward", 0);
        max = frc::SmartDashboard::GetNumber("Max Output", 0);
        min = frc::SmartDashboard::GetNumber("Min Output", 0);
        setPt = frc::SmartDashboard::GetNumber("Set Rotations", 0);
    }

    // update parameters
    pid1.SetP(kp);
    pid1.SetI(ki);
    pid1.SetD(kd);
    pid1.SetIZone(iz);
    pid1.SetFF(ff);
    pid1.SetOutputRange(min, max);
    pid1.SetReference(setPt, rev::ControlType::kPosition);

    pid2.SetP(kp);
    pid2.SetI(ki);
    pid2.SetD(kd);
    pid2.SetIZone(iz);
    pid2.SetFF(ff);
    pid2.SetOutputRange(min, max);
    pid2.SetReference(setPt, rev::ControlType::kPosition);

    frc::SmartDashboard::PutNumber("SetPoint", setPt);
}