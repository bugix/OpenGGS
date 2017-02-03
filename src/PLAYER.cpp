#include "globals.h"

PC_Type PC;

// ##############################################
// ##############################################
// ##############################################

void PC_Define()
{
  PC.PosX = 100;
  PC.PosY = 300;
  PC.JumpStrength = 24;
  PC.OnGround = true;
  PC.OnGroundDelayMax = 80;  // MILISECONDS PLAYER CAN STILL JUMP AFTER WALKING OFF A CLIFF (USEFULL FOR "STAIRS")
  PC.OnGroundDelay = 0;
  PC.HitWall = true;
  PC.JumpOnGoing = false;
  PC.AccellLeft = false;
  PC.AccellRight = false;
  PC.RunStrength = 25;
  PC.RunVelocity = 0;
  PC.ShowBorder = false;
  PC.Dead = false;
  PC.gotKilled = false;
  PC.SubStageEntryStage = 0;
  PC.SubStageNumber = 0;
  PC.GodMode = false;
  PC.TargetEnemy = 0;
  PC.MorphingCounter = 0;
  PC.Lives = 10;
  PC.Points = 0;

  PC.ColWidth = 28;
  PC.ColHeight = 42;
  PC.ColWidthHalf = PC.ColWidth/2;
  PC.ColWidthQuart = PC.ColWidth/4;
  PC.ColHeightHalf = PC.ColHeight/2;
  PC.ColHeightQuart = PC.ColHeight/4;
  PC.ColHeight = PC.ColHeight;

  PC.Stage = 1;
  PC.Coins = 0;
  PC_PowerUp_Set(0);

  PC.Mode = PC_MODE1;
  PC.Stance = PC_STAND;
  PC.Direction = PC_RIGHT;
  PC.Animation = 1;
  PC.WarpCounter = 0;

  // LOADING PLAYER DIMENSIONS
  int x;
  FILE* stagefile;
  Uint32 temparray[92];
  stagefile = fopen(FileName.PlayerDefinition,  "r");
  if (stagefile == NULL)
  {
    fprintf(stderr,"PLAYER DIMENSIONS NOT FOUND!!!");
  }
  else
  {
    for (x = 0; x < 92; x++){fscanf(stagefile, "%i,", &temparray[x]);}
    x = 0;
    PC.FrameX[PC_RIGHT][PC_STAND][PC_MODE1] = temparray[x]; x++;
    PC.FrameY[PC_RIGHT][PC_STAND][PC_MODE1] = temparray[x]; x++;
    PC.FrameW[PC_RIGHT][PC_STAND][PC_MODE1] = temparray[x]; x++;
    PC.FrameH[PC_RIGHT][PC_STAND][PC_MODE1] = temparray[x]; x++;

    PC.FrameX[PC_RIGHT][PC_WALK1][PC_MODE1] = temparray[x]; x++;
    PC.FrameY[PC_RIGHT][PC_WALK1][PC_MODE1] = temparray[x]; x++;
    PC.FrameW[PC_RIGHT][PC_WALK1][PC_MODE1] = temparray[x]; x++;
    PC.FrameH[PC_RIGHT][PC_WALK1][PC_MODE1] = temparray[x]; x++;

    PC.FrameX[PC_RIGHT][PC_WALK2][PC_MODE1] = temparray[x]; x++;
    PC.FrameY[PC_RIGHT][PC_WALK2][PC_MODE1] = temparray[x]; x++;
    PC.FrameW[PC_RIGHT][PC_WALK2][PC_MODE1] = temparray[x]; x++;
    PC.FrameH[PC_RIGHT][PC_WALK2][PC_MODE1] = temparray[x]; x++;

  PC.FrameX[PC_RIGHT][PC_JUMP][PC_MODE1] = temparray[x]; x++;
  PC.FrameY[PC_RIGHT][PC_JUMP][PC_MODE1] = temparray[x]; x++;
  PC.FrameW[PC_RIGHT][PC_JUMP][PC_MODE1] = temparray[x]; x++;
  PC.FrameH[PC_RIGHT][PC_JUMP][PC_MODE1] = temparray[x]; x++;

  PC.FrameX[PC_RIGHT][PC_TURN][PC_MODE1] = temparray[x]; x++;
  PC.FrameY[PC_RIGHT][PC_TURN][PC_MODE1] = temparray[x]; x++;
  PC.FrameW[PC_RIGHT][PC_TURN][PC_MODE1] = temparray[x]; x++;
  PC.FrameH[PC_RIGHT][PC_TURN][PC_MODE1] = temparray[x]; x++;

  PC.FrameX[PC_LEFT][PC_STAND][PC_MODE1] = temparray[x]; x++;
  PC.FrameY[PC_LEFT][PC_STAND][PC_MODE1] = temparray[x]; x++;
  PC.FrameW[PC_LEFT][PC_STAND][PC_MODE1] = temparray[x]; x++;
  PC.FrameH[PC_LEFT][PC_STAND][PC_MODE1] = temparray[x]; x++;

  PC.FrameX[PC_LEFT][PC_WALK1][PC_MODE1] = temparray[x]; x++;
  PC.FrameY[PC_LEFT][PC_WALK1][PC_MODE1] = temparray[x]; x++;
  PC.FrameW[PC_LEFT][PC_WALK1][PC_MODE1] = temparray[x]; x++;
  PC.FrameH[PC_LEFT][PC_WALK1][PC_MODE1] = temparray[x]; x++;

  PC.FrameX[PC_LEFT][PC_WALK2][PC_MODE1] = temparray[x]; x++;
  PC.FrameY[PC_LEFT][PC_WALK2][PC_MODE1] = temparray[x]; x++;
  PC.FrameW[PC_LEFT][PC_WALK2][PC_MODE1] = temparray[x]; x++;
  PC.FrameH[PC_LEFT][PC_WALK2][PC_MODE1] = temparray[x]; x++;

  PC.FrameX[PC_LEFT][PC_JUMP][PC_MODE1] = temparray[x]; x++;
  PC.FrameY[PC_LEFT][PC_JUMP][PC_MODE1] = temparray[x]; x++;
  PC.FrameW[PC_LEFT][PC_JUMP][PC_MODE1] = temparray[x]; x++;
  PC.FrameH[PC_LEFT][PC_JUMP][PC_MODE1] = temparray[x]; x++;

  PC.FrameX[PC_LEFT][PC_TURN][PC_MODE1] = temparray[x]; x++;
  PC.FrameY[PC_LEFT][PC_TURN][PC_MODE1] = temparray[x]; x++;
  PC.FrameW[PC_LEFT][PC_TURN][PC_MODE1] = temparray[x]; x++;
  PC.FrameH[PC_LEFT][PC_TURN][PC_MODE1] = temparray[x]; x++;

  PC.FrameX[PC_RIGHT][PC_STAND][PC_MODE2] = temparray[x]; x++;
  PC.FrameY[PC_RIGHT][PC_STAND][PC_MODE2] = temparray[x]; x++;
  PC.FrameW[PC_RIGHT][PC_STAND][PC_MODE2] = temparray[x]; x++;
  PC.FrameH[PC_RIGHT][PC_STAND][PC_MODE2] = temparray[x]; x++;

  PC.FrameX[PC_RIGHT][PC_WALK1][PC_MODE2] = temparray[x]; x++;
  PC.FrameY[PC_RIGHT][PC_WALK1][PC_MODE2] = temparray[x]; x++;
  PC.FrameW[PC_RIGHT][PC_WALK1][PC_MODE2] = temparray[x]; x++;
  PC.FrameH[PC_RIGHT][PC_WALK1][PC_MODE2] = temparray[x]; x++;

  PC.FrameX[PC_RIGHT][PC_WALK2][PC_MODE2] = temparray[x]; x++;
  PC.FrameY[PC_RIGHT][PC_WALK2][PC_MODE2] = temparray[x]; x++;
  PC.FrameW[PC_RIGHT][PC_WALK2][PC_MODE2] = temparray[x]; x++;
  PC.FrameH[PC_RIGHT][PC_WALK2][PC_MODE2] = temparray[x]; x++;

  PC.FrameX[PC_RIGHT][PC_JUMP][PC_MODE2] = temparray[x]; x++;
  PC.FrameY[PC_RIGHT][PC_JUMP][PC_MODE2] = temparray[x]; x++;
  PC.FrameW[PC_RIGHT][PC_JUMP][PC_MODE2] = temparray[x]; x++;
  PC.FrameH[PC_RIGHT][PC_JUMP][PC_MODE2] = temparray[x]; x++;

  PC.FrameX[PC_RIGHT][PC_TURN][PC_MODE2] = temparray[x]; x++;
  PC.FrameY[PC_RIGHT][PC_TURN][PC_MODE2] = temparray[x]; x++;
  PC.FrameW[PC_RIGHT][PC_TURN][PC_MODE2] = temparray[x]; x++;
  PC.FrameH[PC_RIGHT][PC_TURN][PC_MODE2] = temparray[x]; x++;

  PC.FrameX[PC_LEFT][PC_STAND][PC_MODE2] = temparray[x]; x++;
  PC.FrameY[PC_LEFT][PC_STAND][PC_MODE2] = temparray[x]; x++;
  PC.FrameW[PC_LEFT][PC_STAND][PC_MODE2] = temparray[x]; x++;
  PC.FrameH[PC_LEFT][PC_STAND][PC_MODE2] = temparray[x]; x++;

  PC.FrameX[PC_LEFT][PC_WALK1][PC_MODE2] = temparray[x]; x++;
  PC.FrameY[PC_LEFT][PC_WALK1][PC_MODE2] = temparray[x]; x++;
  PC.FrameW[PC_LEFT][PC_WALK1][PC_MODE2] = temparray[x]; x++;
  PC.FrameH[PC_LEFT][PC_WALK1][PC_MODE2] = temparray[x]; x++;

  PC.FrameX[PC_LEFT][PC_WALK2][PC_MODE2] = temparray[x]; x++;
  PC.FrameY[PC_LEFT][PC_WALK2][PC_MODE2] = temparray[x]; x++;
  PC.FrameW[PC_LEFT][PC_WALK2][PC_MODE2] = temparray[x]; x++;
  PC.FrameH[PC_LEFT][PC_WALK2][PC_MODE2] = temparray[x]; x++;

  PC.FrameX[PC_LEFT][PC_JUMP][PC_MODE2] = temparray[x]; x++;
  PC.FrameY[PC_LEFT][PC_JUMP][PC_MODE2] = temparray[x]; x++;
  PC.FrameW[PC_LEFT][PC_JUMP][PC_MODE2] = temparray[x]; x++;
  PC.FrameH[PC_LEFT][PC_JUMP][PC_MODE2] = temparray[x]; x++;

  PC.FrameX[PC_LEFT][PC_TURN][PC_MODE2] = temparray[x]; x++;
  PC.FrameY[PC_LEFT][PC_TURN][PC_MODE2] = temparray[x]; x++;
  PC.FrameW[PC_LEFT][PC_TURN][PC_MODE2] = temparray[x]; x++;
  PC.FrameH[PC_LEFT][PC_TURN][PC_MODE2] = temparray[x]; x++;

  // MORPHING
  PC.FrameX[PC_MORPH][PC_MORPH1][PC_MODE3] = temparray[x]; x++;
  PC.FrameY[PC_MORPH][PC_MORPH1][PC_MODE3] = temparray[x]; x++;
  PC.FrameW[PC_MORPH][PC_MORPH1][PC_MODE3] = temparray[x]; x++;
  PC.FrameH[PC_MORPH][PC_MORPH1][PC_MODE3] = temparray[x]; x++;

  PC.FrameX[PC_MORPH][PC_MORPH2][PC_MODE3] = temparray[x]; x++;
  PC.FrameY[PC_MORPH][PC_MORPH2][PC_MODE3] = temparray[x]; x++;
  PC.FrameW[PC_MORPH][PC_MORPH2][PC_MODE3] = temparray[x]; x++;
  PC.FrameH[PC_MORPH][PC_MORPH2][PC_MODE3] = temparray[x]; x++;
  // MORPHING

  // DEAD
  PC.FrameX[PC_DEAD][PC_DEAD][PC_DEAD] = temparray[x]; x++;
  PC.FrameY[PC_DEAD][PC_DEAD][PC_DEAD] = temparray[x]; x++;
  PC.FrameW[PC_DEAD][PC_DEAD][PC_DEAD] = temparray[x]; x++;
  PC.FrameH[PC_DEAD][PC_DEAD][PC_DEAD] = temparray[x]; x++;
  // DEAD

  }
  fclose(stagefile);

}

// ##############################################
// ##############################################
// ##############################################

void PC_PowerUp_Set(int PowerUpNumber)
{
  if(PowerUpNumber == 8){PC.Lives += 1;}
  if(PowerUpNumber < 0){PowerUpNumber = 0;}
  if(PowerUpNumber > 7){PowerUpNumber = 7;}
  if(PowerUpNumber < 1){PC.Mode = PC_MODE1;}
  if(PowerUpNumber > 0){PC.Mode = PC_MODE2;}
  if(PowerUpNumber == 1){PC.MorphingCounter = PC_MORPHING_DURATION; AUDIO_Sound_Play(AUDIO_GOTPOWERUP);}
  PC.PowerUp = PowerUpNumber;
}

// ##############################################
// ##############################################
// ##############################################
