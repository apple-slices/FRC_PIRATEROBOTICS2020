
#include <frc/PIDController.h>
#include <frc/Ultrasonic.h>
#include <frc/GyroBase.h>
#include <frc/Encoder.h>
using namespace frc;

// move forward in a line
int PIDForward(double distance, double avgV) {
    PIDController controller = PIDController(0, 0, 0, nullptr, nullptr);
    
}

// Turn on the spot
int PIDSpotTurn(double angle, double avgV) {

}
