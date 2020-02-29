
#pragma once

#include "math.h"
#include "rev/CANSparkMax.h"
class PHHSDrive{

    private:
    //General
    const int m_1lMotorFrontNum = 12; //3 and 1 for pathfinder; 
    const int m_2lMotorFrontNum = 13; //13

    const int m_1rMotorFrontNum = 3; //3 and 1 for pathfinder; 
    const int m_2rMotorFrontNum = 1; //1
    const double m_neutral = 0; 
    const float m_error = 0.15;
    double m_correction = ((1.0)/(1.0-m_error));

    double adrianCoefficent = 0.15;

    float tightness = 0.50;

    

    float endValueLeft = 0;
    float endValueRight = 0;


    rev::CANSparkMax* l1MotorFront = new rev::CANSparkMax(m_1lMotorFrontNum, rev::CANSparkMax::MotorType::kBrushless);
    rev::CANSparkMax* r1MotorFront = new rev::CANSparkMax(m_1rMotorFrontNum, rev::CANSparkMax::MotorType::kBrushless);
    rev::CANSparkMax* l2MotorFront = new rev::CANSparkMax(m_2lMotorFrontNum, rev::CANSparkMax::MotorType::kBrushless);
    rev::CANSparkMax* r2MotorFront = new rev::CANSparkMax(m_2rMotorFrontNum, rev::CANSparkMax::MotorType::kBrushless);
    
    //Ramp Piecewise
    float p1_correction = m_error * (0.25);
    float p2_correction = m_error * (2);

    //Ramp Exponetial 

    float m_exponential = m_correction * m_correction; 

    public:
    const static int axisForUpDown = 1; //1 is for joystick left
    const static int axisForLeftRight = 2; //2 is for joystick right

    PHHSDrive();
    void arcadeDrive(float lStick, float rStick);
    void exponentDrive(float lStick, float rStick);
    void pieceWiseDrive(float lStick, float rStick);
    void drive(float lStick, float rStick);
};




