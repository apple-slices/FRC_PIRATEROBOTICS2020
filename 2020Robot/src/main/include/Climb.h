#pragma once 
#ifndef CLIMB
#define CLIMB

#include "Solenoid.h"



class PHHSClimb
{
    private:
    //Single Solenoid
    constexpr static int kSolenoid = 1; 

    
    
    public:
    
    //Button to raise and lower the climb 
    constexpr static int kClimbUpBtn = 2;
    constexpr static int kClimbDownBtn = 3;

    bool  kUp = true;
    bool  kDown = false;

    void ClimbUp(bool);

    void ClimbDown(bool);



};

#endif
