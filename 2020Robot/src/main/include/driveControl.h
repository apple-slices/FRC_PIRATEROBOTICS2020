#pragma once

#include "Robot.h"
#include "math.h"

class PHHSDrive{

    private:

    //General
    const int lMotorFrontNum = 3;
    const int rMotorFrontNum = 13;
    const double neutral = 0; 
    const float error = 0.1;
    double correction = ((1)/(1-error));

    float endValueLeft = 0;
    float endValueRight = 0;

    //Exponent 
    
    

    
    rev::CANSparkMax * lMotorFront = new rev::CANSparkMax(lMotorFrontNum, rev::CANSparkMax::MotorType::kBrushless);
    rev::CANSparkMax * rMotorFront = new rev::CANSparkMax(rMotorFrontNum, rev::CANSparkMax::MotorType::kBrushless);
    public:


    const static int axisForUpDown = 4; //1 is for joystick left
    const static int axisForLeftRight = 1; //2 is for joystick right

    void arcadeDriveCalculate(float lStick, float rStick);
    void exponentDrive(float lStick, float rStick);
    void drive(float lStick, float rStick);
};




