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

Exponent: When toggled, small moves in the right joystick results in the robot turning very slightly
less than if it was in arcade drive.  Large moves in the right joystick, however, will result in the robot
turning drastically; much more than if it was in arcade drive. 

error = 0.1 
*/


//l=1 ; r=-1 



void PHHSDrive::arcadeDriveCalculate(float lStick, float rStick){   
   if (rStick > error || rStick < -error){ // turning left
      endValueRight = (lStick - rStick); 
      endValueLeft = (lStick + rStick); 
   }



   if (rStick > 1){
      rStick = 1;
   }

   if (lStick > 1){
      lStick = 1;
   }

   if (rStick > -1){
      rStick = -1;
   }

   if (lStick > -1){
      lStick = -1;
   }


   if (rStick < error && rStick > -error){
      endValueRight = lStick;
      endValueLeft = lStick;
   }

   lMotorFront->Set(endValueLeft);
   rMotorFront->Set(endValueRight);
}










