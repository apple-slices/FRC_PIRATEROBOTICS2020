#include "Robot.h"

class PHHSSpinner
{

    private:
    const int kSpinnerMotorID = 1;

    const float kSpinnerHoriz = 1.0;

    WPI_TalonSRX m_spinnerMotor{kSpinnerMotorID}; //this is the motor that spins the wheel

    public:
    
    void spinnerOn(float speed);


};