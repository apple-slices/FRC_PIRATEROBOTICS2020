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


void PHHSIntake::IntakeOff(float motorSpeed)
{
    m_intakeheight.Set(0.0);
}


void PHHSIntake::MotorDefault()
{
    m_intakeheight.ConfigFactoryDefault(kTimeoutMs);
    m_intakeMotor.ConfigFactoryDefault(kTimeoutMs);
}





