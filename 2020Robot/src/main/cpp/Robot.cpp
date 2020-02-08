/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"
#include "driveControl.h"
#include "DriveBase.h"
#include "intake.h"
#include "autonomous.h"

void Robot::RobotInit() {
    
   intake.robotMotorInit(); 

   intake.motorInit();
} 

void Robot::AutonomousInit() {
    
}
void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {}
void Robot::TeleopPeriodic() {
     
    driveBase.arcadeDriveCalculate(m_stick.GetRawAxis(PHHSDrive::axisForUpDown), m_stick.GetRawAxis(PHHSDrive::axisForLeftRight));
    
    if(m_stick.GetRawButton(PHHSIntake::kDownwardMotorBtn))
    {
        intake.lowerIntake(PHHSIntake::kDownwardMotor);
    }

    if(m_stick.GetRawButton(PHHSIntake::kUpwardMotorBtn))
    {
        intake.raiseIntake(PHHSIntake::kUpwardMotor);
    }

    if(m_stick.GetRawButton(PHHSIntake::kIntakemotorBtn))
    {
        intake.suckSpeed(PHHSIntake::kIntakeMotor);
    }

    if(m_stick.GetRawButton(PHHSIntake::kIntakeMotorOffBtn))
    {
        intake.suckSpeedOff(PHHSIntake::kIntakeMotorOff);
    }

}

void Robot::TestInit() {}
void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif



