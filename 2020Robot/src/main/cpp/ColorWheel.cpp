#include "ColorWheel.h"
 
 static constexpr auto i2cPort = frc::I2C::Port::kOnboard;
    rev::ColorSensorV3 m_colorSensor{i2cPort};
    frc::Color detectedColor = m_colorSensor.GetColor();
    PHHSSpinner spinner = PHHSSpinner();
     
   
    void turn2Red() {
      spinner.spinnerOn(PHHSSpinner::kSpinnerHoriz);
      if(detectedColor.red>detectedColor.green  && detectedColor.red>detectedColor.blue){
          spinner.spinnerOff(PHHSSpinner::kSpinnerHorizOff);
      }
    }

    void turn2Blue() {
     spinner.spinnerOn(PHHSSpinner::kSpinnerHoriz);
      if(detectedColor.blue>detectedColor.red  && detectedColor.blue>detectedColor.green){
          spinner.spinnerOff(PHHSSpinner::kSpinnerHorizOff);
      }
    }

void turn2Green(){
    spinner.spinnerOn(PHHSSpinner::kSpinnerHoriz);
    if(detectedColor.green>detectedColor.red  && detectedColor.green>detectedColor.blue){
        spinner.spinnerOff(PHHSSpinner::kSpinnerHorizOff);
    }
}
void turn2Yellow(){
 spinner.spinnerOn(PHHSSpinner::kSpinnerHoriz);
    if(detectedColor.red>detectedColor.blue  && detectedColor.green>detectedColor.blue && abs(detectedColor.red-detectedColor.green)<40){
        spinner.spinnerOff(PHHSSpinner::kSpinnerHorizOff);
    }
}   
    #include <frc/DriverStation.h>

std::string gameData;
gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
if(gameData.length() > 0)
{
  switch (gameData[0])
  {
    case 'B' :
      turn2Blue();
      break;
    case 'G' :
      turn2Green();
      break;
    case 'R' :
      turn2Red();
      break;
    case 'Y' :
      turn2Yellow();
      break;
    default :
      //This is corrupt data
      break;
  }
} else {
  //Code for no data received yet
}

