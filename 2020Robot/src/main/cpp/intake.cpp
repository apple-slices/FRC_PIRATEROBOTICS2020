//C++ code for Intake in the robot 
//Main objective: 

//Adrian Lam and Dylan Nguyen

#include "intake.h"

void PHHSIntake::suckSpeed(float speed)
{
    m_intakeMotor.Set(speed);

}

void PHHSIntake::lowerIntake(int buttonPress)
{
    m_indexingMotor.Set(kDownwardMotor);
}

void PHHSIntake::raiseIntake(int buttonPress)
{
    m_indexingMotor.Set(kUpwardMotor);
}

