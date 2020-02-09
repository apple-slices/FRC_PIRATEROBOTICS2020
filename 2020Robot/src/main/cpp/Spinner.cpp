#include "spinner.h"

void PHHSSpinner::spinnerOn(float speed)
{
    m_spinnerMotor.Set(speed);
}

void PHHSSpinner::spinnerOff(float speed)
{
    m_spinnerMotor.Set(speed);
}

void PHHSSpinner::SpinnerInit()
{
    m_spinnerMotor.ConfigNominalOutputForward( 6, +1); //Remember to change the "+1" to kTimeoutMS

    m_spinnerMotor.ConfigPeakOutputForward( 6, +1); //Remember to change the "+1" to kTimeoutMS


}
