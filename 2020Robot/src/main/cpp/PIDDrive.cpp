#include <frc/PIDController.h>
#include <chrono>

#include <frc/PIDSource.h>
#include <frc/Ultrasonic.h>
#include <frc/ADXRS450_Gyro.h>
#include <frc/Encoder.h>

#include <frc/PIDOutput.h>
#include <frc/PWMSparkMax.h>

using namespace frc;

// move forward in a line
int PIDForward(double distance) {
    // static objects to be reused
    // 0's as temporary placeholder
    static Encoder wheelEncoder = Encoder(0, 0);
    static PWMSparkMax wheelController = PWMSparkMax(0);
    static PIDController controller = PIDController(0, 0, 0, (PIDSource &) wheelEncoder, (PIDOutput &) wheelController);
    
    // reset encoder on first run
    static bool firstRun = true;
    if (firstRun) {
        wheelEncoder.Reset();
        firstRun = false;
    }

    controller.SetSetpoint(distance);
}

// Turn on the spot
int PIDSpotTurn(double angle) {
    // static objects to be reused
    // 0's as temporary placeholder
    static ADXRS450_Gyro gyro = ADXRS450_Gyro();
    static PWMSparkMax wheelController = PWMSparkMax(0);
    static PIDController controller = PIDController(0, 0, 0, (PIDSource &) gyro, (PIDOutput &) wheelController);
    
    // reset gyro on first run
    static bool firstRun = true;
    if (firstRun) {
        gyro.Reset();
        firstRun = false;
    }

    controller.SetSetpoint(angle);
}
