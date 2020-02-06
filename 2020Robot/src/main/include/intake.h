#pragma once 
#ifndef INTAKE
#define INTAKE

#include "ctre/Phoenix.h"


class PHHSIntake
{

private:
//motor IDs
const int kIntakemotorID = 1;
const int kIndexingMotorID = 0;

//Motor Control limits 
const int kPeakCurrentAmpIntake = 40; //Max. before tirggering current limit 
const int kPeakCurrentAmpIndexing = 40; //Max. before tiggering current limit 
const int kContinCurrentAmps = 40; //hold current after limit is tirgged

//Motor Control Time 
const int kTimeoutMs = 0; //How much time to check (if 0 then it will skip the check)
const int kPeakTimeMs = 0; //How long after peak current to stop motors



const float kIntakeDown = 1.0;

WPI_TalonSRX m_intakeMotor{kIntakemotorID};
WPI_TalonSRX m_indexingMotor{kIndexingMotorID};

public:
//motor speed 
constexpr static float kDownwardMotor = 1.0;
constexpr static float kUpwardMotor = -1.0;
constexpr static float kIntakeMotor = 1.0; 
constexpr static float kIntakeMotorOff = 0.0;
//Joystick ID 
constexpr static int kDownwardMotorBtn = 1; //button A on Xbox 360 
constexpr static int kUpwardMotorBtn = 2; //button B on Xbox 360 
constexpr static int kIntakemotorBtn = 3; //Button "X" on the Xbox 360 
constexpr static int kIntakeMotorOffBtn = 4; //Button "Y" on the Xbox 360 

//Button Toggle to turn on Intake Motor
void suckSpeed(float speed);
//Button Toggle to turn off Intake Motor
void suckSpeedOff(float speed);
 //Button Toggle to move motor down until hit ground 
void lowerIntake(float motorSpeed); 
//Button Toggle to move intake system upwards
void raiseIntake(float motorSpeed);


void motorInit();

void robotMotorInit();
};
#endif