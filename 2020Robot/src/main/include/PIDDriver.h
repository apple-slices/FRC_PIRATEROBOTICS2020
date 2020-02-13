#include "Robot.h"
#include <frc/SmartDashboard/SmartDashboard.h>
#include "rev/CANSparkMax.h"
#include "rev/CANEncoder.h"
#include "rev/CANPIDController.h"

class PIDDriver{
private:
    const int lMotorID = 13;
    const int rMotorID = 3;
    rev::CANSparkMax lMotor =  rev::CANSparkMax(lMotorID, rev::CANSparkMax::MotorType::kBrushless);
    rev::CANSparkMax rMotor =  rev::CANSparkMax(rMotorID, rev::CANSparkMax::MotorType::kBrushless);
    double kp = 0.0;
    double ki = 0.0;
    double kd = 0.0;
    double iz = 0.0;
    double ff = 0.0;
    double min = 0.0;
    double max = 0.0;
    double setPt = 0.0;

public:
    int drive(double distance, bool testing = false);
};