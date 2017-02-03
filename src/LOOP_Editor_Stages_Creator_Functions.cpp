#include "globals.h"

// ##############################################
// ##############################################
// ##############################################

void CREATOR_Stages_Clear()
{
  int x,y;
  // DELETE ALL TILES
  for(y = 0; y < 30; y++)
  {
    for (x = 0; x < 256; x++)
    {
      ME.TileNumber[x][y] = 0;
    }
  }
}

// ##############################################
// ##############################################
// ##############################################

void CREATOR_Stages_Clear_Enemies()
{
  int x;
  // DELETE ALL ENEMIES
  for(x=0;x<MAX_NUM_ENEMIES;x++)
  {
    ME.Enemy_PosX[x] = 0;
    ME.Enemy_PosY[x] = 0;
    ME.Enemy_Direction[x] = NPC_RIGHT;
    ME.Enemy_Type[x] = 1;
    ME.Enemy_Alive[x] = true;
    ME.Enemy_InUse[x] = false;
  }
}

// ##############################################
// ##############################################
// ##############################################

void CREATOR_Stages_Ground(int IndooOutdoor)
{
  int x;
  if(IndooOutdoor == 0)
  {
    for(x = 0; x < 256; x += 4)
    {
      LOOP_Editor_Stages_Set_Tile(775, x, 27);
    }
  }

  if(IndooOutdoor == 1)
  {
    for(x = 0; x < 256; x += 2)
    {
      LOOP_Editor_Stages_Set_Tile(672, x, 26);
      LOOP_Editor_Stages_Set_Tile(672, x, 28);
    }
  }
}

// ##############################################
// ##############################################
// ##############################################

void CREATOR_Stages_Reset_Start_Positions()
{
  ME.StartPositionX_Tile[0] = 9;
  ME.StartPositionY_Tile[0] = 3;
  ME.StartPositionX_Tile[1] = 10;
  ME.StartPositionY_Tile[1] = 3;
  ME.StartPositionX_Tile[2] = 11;
  ME.StartPositionY_Tile[2] = 3;
  ME.StartPositionX_Tile[3] = 12;
  ME.StartPositionY_Tile[3] = 3;
}

// ##############################################
// ##############################################
// ##############################################

void CREATOR_Stages_Create_Ground_With_Holes(int BackgroundColour, bool Holes)
{
  int x;

  // CREATE GROUND
  CREATOR_Stages_Ground(BackgroundColour);


  // CREATE HOLES IN THE GROUND
  int CeateAHole;
  if(BackgroundColour == 0)
  {
    for(x = 20; x < 240; x += 4)
    {
      CeateAHole = rand() % 8;
      if(CeateAHole == 0)
      {
        LOOP_Editor_Stages_Delete_Tile(x, 27);
        LOOP_Editor_Stages_Set_Tile(791, x, 27);
        x+=4;
        LOOP_Editor_Stages_Delete_Tile(x, 27);
        x+=4;
        LOOP_Editor_Stages_Delete_Tile(x, 27);
        LOOP_Editor_Stages_Set_Tile(780, x+2, 27);
        x+=4;
      }
    }
  }

  if(BackgroundColour == 1)
  {
    for(x = 20; x < 240; x += 4)
    {
      CeateAHole = rand() % 8;
      if(CeateAHole == 0)
      {
        LOOP_Editor_Stages_Delete_Tile(x, 26);
        LOOP_Editor_Stages_Delete_Tile(x, 28);
        LOOP_Editor_Stages_Set_Tile(676, x, 26);
        LOOP_Editor_Stages_Set_Tile(676, x, 28);
        x+=2;
        LOOP_Editor_Stages_Delete_Tile(x, 26);
        LOOP_Editor_Stages_Delete_Tile(x, 28);
        x+=2;
        LOOP_Editor_Stages_Delete_Tile(x, 26);
        LOOP_Editor_Stages_Delete_Tile(x, 28);
        x+=2;
        LOOP_Editor_Stages_Delete_Tile(x, 26);
        LOOP_Editor_Stages_Delete_Tile(x, 28);
        x+=2;
        LOOP_Editor_Stages_Delete_Tile(x, 26);
        LOOP_Editor_Stages_Delete_Tile(x, 28);
        LOOP_Editor_Stages_Set_Tile(674, x, 26);
        LOOP_Editor_Stages_Set_Tile(674, x, 28);
        x+=2;
      }
    }
  }
}

// ##############################################
// ##############################################
// ##############################################
