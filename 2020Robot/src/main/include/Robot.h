/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

//WPILib includes
#include <frc/TimedRobot.h>
#include <frc/Joystick.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/smartdashboard/smartdashboard.h>
#include <frc/util/color.h>

//Rev robotics includes
#include "rev/ColorSensorV3.h"
#include "rev/ColorMatch.h"
#include "rev/CANSparkMax.h"

//CTRE includes
#include "ctre/Phoenix.h"
#include "Shooter.h"

//PHHS includes
#include <chrono>

class Robot : public frc::TimedRobot
{
private:
  frc::Joystick m_stick{0};
  Shooter shooter;

public:
  void RobotInit() override;
  
  void AutonomousInit() override;
  void AutonomousPeriodic() override;

  void TeleopInit() override;
  void TeleopPeriodic() override;

  void TestInit() override;
  void TestPeriodic() override;
};
