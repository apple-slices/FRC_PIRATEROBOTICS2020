#ifndef SPINNER
#define SPINNER

#include "ctre/Phoenix.h"

class PHHSSpinner
{

    private:
    const int kSpinnerMotorID = 1;

    

    WPI_TalonSRX m_spinnerMotor{kSpinnerMotorID}; //this is the motor that spins the wheel

    public:

    const float kSpinnerHoriz = 1.0;

    const int kSpinOn = 

    void spinnerOn(float speed);


};

#endif 