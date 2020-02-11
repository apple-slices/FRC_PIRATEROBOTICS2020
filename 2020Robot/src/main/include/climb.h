#pragma once 
#ifndef CLIMB
#define CLIMB

#include "Compressor.h"
#include "Solenoid.h"

class PHHSClimb
{
    private:
    //Single Solenoid
    constexpr static int kSolenoidUp = 1; 
    constexpr static int kSolenoidDown = 2;



    public:
    //Button to raise and lower the climb 
    constexpr static int kClimbUpBtn = 1;
    constexpr static int kClimbDownBtn = 2;


    



};

#endif
