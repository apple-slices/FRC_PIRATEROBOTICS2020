
#ifndef INTAKE
#define INTAKE

#include "ctre/Phoenix.h"


class PHHSIntake
{

private:
//motor IDs
const int kIntakemotorID = 8;
const int kIndexingMotorID = 20;

//Motor Control limits 
const int kPeakCurrentAmp = 15;
const int kPeakTimeMs = 0;
const int kContinCurrentAmps = 10;
const int kTimeoutMs = 0;



const float kIntakeDown = 1.0;

WPI_TalonSRX m_intakeMotor{kIntakemotorID};
WPI_TalonSRX m_indexingMotor{kIndexingMotorID};

public:
constexpr static float kDownwardMotor = 1.0;
constexpr static float kUpwardMotor = -1.0;

constexpr static int kDownwardMotorBtn = 1; //button A on Xbox 360 
constexpr static int kUpwardMotorBtn = 2; //button B on Xbox 360 

void suckSpeed(float speed);
 //Button Hold to move motor down until hit ground 
void lowerIntake(float motorSpeed); 
//Button Hold to move intake system upwards
void raiseIntake(float motorSpeed);


void motorInit();
};
#endif