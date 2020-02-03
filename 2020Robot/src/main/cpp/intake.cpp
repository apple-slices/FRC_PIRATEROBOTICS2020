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
    m_indexingMotor.Set(motorSpeed);
}

void PHHSIntake::raiseIntake(float motorSpeed)
{
    m_indexingMotor.Set(motorSpeed);
}

void PHHSIntake::robotMotorInit()
{
    //Change kTimeoutMs if needed to because the docum. says 50
    m_indexingMotor.ConfigFactoryDefault(kTimeoutMs);
    m_intakeMotor.ConfigFactoryDefault(kTimeoutMs);
}


void PHHSIntake::motorInit()
{
    
    m_indexingMotor.SetInverted(false);
    m_intakeMotor.SetInverted(false);

    m_indexingMotor.ConfigForwardLimitSwitchSource(LimitSwitchSource::LimitSwitchSource_FeedbackConnector, LimitSwitchNormal::LimitSwitchNormal_NormallyOpen, kTimeoutMs);
    m_intakeMotor.ConfigReverseLimitSwitchSource(LimitSwitchSource::LimitSwitchSource_FeedbackConnector,LimitSwitchNormal::LimitSwitchNormal_NormallyOpen, kTimeoutMs);

    m_intakeMotor.ConfigPeakCurrentLimit(kPeakCurrentAmp, kPeakTimeMs);
    m_indexingMotor.ConfigPeakCurrentLimit(kPeakCurrentAmp, kPeakTimeMs);

    m_indexingMotor.EnableCurrentLimit(true);
    m_intakeMotor.EnableCurrentLimit(true);


    m_indexingMotor.ConfigContinuousCurrentLimit(kContinCurrentAmps, kTimeoutMs);

    //closed loop to limit amp

   /* m_indexingMotor.SetNeutralMode(NeutralMode::Brake);
    m_intakeMotor.SetNeutralMode(NeutralMode::Brake);

    m_indexingMotor.Config_kP(0, 2.0, 10);
    m_intakeMotor.Config_kP(0, 2.0, 10);

    m_indexingMotor.Config_kI(0, 0.0, 10);
    m_intakeMotor.Config_kI(0, 0.0, 10);

    m_indexingMotor.Config_kD(0, 0.0, 10);
    m_intakeMotor.Config_kD(0, 0.0, 10);

    m_indexingMotor.Config_kF(0, 0.0, 10);
    m_intakeMotor.Config_kF(0, 0.0, 10); */

    
    
}





