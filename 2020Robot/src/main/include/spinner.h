#ifndef SPINNER
#define SPINNER

#include "ctre/Phoenix.h"

class PHHSSpinner
{

    private:
    constexpr static int kSpinnerMotorID = 1;


    WPI_TalonSRX m_spinnerMotor{kSpinnerMotorID}; //this is the motor that spins the wheel

    public:

    const float kSpinnerHoriz = 1.0;

    constexpr static int kSpinnerMotorOnBtn = 1; //Button A on Xbox Controller 

    

    void spinnerOn(float speed);


};

#endif 