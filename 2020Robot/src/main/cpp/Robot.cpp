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

void Robot::RobotInit() {
    
  //  intake.motorInit();

   intake.MotorDefault();

} 

void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {
    
}
void Robot::TeleopPeriodic() {
     
    driveBase.arcadeDriveCalculate(m_stick.GetRawAxis(PHHSDrive::axisForUpDown), m_stick.GetRawAxis(PHHSDrive::axisForLeftRight));
    
    if(m_stick.GetRawButton(PHHSIntake::kDownwardMotorBtn))
    {
        intake.lowerIntake(PHHSIntake::kDownwardMotor);
        MyTime.Reset();
        MyTime.Start();
    }
    else if(MyTime.Get()>1)
    {
        MyTime.Stop();
        intake.lowerIntake(PHHSIntake::kDownwardMotorOff);
    }
    
    if(m_stick.GetRawButton(PHHSIntake::kUpwardMotorBtn))
    {
        intake.raiseIntake(PHHSIntake::kUpwardMotor);
        MyTime.Reset();
        MyTime.Start();
    }
    else if(MyTime.Get()>1)
    {
        MyTime.Stop();
        intake.raiseIntake(PHHSIntake::kUpwardMotorOff);
    }

    if(m_stick.GetRawButton(PHHSIntake::kIntakemotorBtn))
    {
        intake.suckSpeed(PHHSIntake::kIntakeMotor);
    }
    else//(m_stick.GetRawButton(PHHSIntake::kIntakemotorBtn)) 
    {
        intake.suckSpeedOff(PHHSIntake::kIntakeMotorOff);
    }


}

void Robot::TestInit() {}
void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif



