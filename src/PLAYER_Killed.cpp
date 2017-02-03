#include "globals.h"

// ##############################################
// ##############################################
// ##############################################

void PC_Killed()
{
  int i;

  PC.gotKilled = false;
  PC.WallGrinding = false;
  PC.Dead = true;
  PC.RunVelocity = 0;
  PC.JumpOnGoing = true;
  PC.OnGround = true;
  PC.Mode = PC_MODE1;
  PC_PowerUp_Set(0);
  PC.SubStageNumber=0;
  PC.JumpStrength = 50;
  PC_Jump();
  PC.Lives -= 1;
  AUDIO_Sound_Play(AUDIO_KILLED);

  for(i=1;i<10;i++)
  {
    Sprite_PowerUp[i].JumpVelocity = 0;
    Sprite_PowerUp[i].RunVelocity = 0;
    Sprite_PowerUp[i].Active = false;
  }
}

// ##############################################
// ##############################################
// ##############################################

void PC_Death_Routine()
{
  int StartPos = 0;
  if(PC.PosX > StageC64.CheckPointX[1]-10){StartPos = 1;}
  if(PC.PosX > StageC64.CheckPointX[2]-10){StartPos = 2;}
  if(PC.PosY > GV.Screen_Height-1){STAGE_Load(PC.Stage, StartPos, true, false);}
}

// ##############################################
// ##############################################
// ##############################################
