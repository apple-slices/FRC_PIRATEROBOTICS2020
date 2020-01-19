#include "ctre/Phoenix.h"


class PHHSIntake
{

private:
const int kIntakemotorID = 1;
const int kIndexingMotorID = 2;
const float kDownwardMotor = 1.0;
const float kUpwardMotor = -1.0;
const float kIntakeDown = 1.0;

WPI_TalonSRX m_intakeMotor{kIntakemotorID};
WPI_TalonSRX m_indexingMotor{kIndexingMotorID};

public:

 

void suckSpeed(float speed);
 //Button Hold to move motor down until hit ground 
void lowerIntake(int buttonPress); 
//BUtton Hold to move intake Upwards 
void raiseIntake(int buttonPress);


};