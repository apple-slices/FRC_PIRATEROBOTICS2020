#pragma once 
#ifndef SHOOTER
#define SHOOTER

#include "ctre/Phoenix.h"


class PHHSShooter
{

private:
//motor IDs
const int kShooterMotor1ID = 2;
const int kShooterMotor2ID = 3;

WPI_TalonSRX m_shooterMotor{kShooterMotor1ID && kShooterMotor2};



public:
//motor speed 
constexpr static float kShooterMotor1 = 1.0;
constexpr static float kShooterMotor2 = -1.0;
constexpr static float kShooterMotorOff = 0.0;
//Joystick ID 
constexpr static int kShooterMotorOnBtn = 1;
constexpr static int kShooterMotorOffBtn = 2;


void shooterOn(float speed);

void shooterOff(float speed);

};
#endif



