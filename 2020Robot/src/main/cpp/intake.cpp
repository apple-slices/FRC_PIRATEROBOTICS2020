//C++ code for Intake in the robot 
//Main objective: 

//Adrian Lam and Dylan Nguyen

#include "intake.h"

void PHHSIntake::suckSpeed(float speed)
{
    m_intakeMotor.Set(speed);

}

void PHHSIntake::suckSpeedOff(float speed)
{
    m_intakeMotor.Set(speed);
}

void PHHSIntake::lowerIntake(float motorSpeed)
{
    m_intakeheight.Set(motorSpeed);
}

void PHHSIntake::raiseIntake(float motorSpeed)
{
    m_intakeheight.Set(motorSpeed);
}

void PHHSIntake::upTime(int time)
{
    
}

void PHHSIntake::downTime(int time)
{

}

void PHHSIntake::IntakeOff(float motorSpeed)
{
    m_intakeheight.Set(0.0);
}
void PHHSIntake::motorInit()
{
    
    m_intakeheight.SetInverted(false);
    m_intakeMotor.SetInverted(false);

    //Code for the limit switch 
    m_intakeheight.ConfigForwardLimitSwitchSource(LimitSwitchSource::LimitSwitchSource_FeedbackConnector, LimitSwitchNormal::LimitSwitchNormal_NormallyOpen, kTimeoutMs);
    m_intakeMotor.ConfigReverseLimitSwitchSource(LimitSwitchSource::LimitSwitchSource_FeedbackConnector,LimitSwitchNormal::LimitSwitchNormal_NormallyOpen, kTimeoutMs);

    //code for amp limit 
    m_intakeMotor.ConfigPeakCurrentLimit(kPeakCurrentAmpIntake, kPeakTimeMs);
    m_intakeheight.ConfigPeakCurrentLimit(kPeakCurrentAmpIndexing, kPeakTimeMs);

    m_intakeMotor.ConfigPeakCurrentDuration(kPeakTimeMs,kTimeoutMs);
    m_intakeheight.ConfigPeakCurrentDuration(kPeakTimeMs,kTimeoutMs);

    m_intakeheight.EnableCurrentLimit(true);
    m_intakeMotor.EnableCurrentLimit(true);

    m_intakeheight.ConfigContinuousCurrentLimit(kContinCurrentAmps, kTimeoutMs);
    m_intakeMotor.ConfigContinuousCurrentLimit(kContinCurrentAmps, kTimeoutMs);

}





