#pragma once 
#ifndef SHOOTER 

#include "ctre/Phoenix.h"

class PHHSShooter
{

private:
//motor ID
const int kShootermotorID = 1;

WPI_TalonSRX m_shooterMotor{kShootermotorID};


public:
//motor speed 
constexpr static float kShooterMotor = 1.0;
constexpr static float kShooterMotorOff = 0.0;
//Joystick ID 
constexpr static int kShooterMotorOnBtn = 1; //button A on Xbox 360 
constexpr static int kShooterMotorOffBtn = 2; //Button B on Xbox 360 controller


void shooterOn(float speed);

void shooterOff(float speed);

};
#endif

