#pragma once
#ifndef SPINNER
#define SPINNER

#include "ctre/Phoenix.h"

class PHHSSpinner
{

    private:
    constexpr static int kSpinnerMotorID = 1;


    WPI_TalonSRX m_spinnerMotor{kSpinnerMotorID}; //this is the motor that spins the wheel

    public:

    constexpr static float kSpinnerHoriz = 1.0;
    constexpr static float kSpinnerHorizOff = 0.0;

    constexpr static int kSpinnerMotorOnBtn = 1; //Button A on Xbox Controller 
    constexpr static int kSpinnerMotorOffBtn = 2; //ButtonB on Xbox 360 Controller

    

    void spinnerOn(float speed);

    void spinnerOff(float speed);


};

#endif 