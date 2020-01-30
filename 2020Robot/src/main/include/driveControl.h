
#pragma once

#include "math.h"
#include "rev/CANSparkMax.h"
class PHHSDrive{

    private:
    //General
    const int m_lMotorFrontNum = 3;
    const int m_rMotorFrontNum = 13;
    const double m_neutral = 0; 
    const float m_error = 0.2;
    double m_correction = ((1.0)/(1.0-m_error));

    float endValueLeft = 0;
    float endValueRight = 0;

    rev::CANSparkMax * lMotorFront = new rev::CANSparkMax(m_lMotorFrontNum, rev::CANSparkMax::MotorType::kBrushless);
    rev::CANSparkMax * rMotorFront = new rev::CANSparkMax(m_rMotorFrontNum, rev::CANSparkMax::MotorType::kBrushless);
    
    //PieceWise 
    const float p1_correction = m_error * (0.5);
    const float p2_correction = m_error * (1.5);

    //Exponent


    public:
    const static int axisForUpDown = 4; //1 is for joystick left
    const static int axisForLeftRight = 1; //2 is for joystick right

    void arcadeDrive(float lStick, float rStick);
    void exponentDrive(float lStick, float rStick);
    void pieceWiseDrive(float lStick, float rStick);
    void drive(float lStick, float rStick);
};




