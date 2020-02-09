/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"
#include "rev/ColorSensorV3.h"
#include <frc/smartdashboard/smartdashboard.h>
#include "ColorWheel.h"

rev::ColorSensorV3 m_colorSensor{ frc::I2C::Port::kOnboard};
#include "spinner.cpp"

void Robot::RobotInit() {}

void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {
    
}

void Robot::TeleopInit() {}
void Robot::TeleopPeriodic() {
        if(m_stick.GetRawButton(PHHSSpinner::kSpinnerMotorOnBtn))
        {
            spinner.spinnerOn(PHHSSpinner::kSpinnerHoriz);
        }

        if(m_stick.GetRawButton(PHHSSpinner::kSpinnerMotorOffBtn))
        {
            spinner.spinnerOff(PHHSSpinner::kSpinnerHorizOff);
        }

        turn2Red();
    
}

void Robot::TestInit() {}
void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
