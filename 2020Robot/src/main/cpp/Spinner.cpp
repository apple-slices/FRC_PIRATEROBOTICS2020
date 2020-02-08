#include "spinner.h"

void PHHSSpinner::spinnerOn(float speed)
{
    m_spinnerMotor.Set(speed);
}

void PHHSSpinner::spinnerOff(float speed)
{
    m_spinnerMotor.Set(speed);
}
