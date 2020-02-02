//C++ code for Intake in the robot 
//Main objective: 

//Adrian Lam and Dylan Nguyen

#include "intake.h"

void PHHSIntake::suckSpeed(float speed)
{
    m_intakeMotor.Set(speed);

}

void PHHSIntake::lowerIntake(float motorSpeed)
{
    m_indexingMotor.Set(motorSpeed);
}

void PHHSIntake::raiseIntake(float motorSpeed)
{
    m_indexingMotor.Set(motorSpeed);
}


void PHHSIntake::motorInit()
{
    
    m_indexingMotor.SetInverted(false);
    m_intakeMotor.SetInverted(false);

    m_indexingMotor.ConfigForwardLimitSwitchSource(LimitSwitchSource::LimitSwitchSource_FeedbackConnector, LimitSwitchNormal::LimitSwitchNormal_NormallyOpen, 0);
    m_intakeMotor.ConfigReverseLimitSwitchSource(LimitSwitchSource::LimitSwitchSource_FeedbackConnector,LimitSwitchNormal::LimitSwitchNormal_NormallyOpen, 0);

    m_intakeMotor.ConfigPeakCurrentLimit(kPeakCurrentAmp, kPeakTimeMs);
    m_indexingMotor.ConfigPeakCurrentLimit(kPeakCurrentAmp, kPeakTimeMs);

    m_indexingMotor.ConfigContinuousCurrentLimit(kContinCurrentAmps, kTimeoutMs);
    
}; 


