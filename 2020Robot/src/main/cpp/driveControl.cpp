/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
//Alan Yu

#include "driveControl.h"
#include "math.h"
PHHSDrive::PHHSDrive() {
   l2MotorFront->Follow(*l1MotorFront, false);
   r2MotorFront->Follow(*r1MotorFront, false);
}
void PHHSDrive::arcadeDrive(float laStick, float rStick){ 
   
   float lStick = -laStick;
   
   if (abs(rStick) > m_error && abs(lStick) < m_error ){ // turning left or right in place
      endValueLeft = m_correction *(-rStick + m_error); 
      endValueRight =  m_correction *(rStick - m_error);
   }
  
   else if (abs(lStick)> m_error && abs(rStick)< m_error){ // forward or back
      endValueRight = m_correction * -1 * (lStick - m_error);
      endValueLeft  = m_correction * -1 * (lStick - m_error);
   }

   else if ((abs(lStick) > m_error) && (rStick > m_error)){ //turns foward right
      endValueRight = m_correction * -1 * (lStick - m_error) - (rStick);
      endValueLeft  = m_correction * -1 * (lStick - m_error);
   }

   else if ((abs(lStick) > m_error) && (-rStick < -m_error)){ //turns foward left
      endValueLeft = ((0.75) * lStick); // decreases speed
      endValueRight = ((0.75) * lStick) + (-1 * adrianCoefficent * rStick); // or increase speed
   }

   else if (abs(lStick) < m_error && abs(rStick) < m_error){
      endValueLeft = endValueRight =0;
   }

//Make sure to change "adrianCoefficient" into an actual name 
 
   l1MotorFront->Set(-endValueLeft);
   r1MotorFront->Set(endValueRight);
}

void PHHSDrive::pieceWiseDrive(float lStick, float rStick){
   endValueLeft = endValueRight =0;

   if (abs(rStick) < 0.4){
      if (abs(rStick) > m_error ){ // turning left or right
         endValueRight =  ((lStick - rStick)-m_error); 
         endValueLeft =   ((lStick + rStick)-m_error);
      }
      else if (abs(lStick)> m_error){ // forward or back
         endValueRight = (lStick - m_error);
         endValueLeft  = (lStick - m_error);
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


   l1MotorFront->Set(endValueLeft);  
   l2MotorFront->Set(endValueLeft);
   r1MotorFront->Set(endValueRight);
   r2MotorFront->Set(endValueRight);
}


void PHHSDrive::exponentDrive(float lStick, float rStick){ 
   endValueLeft = endValueRight =0;
   
   if (abs(rStick) > m_error ){ // turning left or right
      endValueRight = m_exponential * ((lStick - rStick)-m_error); 
      endValueLeft =  m_exponential * ((lStick + rStick)-m_error);
   }
  
   else if (abs(lStick)> m_error){ // forward or back
      endValueRight = m_exponential * (lStick - m_error);
      endValueLeft  = m_exponential * (lStick - m_error);
   }

   l1MotorFront->Set(endValueLeft);  
   l2MotorFront->Set(endValueLeft);
   r1MotorFront->Set(endValueRight);
   r2MotorFront->Set(endValueRight);
}








