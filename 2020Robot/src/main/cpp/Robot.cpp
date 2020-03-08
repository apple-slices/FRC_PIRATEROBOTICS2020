/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"
#include "DriveBase.h"
#include "intake.h"
#include "climb.h"

void Robot::RobotInit() {
    
   intake.robotMotorInit(); 

   //initialize solenoid
    m_solenoid = new frc::Solenoid(2,4); 
}

void Robot::AutonomousInit() {}
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

    if(m_stick.GetRawButton(PHHSClimb::kClimbUpBtn))
    {
        climb.ClimbUp(m_solenoid);
    }

    if(m_stick.GetRawButton(PHHSClimb::kClimbDownBtn))
    {
        climb.ClimbDown(m_solenoid);
    }

   
} 

void Robot::TestInit() {}
void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif



