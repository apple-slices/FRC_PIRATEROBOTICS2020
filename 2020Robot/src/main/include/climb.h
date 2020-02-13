#pragma once 
#ifndef CLIMB
#define CLIMB

#include <Solenoid.h>



class PHHSClimb
{
    private:
    //Single Solenoid
    constexpr static int kSolenoid = 1; 
    
    
    
    public:
    
    //Button to raise and lower the climb 
    constexpr static int kClimbUpBtn = 2;
    constexpr static int kClimbDownBtn = 3;

    //Buttons to turn on and off the compressor
    constexpr static int kCompressorOnBtn = 5; 
    constexpr static int kCompressorOffBtn = 6;

    bool kUp = true;
    bool kDown = false;

    bool kOn = true;
    bool kOff = false;

    void ClimbUp(bool On);
    void ClimbDown(bool Off);

    void CompressorOn(bool);
    void CompressorOff(bool);



};

#endif
