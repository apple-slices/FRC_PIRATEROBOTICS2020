#pragma once 
#ifndef SHOOTER
#define SHOOTER

#include "ctre/Phoenix.h"


class PHHSShooter
{

private:
//motor IDs
const int kShooterMotorID = 2;

WPI_TalonSRX m_shooterMotor{kShooterMotorID};

public:
//motor speed 
constexpr static float kShooterMotor = 1.0;
constexpr static float kShooterMotorOff = 0.0;
//Joystick ID 
constexpr static int kShooterMotorOnBtn = 1;
constexpr static int kShooterMotorOffBtn = 2;


void shooterOn(float speed);

void shooterOff(float speed);

};
#endif



