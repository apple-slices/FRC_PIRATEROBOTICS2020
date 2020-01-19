/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
//Alan Yu


#include "Robot.h"
#include "driveControl.h"
#include "math.h"
/*


arcadeDrive: Linear turn from |0.1| to Full

Exponent: When toggled, small moves in the right joystick results in the robot turning very slightly
less than if it was in arcade drive.  Large moves in the right joystick, however, will result in the robot
turning drastically; much more than if it was in arcade drive. 

error = 0.1 
*/


//l=1 ; r=-1 



void PHHSDrive::arcadeDriveCalculate(float lStick, float rStick){ 
   endValueLeft = endValueRight =0;
   if (abs(rStick) > error ){ // turning left
      endValueRight =((((1.0)/(1.0-error))*(lStick - rStick))-error); 
      endValueLeft = ((((1.0)/(1.0-error))*(lStick + rStick))-error); 
   }
   else if (abs(lStick)>error){
      endValueRight = ((((1.0)/(1.0-error))*lStick)-error);
      endValueLeft = ((((1.0)/(1.0-error))*lStick)-error);
   }

   lMotorFront->Set(endValueLeft);
   rMotorFront->Set(endValueRight);
}










