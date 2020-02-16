#include "Robot.h"


#include "Climb.h"

void PHHSClimb:: ClimbUp(bool)
{
    kSolenoid.Set(true);
}

void PHHSClimb::ClimbDown(bool)
{
    kSolenoid.Set(false);
}
