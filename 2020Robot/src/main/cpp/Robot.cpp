/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

//Adrian Lam


#include "Robot.h"

void Robot::RobotInit() {}

void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {
    shooter.setSpeed(5.0);
    shooter.display();
}
void Robot::TeleopPeriodic() 
{
    shooter.read();
    if(m_stick.GetRawButton(Shooter::onBtnID))
    {
        frc::SmartDashboard::PutString("Joystick", "on");
        shooter.shooterOn();
    } else {
        frc::SmartDashboard::PutString("Joystick", "off");
        shooter.shooterOff();
    }
}

void Robot::TestInit() {}
void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
