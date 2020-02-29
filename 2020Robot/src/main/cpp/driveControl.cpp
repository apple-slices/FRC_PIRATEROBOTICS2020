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
   float endValueLeft = endValueRight = 0;
   
   
   if (abs(rStick) > m_error && abs(lStick) < m_error ){ // turning left or right in place
      endValueLeft = m_correction *(-rStick + m_error); 
      endValueRight =  m_correction *(rStick - m_error);
   }
  
   else if (lStick > m_error && abs(rStick)< m_error){ // forward or back
      endValueRight = m_correction * -1 * (lStick - m_error);
      endValueLeft  = m_correction * -1 * (lStick - m_error);
   }

   else if (lStick < -m_error && abs(rStick)< m_error){ // forward or back
      endValueRight = m_correction * -1 * (lStick + m_error);
      endValueLeft  = m_correction * -1 * (lStick + m_error);
   }

   else if ((lStick > m_error) && (rStick < m_error)){ //turns foward left
      endValueRight  = m_correction * -1 * (lStick - m_error);
      endValueLeft = endValueRight * (1 + rStick); 
   }

   else if ((lStick > m_error) && (rStick > m_error)){ //turns foward right
      endValueLeft  = m_correction * -1 * (lStick - m_error);
      endValueRight = endValueLeft * (1 - rStick); 
   }

   else if ((lStick < -m_error) && (rStick < m_error)){ //turns back left
      endValueRight  = -m_correction * (lStick + m_error);
      endValueLeft = endValueRight * (1 + rStick); 

   }

   else if ((lStick < -m_error) && (rStick > m_error)){ //turns back right
      endValueLeft  = m_correction * -1 * (lStick + m_error);
      endValueRight = endValueLeft * (1 - rStick); 
   }

   l1MotorFront->Set(-endValueLeft);
   r1MotorFront->Set(endValueRight);
}

























void PHHSDrive::exponentDrive(float laStick, float rStick){
   
   float lStick = -laStick;
   float endValueLeft = endValueRight = 0;
   
   
   if (abs(rStick) > m_error && abs(lStick) < m_error ){ // turning left or right in place
      endValueLeft = (m_correction *(-rStick + m_error)) * (m_correction *(-rStick + m_error)); 
      endValueRight =  (m_correction *(rStick - m_error)) * (m_correction *(rStick - m_error));
   }
  
   else if (lStick > m_error && abs(rStick)< m_error){ // forward or back
      endValueRight = -1 * (m_correction  * (lStick - m_error)) *  (m_correction  * (lStick - m_error));
      endValueLeft  = -1 * (m_correction * (lStick - m_error)) *  (m_correction  * (lStick - m_error));
   }

   else if (lStick < -m_error && abs(rStick)< m_error){ // forward or back
      endValueRight =  (m_correction  * (lStick + m_error)) * (m_correction  * (lStick + m_error));
      endValueLeft  =  (m_correction * (lStick + m_error)) * (m_correction * (lStick + m_error));
   }

   else if ((lStick > m_error) && (rStick < m_error)){ //turns foward left
      endValueRight  = m_correction * -1 * (lStick - m_error);
      endValueLeft = endValueRight * (1 + rStick); 
   }

   else if ((lStick > m_error) && (rStick > m_error)){ //turns foward right
      endValueLeft  = m_correction * -1 * (lStick - m_error);
      endValueRight = endValueLeft * (1 - rStick); 
   }

   else if ((lStick < -m_error) && (rStick < m_error)){ //turns back left
      endValueRight  = -m_correction * (lStick + m_error);
      endValueLeft = endValueRight * (1 + rStick); 

   }

   else if ((lStick < -m_error) && (rStick > m_error)){ //turns back right
      endValueLeft  = m_correction * -1 * (lStick + m_error);
      endValueRight = endValueLeft * (1 - rStick); 
   }
   
   l1MotorFront->Set(-endValueLeft);
   r1MotorFront->Set(endValueRight);
}

















void PHHSDrive::pieceWiseDrive(float laStick, float rStick){ 
   
   float lStick = -laStick;
   float endValueLeft = endValueRight = 0;
   
   
   if (abs(rStick) > m_error && abs(lStick) < m_error){ // turning left or right in place
      if(abs(rStick) < 0.25){
         endValueLeft = p1_correction *(-rStick + m_error); 
         endValueRight =  p1_correction *(rStick - m_error);
      }
      else if(abs(rStick) > 0.25){
         endValueLeft = p2_correction *(-rStick + m_error); 
         endValueRight =  p2_correction *(rStick - m_error);
      }
   }
  
   else if (lStick > m_error && abs(rStick)< m_error){ // forward or back
      if(abs(lStick) < 0.25){
         endValueRight = p1_correction * -1 * (lStick - m_error);
         endValueLeft  = p1_correction * -1 * (lStick - m_error);
      }
      else if(abs(lStick) > 0.25){
         endValueRight = p2_correction * -1 * (lStick - m_error);
         endValueLeft  = p2_correction * -1 * (lStick - m_error);
      }     
      
   }

   else if (lStick < -m_error && abs(rStick)< m_error){ // forward or back
      if(abs(lStick) < 0.25){
         endValueRight = p1_correction * -1 * (lStick + m_error);
         endValueLeft  = p1_correction * -1 * (lStick + m_error);
      }
      else if(abs(lStick) > 0.25){
         endValueRight = p2_correction * -1 * (lStick + m_error);
         endValueLeft  = p2_correction * -1 * (lStick + m_error);
      }   
   }

   else if ((lStick > m_error) && (rStick < m_error)){ //turns foward left
      endValueRight  = m_correction * -1 * (lStick - m_error);
      endValueLeft = endValueRight * (1 + rStick); 
   }

   else if ((lStick > m_error) && (rStick > m_error)){ //turns foward right
      endValueLeft  = m_correction * -1 * (lStick - m_error);
      endValueRight = endValueLeft * (1 - rStick); 
   }

   else if ((lStick < -m_error) && (rStick < m_error)){ //turns back left
      endValueRight  = -m_correction * (lStick + m_error);
      endValueLeft = endValueRight * (1 + rStick); 

   }

   else if ((lStick < -m_error) && (rStick > m_error)){ //turns back right
      endValueLeft  = m_correction * -1 * (lStick + m_error);
      endValueRight = endValueLeft * (1 - rStick); 
   }

   l1MotorFront->Set(-endValueLeft);
   r1MotorFront->Set(endValueRight);
}

