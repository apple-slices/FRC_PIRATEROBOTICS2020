#pragma once 
#ifndef AUTONOMOUS
#define AUTONOMOUS

#include "Robot.h"
#include "math.h"


class PHHSAuntonomous{

    private:

    const int m_lMotorFrontNum = 3;
    const int m_rMotorFrontNum = 13;
    const double m_neutral = 0; 

    rev::CANSparkMax * lMotorFront = new rev::CANSparkMax(m_lMotorFrontNum, rev::CANSparkMax::MotorType::kBrushless);
    rev::CANSparkMax * rMotorFront = new rev::CANSparkMax(m_rMotorFrontNum, rev::CANSparkMax::MotorType::kBrushless);
    
    //Motor Control limits 
    const int kPeakCurrentAmpIntake = 40; //Max. before tirggering current limit 
    const int kPeakCurrentAmpIndexing = 40; //Max. before tiggering current limit 
    const int kContinCurrentAmps = 40; //hold current after limit is tirgged

    const int kIntakemotorID = 1;
    
    public:
    
    constexpr static float kLmotorfront = 1.0;
    constexpr static float kRmotorfront = 1.0;


    constexpr static int StartAutoBtn = 5;



    void AutonomousInit();
    



};


#endif