/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
//Alan Yu


#include "Robot.h"
#include "driveControl.h"
/*


arcadeDrive: Linear turn from |0.1| to Full

Exponent: When toggled, small varaitons result in the robot turning very slightly, less than the 

*/




void PHHSDrive::arcadeDrive(float lStick, float rStick){   


   if (rStick > error){
      lMotorFront->Set(lStick);
      rMotorFront->Set(lStick - correction * rStick);
   }

   if (rStick < -error){
      lMotorFront->Set(lStick + correction * rStick);
      rMotorFront->Set(lStick);
   }

   if ((rStick < error) && (rStick > -error)){
      lMotorFront->Set(lStick);
      rMotorFront->Set(lStick);
   }
}
















































































