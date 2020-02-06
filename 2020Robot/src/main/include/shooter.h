#include "ctre/Phoenix.h"

class PHHSShooter
{
    private:
    constexpr static int kShooterMotorID = 1;

    WPI_TalonSRX m_shooterMotor{kShooterMotorID};
    
    public:
    
    constexpr static float  kShooterMotor = 1.0;
   
    constexpr static int kShooterMotorOnBtn = 1; //Button A on Xbox 360
    constexpr static int kShooterMotorOffBtn = 2; //Button B on Xbox 360

    void shooterOn(float speed);
    
    void shooterOff(float speed);

};