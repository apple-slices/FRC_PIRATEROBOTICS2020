/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
//Alan Yu

#include "driveControl.h"
#include "math.h"

void PHHSDrive::arcadeDrive(float lStick, float rStick){ 
   endValueLeft = endValueRight =0;
   
   if (abs(rStick) > m_error ){ // turning left or right
      endValueRight = m_correction * ((lStick - rStick)-m_error); 
      endValueLeft =  m_correction * ((lStick + rStick)-m_error);
   }
  
   else if (abs(lStick)> m_error){ // forward or back
      endValueRight = m_correction * (lStick - m_error);
      endValueLeft  = m_correction * (lStick - m_error);
   }



   lMotorFront->Set(endValueLeft);
   rMotorFront->Set(endValueRight);
}

void PHHSDrive::pieceWiseDrive(float lStick, float rStick){
   endValueLeft = endValueRight =0;

   if (abs(rStick) < 0.4){
      if (abs(rStick) > m_error ){ // turning left or right
         endValueRight = p1_correction * ((lStick - rStick)-m_error); 
         endValueLeft =  p1_correction * ((lStick + rStick)-m_error);
      }
      else if (abs(lStick)> m_error){ // forward or back
         endValueRight = p2_correction * (lStick - m_error);
         endValueLeft  = p2_correction * (lStick - m_error);
      }
   }

   else if (abs(rStick) > 0.4){
      if (abs(rStick) > m_error ){ // turning left or right
         endValueRight = m_correction * ((lStick - rStick)-m_error); 
         endValueLeft =  m_correction * ((lStick + rStick)-m_error);
      }
      else if (abs(lStick)> m_error){ // forward or back
         endValueRight = m_correction * (lStick - m_error);
         endValueLeft  = m_correction * (lStick - m_error);
      }
   }
   lMotorFront->Set(endValueLeft);
   rMotorFront->Set(endValueRight);
}


void PHHSDrive::exponentDrive(float lStick, float rStick){ 
   endValueLeft = endValueRight =0;
   
   if (abs(rStick) > m_error ){ // turning left or right
      endValueRight = m_correction * ((lStick - rStick)-m_error); 
      endValueLeft =  m_correction * ((lStick + rStick)-m_error);
   }
  
   else if (abs(lStick)> m_error){ // forward or back
      endValueRight = m_correction * (lStick - m_error);
      endValueLeft  = m_correction * (lStick - m_error);
   }
   lMotorFront->Set(endValueLeft);
   rMotorFront->Set(endValueRight);
}






