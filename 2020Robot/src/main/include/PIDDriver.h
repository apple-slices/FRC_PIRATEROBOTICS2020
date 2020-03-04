#pragma once

#include <frc/SmartDashboard/SmartDashboard.h>
#include "rev/CANSparkMax.h"
#include "rev/CANEncoder.h"
#include "rev/CANPIDController.h"

class PIDDriver {
private:
    const int lMotorID = 12;
    const int rMotorID = 3;

    // fl, fr, bl, br = front left, front right, back left, back right
    rev::CANSparkMax flMotor = rev::CANSparkMax(lMotorID, rev::CANSparkMax::MotorType::kBrushless);
    rev::CANSparkMax frMotor = rev::CANSparkMax(rMotorID, rev::CANSparkMax::MotorType::kBrushless);
    rev::CANSparkMax blMotor = rev::CANSparkMax(lMotorID, rev::CANSparkMax::MotorType::kBrushless);
    rev::CANSparkMax brMotor = rev::CANSparkMax(rMotorID, rev::CANSparkMax::MotorType::kBrushless);

    // will do the pid calculations for us
    rev::CANPIDController flPIDController = rev::CANPIDController(flMotor);
    rev::CANPIDController frPIDController = rev::CANPIDController(frMotor);
    rev::CANPIDController blPIDController = rev::CANPIDController(flMotor);
    rev::CANPIDController brPIDController = rev::CANPIDController(frMotor);

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

public:
    int drive(bool testing = false);
    void setDistance(double distance) {
        setPt = distance;
        flMotor.RestoreFactoryDefaults();
        frMotor.RestoreFactoryDefaults();
        blMotor.RestoreFactoryDefaults();
        brMotor.RestoreFactoryDefaults();
    }
};