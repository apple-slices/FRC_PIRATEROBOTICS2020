

#include "shooter.h"


void PHHSShooter::shooterOn(float speed)
{
    m_shooterMotor.Set(speed);
}

void PHHSShooter::shooterOff(float speed)
{
    m_shooterMotor.Set(speed);
}
