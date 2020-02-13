
#include "Robot.h"
#include <frc/SmartDashboard/SmartDashboard.h>
#include "rev/CANSparkMax.h"
#include "rev/CANEncoder.h"
#include "rev/CANPIDController.h"

class PIDDrive{

    private:
    //General
    const int m_lMotorFrontNum = 13;
    const int m_rMotorFrontNum = 3;


    public:
    rev::CANSparkMax lMotorFront =  rev::CANSparkMax(m_lMotorFrontNum, rev::CANSparkMax::MotorType::kBrushless);
    rev::CANSparkMax rMotorFront =  rev::CANSparkMax(m_rMotorFrontNum, rev::CANSparkMax::MotorType::kBrushless);
    rev::CANEncoder encoder1 =  rev::CANEncoder(lMotorFront);
    rev::CANEncoder encoder2 =  rev::CANEncoder(lMotorFront);
    int drive(double distance, rev::CANEncoder &encoder1, rev::CANEncoder &encoder2, rev::CANSparkMax &wheel1, rev::CANSparkMax &wheel2, bool testing);
};




