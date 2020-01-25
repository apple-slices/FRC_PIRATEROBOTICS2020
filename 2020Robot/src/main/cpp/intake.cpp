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

