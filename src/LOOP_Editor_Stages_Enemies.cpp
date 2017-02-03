#include "globals.h"

// ##############################################
// ##############################################
// ##############################################

void LOOP_Editor_Stages_Draw_Enemies()
{
  int x;
  for (x = 0; x < MAX_NUM_ENEMIES; x++)
  {
    if(ME.Enemy_InUse[x]){LOOP_Editor_Stages_Draw_Enemy(x);}
  }
}

// ##############################################
// ##############################################
// ##############################################

void LOOP_Editor_Stages_Set_New_Enemy(int EnemyType, int x, int y)
{
  int i;

  int EnemyNumber = 0;

  // DELETE ENEMY IF ON THIS TILE
  for(i=1;i<MAX_NUM_ENEMIES;i++) // WAR 16
  {
    if(ME.Enemy_PosX[i] == x &&
       ME.Enemy_PosY[i] == y &&
       ME.Enemy_InUse[i])
    {ME.Enemy_InUse[i] = false;}
  }

  // SET NEW ENEMY
  for(i=0;i<MAX_NUM_ENEMIES;i++){if(!ME.Enemy_InUse[i]){EnemyNumber = i;}}
  if(EnemyNumber>-1)
  {
    ME.Enemy_PosX[EnemyNumber] = x;
    ME.Enemy_PosY[EnemyNumber] = y;
    ME.Enemy_Type[EnemyNumber] = EnemyType;
    ME.Enemy_InUse[EnemyNumber] = true;
    ME.Enemy_Direction[EnemyNumber] = NPC_LEFT;
    ME.Enemy_Alive[EnemyNumber] = true;
    //ME.CurrentEnemyType = 0;
  }

  ME.DontSetATile = true;
}

// ##############################################
// ##############################################
// ##############################################

void LOOP_Editor_Stages_Set_Enemy(int x, int y)
{
  if(ME.CurrentEnemy > -1)
  {
    ME.Enemy_PosX[ME.CurrentEnemy] = x;
    ME.Enemy_PosY[ME.CurrentEnemy] = y;
  }

  ME.CurrentEnemy = -1;
  ME.DontSetATile = true;
}

// ##############################################
// ##############################################
// ##############################################

void LOOP_Editor_Stages_Draw_Enemy(int EnemyNumber)
{
  SDL_Rect SrcRect;
  SDL_Rect DstRect;

  int AnimationFrame;
  AnimationFrame = EV.Frame_4;
  if(ME.Enemy_Type[EnemyNumber] == 15){AnimationFrame = EV.Frame_7;}



  if(ME.Enemy_InUse[EnemyNumber])
  {
    SrcRect.x = Enemy_Type[1].FrameX[NPC_LEFT][0][NPC_ALIVE];
    SrcRect.y = Enemy_Type[1].FrameY[NPC_LEFT][0][NPC_ALIVE];
    SrcRect.w = Enemy_Type[1].FrameW[NPC_LEFT][0][NPC_ALIVE];
    SrcRect.h = Enemy_Type[1].FrameH[NPC_LEFT][0][NPC_ALIVE];

    if(ME.Enemy_Type[EnemyNumber] < 16)
    {
      SrcRect.x = Enemy_Type[ME.Enemy_Type[EnemyNumber]].FrameX[ME.Enemy_Direction[EnemyNumber]][AnimationFrame][NPC_ALIVE];
      SrcRect.y = Enemy_Type[ME.Enemy_Type[EnemyNumber]].FrameY[ME.Enemy_Direction[EnemyNumber]][AnimationFrame][NPC_ALIVE];
      SrcRect.w = Enemy_Type[ME.Enemy_Type[EnemyNumber]].FrameW[ME.Enemy_Direction[EnemyNumber]][AnimationFrame][NPC_ALIVE];
      SrcRect.h = Enemy_Type[ME.Enemy_Type[EnemyNumber]].FrameH[ME.Enemy_Direction[EnemyNumber]][AnimationFrame][NPC_ALIVE];

      if(!ME.Enemy_Alive[EnemyNumber])
      {
        SrcRect.x = Enemy_Type[ME.Enemy_Type[EnemyNumber]].FrameX[NPC_DEAD][NPC_DEAD][NPC_DEAD];
        SrcRect.y = Enemy_Type[ME.Enemy_Type[EnemyNumber]].FrameY[NPC_DEAD][NPC_DEAD][NPC_DEAD];
        SrcRect.w = Enemy_Type[ME.Enemy_Type[EnemyNumber]].FrameW[NPC_DEAD][NPC_DEAD][NPC_DEAD];
        SrcRect.h = Enemy_Type[ME.Enemy_Type[EnemyNumber]].FrameH[NPC_DEAD][NPC_DEAD][NPC_DEAD];
      }
    }

    DstRect.w = SrcRect.w;
    DstRect.h = SrcRect.h;
    DstRect.x = (ME.Enemy_PosX[EnemyNumber]*TS.Tile_Width)-(int)(SrcRect.w/2)-ME.StagePosX;
    DstRect.y = (ME.Enemy_PosY[EnemyNumber]*TS.Tile_Height)-SrcRect.h;
    SDL_RenderCopyEx(gRenderer, EnemiesTexture, &SrcRect, &DstRect, 0, NULL, SDL_FLIP_NONE );

    // DRAW GRABBER ON ENEMY
    int GrabberX = (ME.Enemy_PosX[EnemyNumber]*TS.Tile_Width)-ME.StagePosX;
    int GrabberY = (ME.Enemy_PosY[EnemyNumber]*TS.Tile_Height)-TS.Tile_Height;
    if(EnemyNumber == ME.CurrentEnemy){INTERFACE_Tile_Draw(GrabberX, GrabberY, INTERFACE_MARK_GRAB_ACTIVE);}
    if(EnemyNumber != ME.CurrentEnemy){INTERFACE_Tile_Draw(GrabberX, GrabberY, INTERFACE_MARK_GRAB);}
    //PrintInt(GrabberX, GrabberY, 0,0, ME.Enemy_PosX[EnemyNumber]);
    //PrintInt(GrabberX, GrabberY+10, 0,0, ME.Enemy_PosY[EnemyNumber]);
    //PrintInt(GrabberX, GrabberY+10, 0,0,EnemyNumber);
    //PrintInt(GrabberX, GrabberY+20, 0,0,ME.Enemy_Direction[EnemyNumber]);
    //PrintInt(GrabberX, GrabberY+30, 0,0,AnimationFrame);
    // DRAW GRABBER ON ENEMY

   //INTERFACE_Tile_Draw(10+32*EnemyNumber, 90, INTERFACE_MARK_GRAB_ACTIVE);
   //PrintInt(10+32*EnemyNumber, 80,0,0, ME.Enemy_Type[EnemyNumber]);
  }
   //INTERFACE_Tile_Draw(10+32*EnemyNumber, 100, INTERFACE_MARK_GRAB_ACTIVE);
}

// ##############################################
// ##############################################
// ##############################################
