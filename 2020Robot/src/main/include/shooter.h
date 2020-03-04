#pragma once

#include <frc/SmartDashboard/SmartDashboard.h>
#include "rev/CANSparkMax.h"
#include "rev/CANEncoder.h"
#include "rev/CANPIDController.h"

class Shooter {
private:
    const int motor1ID = 12;
    const int motor2ID = 3;

    rev::CANSparkMax motor1 = rev::CANSparkMax(motor1ID, rev::CANSparkMax::MotorType::kBrushless);
    rev::CANSparkMax motor2 = rev::CANSparkMax(motor2ID, rev::CANSparkMax::MotorType::kBrushless);

    // will do the pid calculations for us
    rev::CANPIDController PIDController1 = rev::CANPIDController(motor1);
    rev::CANPIDController PIDController2 = rev::CANPIDController(motor2);

    // used to measure the results of pid
    rev::CANEncoder encoder1 = rev::CANEncoder(motor1);
    rev::CANEncoder encoder2 = rev::CANEncoder(motor2);

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
    int spinShooter(bool testing = false);
    void setSpeed(double speed) {
        setPt = speed;
        motor1.RestoreFactoryDefaults();
        motor2.RestoreFactoryDefaults();
    }
};