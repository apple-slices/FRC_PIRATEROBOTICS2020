#pragma once 
#ifdef CLIMB

#include "Compressor.h"
#include "Solenoid.h"

class PHHSClimb
{
    private:
    //Solenoid 

    Compressor* pCompressor;

    Solenoid* pSoldenoid;


    public:

    Climb();
    ~Climb();

    void climbUp();

    void climbDown();



};

#endif
