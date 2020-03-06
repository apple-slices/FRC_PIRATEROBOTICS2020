#pragma once

#include <frc/SmartDashboard/SmartDashboard.h>
#include "rev/CANSparkMax.h"
#include "rev/CANEncoder.h"
#include "rev/CANPIDController.h"

class PIDDriver {
private:
    const int flMotorID = 12;
    const int frMotorID = 3;
    const int blMotorID = 0;
    const int brMotorID = 0;

    // fl, fr, bl, br = front left, front right, back left, back right
    rev::CANSparkMax flMotor = rev::CANSparkMax(flMotorID, rev::CANSparkMax::MotorType::kBrushless);
    rev::CANSparkMax frMotor = rev::CANSparkMax(frMotorID, rev::CANSparkMax::MotorType::kBrushless);
    rev::CANSparkMax blMotor = rev::CANSparkMax(blMotorID, rev::CANSparkMax::MotorType::kBrushless);
    rev::CANSparkMax brMotor = rev::CANSparkMax(brMotorID, rev::CANSparkMax::MotorType::kBrushless);

    // will do the pid calculations for us
    rev::CANPIDController flController = rev::CANPIDController(flMotor);
    rev::CANPIDController frController = rev::CANPIDController(frMotor);
    rev::CANPIDController blController = rev::CANPIDController(flMotor);
    rev::CANPIDController brController = rev::CANPIDController(frMotor);

    // used to measure the results of pid
    rev::CANEncoder flEncoder = rev::CANEncoder(flMotor);
    rev::CANEncoder frEncoder = rev::CANEncoder(frMotor);
    rev::CANEncoder blEncoder = rev::CANEncoder(flMotor);
    rev::CANEncoder brEncoder = rev::CANEncoder(frMotor);

    // all motors use the same constants
    double kp = 0.0;
    double ki = 0.0;
    double kd = 0.0;
    double iz = 0.0;
    double ff = 0.0;
    double min = 0.0;
    double max = 0.0;
    double setPt = 0.0;
    double tolerance = 1.0;

public:
    PIDDriver() {
        flController.SetFeedbackDevice(flEncoder);
        frController.SetFeedbackDevice(frEncoder);
        blController.SetFeedbackDevice(blEncoder);
        brController.SetFeedbackDevice(brEncoder);
        
        flController.SetSmartMotionAllowedClosedLoopError(tolerance);
        frController.SetSmartMotionAllowedClosedLoopError(tolerance);
        blController.SetSmartMotionAllowedClosedLoopError(tolerance);
        brController.SetSmartMotionAllowedClosedLoopError(tolerance);
    }

    int drive(bool testing = false);

    void setDistance(double distance) {
        setPt = distance;
        flMotor.RestoreFactoryDefaults();
        frMotor.RestoreFactoryDefaults();
        blMotor.RestoreFactoryDefaults();
        brMotor.RestoreFactoryDefaults();
    }

    void display() {
        frc::SmartDashboard::PutNumber("P Gain", kp);
        frc::SmartDashboard::PutNumber("I Gain", ki);
        frc::SmartDashboard::PutNumber("D Gain", kd);
        frc::SmartDashboard::PutNumber("I Zone", iz);
        frc::SmartDashboard::PutNumber("Feed Forward", ff);
        frc::SmartDashboard::PutNumber("Max Output", min);
        frc::SmartDashboard::PutNumber("Min Output", max);
        frc::SmartDashboard::PutNumber("Set Rotations", 0);
    }
};
