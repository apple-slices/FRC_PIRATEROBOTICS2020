#include "ColorWheel.h"
void turn2Red()
{
    static constexpr auto i2cPort = frc::I2C::Port::kOnboard;
    rev::ColorSensorV3 m_colorSensor{i2cPort};
  //  uint32_t proximity = m_colorSensor.GetProximity();
    frc::Color detectedColor = m_colorSensor.GetColor();
  //  double IR = m_colorSensor.GetIR();

    if(detectedColor.red>detectedColor.green  && detectedColor.red>detectedColor.blue){
        // spinner.spinnerOn(PHHSSpinner::kSpinnerHoriz);
    }
    else {
          //spinner.spinnerOff(PHHSSpinner::kSpinnerHorizOff);
    }
}
