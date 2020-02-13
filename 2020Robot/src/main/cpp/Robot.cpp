/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"
#include "driveControl.h"
#include "DriveBase.h"
#include "PIDDrive.h"

PIDDrive pid;

void Robot::RobotInit() {}

void Robot::AutonomousInit() {
}
void Robot::AutonomousPeriodic() {
    pid.drive(5.0, pid.encoder1, pid.encoder2, pid.lMotorFront, pid.rMotorFront, true);
}

void Robot::TeleopInit() {}
void Robot::TeleopPeriodic() {
    
    
    //driveBase.arcadeDriveCalculate(m_stick.GetRawAxis(PHHSDrive::axisForUpDown), m_stick.GetRawAxis(PHHSDrive::axisForLeftRight));
}

void Robot::TestInit() {}
void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif



