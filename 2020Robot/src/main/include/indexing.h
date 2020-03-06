#pragma once 
#ifndef INDEX
#define INDEX

#include <frc2/Timer.h>
#include "ctre/Phoenix.h"

class PHHSIndex
{

private:
//motor IDs
const int kIndexingMotorID = 1;
const int kIndexingMotorID2 = 2;
const int kIndexingMotorID3 = 3;

WPI_VictorSPX m_indexingmotor1{kIndexingMotorID};
WPI_VictorSPX m_indexingmotor2{kIndexingMotorID2};
WPI_VictorSPX m_indexingmotor3{kIndexingMotorID3};

public:

//motor speed
constexpr static float kindexingMotorOn = 0.3;
constexpr static float kindexingMotorOff = 0.0;

//Joystick ID
constexpr static int kIndexingMotorBtn = 4;


void on(float speed);

void off(float speed);



};

#endif