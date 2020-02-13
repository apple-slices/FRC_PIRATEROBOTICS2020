#include "Robot.h"


#include "Climb.h"

void PHHSClimb::ClimbUp(bool On)
{
    kSolenoid.Set(true);
}

void PHHSClimb::ClimbDown(bool Off)
{
    kSolenoid.Set(false);
}
