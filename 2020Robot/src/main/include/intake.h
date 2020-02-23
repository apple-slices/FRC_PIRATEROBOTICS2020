#pragma once 
#ifndef INTAKE
#define INTAKE

#include "ctre/Phoenix.h"


class PHHSIntake
{

private:
//motor IDs
const int kIntakeHID = 0;
const int kIntakeMotorID = 2;

//Motor Control limits 
const int kPeakCurrentAmpIntake = 25; //Max. before tirggering current limit 
const int kPeakCurrentAmpIndexing = 25; //Max. before tiggering current limit 
const float kContinCurrentAmps = 0.0; //hold current after limit is tirgged


//Motor Control Time 
const int kTimeoutMs = 5; //How much time to check (if 0 then it will skip the check)
const int kPeakTimeMs = 0; //How long after peak current to stop motors



//const float kIntakeDown = 1.0;

WPI_TalonSRX m_intakeheight{kIntakeHID};
WPI_VictorSPX m_intakeMotor{kIntakeMotorID};

public:
//motor speed 
constexpr static float kIntakeMotorOff = 0.0;
constexpr static float kIntakeMotor = 1.0;
constexpr static float kDownwardMotor = 1.0; 
constexpr static float kUpwardMotor = -1.0;
//Joystick ID 
constexpr static int kUpwardMotorBtn = 1; //button A on Xbox 360 
constexpr static int kDownwardMotorBtn = 2; //button B on Xbox 360 
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
//Time to raise the intake up 
void upTime(int time);
//Time to lower the intake down 
void downTime(int time);
//Intake motor off
void IntakeOff(float motorSpeed);


void motorInit();

void robotMotorInit();
};
#endif