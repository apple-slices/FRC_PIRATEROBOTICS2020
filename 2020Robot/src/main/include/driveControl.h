#pragma once

#include "Robot.h"

class PHHSDrive{

    private:
    const int lMotorFrontNum = 2;
    const int rMotorFrontNum = 4;
    const int axisForUpDown = 1; //1 is for joystick left
    const int axisForLeftRight = 2; //2 is for joystick right
    const double neutral = 0; 
    const int error = 0.1;
    double correction = ((1-error)/1);

    
    rev::CANSparkMax * lMotorFront = new rev::CANSparkMax(lMotorFrontNum, rev::CANSparkMax::MotorType::kBrushless);
    rev::CANSparkMax * rMotorFront = new rev::CANSparkMax(rMotorFrontNum, rev::CANSparkMax::MotorType::kBrushless);
    public:

    void arcadeDrive(float lStick, float rStick);
};




