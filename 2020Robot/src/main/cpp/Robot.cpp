/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

//Jason

//Alan Yu

//Dylan Nguyen

#include "Robot.h"
#include "rev/ColorSensorV3.h"
#include <frc/smartdashboard/smartdashboard.h>

rev::ColorSensorV3 m_colorSensor{ frc::I2C::Port::kOnboard};

void Robot::RobotInit() {}

void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {}
void Robot::TeleopPeriodic() {
    frc::Color detectedColor = m_colorSensor.GetColor();

    /**
     * The sensor returns a raw IR value of the infrared light detected.
     */
    double IR = m_colorSensor.GetIR();

    /**
     * Open Smart Dashboard or Shuffleboard to see the color detected by the 
     * sensor.
     */
    frc::SmartDashboard::PutNumber("Red", detectedColor.red);
    frc::SmartDashboard::PutNumber("Green", detectedColor.green);
    frc::SmartDashboard::PutNumber("Blue", detectedColor.blue);
    frc::SmartDashboard::PutNumber("IR", IR);
    if(detectColor.red>detectColor.green  && detectColor.red>detectColor.blue){
         spinner.spinnerOn(PHHSSpinner::kSpinnerHoriz);
    }
    else {
          spinner.spinnerOff(PHHSSpinner::kSpinnerHorizOff);
    }
    /**
     * In addition to RGB IR values, the color sensor can also return an 
     * infrared proximity value. The chip contains an IR led which will emit
     * IR pulses and measure the intensity of the return. When an object is 
     * close the value of the proximity will be large (max 2047 with default
     * settings) and will approach zero when the object is far away.
     * 
     * Proximity can be used to roughly approximate the distance of an object
     * or provide a threshold for when an object is close enough to provide
     * accurate color values.
     */
    uint32_t proximity = m_colorSensor.GetProximity();

    frc::SmartDashboard::PutNumber("Proximity", proximity);
}

void Robot::TestInit() {}
void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
