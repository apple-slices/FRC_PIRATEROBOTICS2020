// Jason Cheng / Jason Nguyen

#include <frc/SmartDashboard/SmartDashboard.h>
#include "rev/CANSparkMax.h"
#include "rev/CANEncoder.h"
#include "rev/CANPIDController.h"

int PIDDrive(double distance, rev::CANEncoder &wheelEncoder, rev::CANSparkMax &wheelController, bool testing = false) {
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
    static rev::CANPIDController PIDController = rev::CANPIDController(wheelController);

    // init stuff
    static bool init = true;
    if (init) {
        wheelController.RestoreFactoryDefaults();
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
    PIDController.SetP(kp);
    PIDController.SetI(ki);
    PIDController.SetD(kd);
    PIDController.SetIZone(iz);
    PIDController.SetFF(ff);
    PIDController.SetOutputRange(min, max);
    PIDController.SetReference(setPt, rev::ControlType::kPosition);

    frc::SmartDashboard::PutNumber("SetPoint", setPt);
}