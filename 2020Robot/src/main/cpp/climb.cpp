#include "Robot.h"


#include "Climb.h"

void PHHSClimb:: ClimbUp(frc::Solenoid* solenoid)
{
    solenoid->Set(true);
}

void PHHSClimb::ClimbDown(frc::Solenoid* solenoid)
{
    solenoid->Set(false);
}
