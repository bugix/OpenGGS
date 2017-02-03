#include "globals.h"

// ##############################################
// ##############################################
// ##############################################

void PC_Run()
{
  if(PC.AccellLeft){PC.Direction = PC_LEFT;}
  if(PC.AccellRight){PC.Direction = PC_RIGHT;}

  // START SLOWLY
  if(PC.AccellRight && !PC.AccellLeft){PC.RunVelocity += 1.5*World.Friction;}
  if(PC.AccellLeft &&  !PC.AccellRight){PC.RunVelocity -= 1.5*World.Friction;}
  // START SLOWLY

  // ADDITIONAL ACCELLARATION ONCE PC HAS SOME VELOCITY
  if(PC.AccellRight && !PC.AccellLeft  && PC.RunVelocity > 9){PC.RunVelocity += 0.5*World.Friction;}
  if(PC.AccellLeft &&  !PC.AccellRight && PC.RunVelocity < -9){PC.RunVelocity -= 0.5*World.Friction;}
  // ADDITIONAL ACCELLARATION ONCE PC HAS SOME VELOCITY

  // ALLOW FASTER DIRECTION CHANGES
  if(PC.AccellRight && !PC.AccellLeft  && PC.RunVelocity < 0){PC.RunVelocity += 0.5*World.Friction;}
  if(PC.AccellLeft &&  !PC.AccellRight && PC.RunVelocity > 0){PC.RunVelocity -= 0.5*World.Friction;}
  // ALLOW FASTER DIRECTION CHANGES

  if(PC.RunVelocity < -PC.RunStrength){PC.RunVelocity = -PC.RunStrength;} // MAX SPEED
  if(PC.RunVelocity > PC.RunStrength) {PC.RunVelocity = PC.RunStrength;}  // MAX SPEED
}

// ##############################################
// ##############################################
// ##############################################

void PC_Friction()
{
  //if(PC.AccellRight && !PC.AccellLeft){PC.RunVelocity += World.Friction;}
  //if(PC.AccellLeft && !PC.AccellRight){PC.RunVelocity -= World.Friction;}
  int TempSpeed = 0;

  if((!PC.AccellRight && !PC.AccellLeft) || (PC.AccellRight && PC.AccellLeft))
  {
    if(PC.RunVelocity > 0){PC.RunVelocity -= World.Friction;}
    if(PC.RunVelocity < 0){PC.RunVelocity += World.Friction;}
  }

  if(!GV.PixelPerfectRunning){PC.PosX += int(PC.RunVelocity/4);}

  if(GV.PixelPerfectRunning) // RUNNING RIGHT HAS TO BE PIXEL PERFECT
  {
    if(PC.RunVelocity > 0) // MOVING TO THE RIGHT
    {
      TempSpeed = (int)(PC.RunVelocity/4);
      while(TempSpeed != 0)
      {
        TempSpeed--;
        if(!PC.HitWall){PC_Check_Tilecollision(); PC.PosX++;}
      }
    }
    if(PC.RunVelocity < 0) // MOVING TO THE LEFT
    {
      TempSpeed = (int)(PC.RunVelocity/4);
      while(TempSpeed != 0)
      {
        TempSpeed++;
        if(!PC.HitWall){PC_Check_Tilecollision(); PC.PosX--;}
      }
    }
  }

  if(PC.PosX > StageC64.StageWidthPixels-PC.ColWidthHalf-1){PC.PosX = StageC64.StageWidthPixels-PC.ColWidthHalf-1; PC.RunVelocity = 0;}
  if(PC.PosX < 0){PC.PosX = 0; PC.RunVelocity = 0;}

}

// ##############################################
// ##############################################
// ##############################################
