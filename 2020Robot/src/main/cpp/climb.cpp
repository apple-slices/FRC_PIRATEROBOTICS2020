#include "climb.h"

void PHHSClimb::climbOn(float speed)
{
    m_climbMotor.Set(speed);
}

void PHHSClimb::climbOff(float speed)
{
    m_climbMotor.Set(speed);
}