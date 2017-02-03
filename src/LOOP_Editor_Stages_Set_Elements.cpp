#include "globals.h"

// ##############################################
// ##############################################
// ##############################################

void LOOP_Editor_Stages_Set_Tile(int TileType, int x, int y)
{
  int El_Width, El_Height;

  if(ME.SingleTileMode){ME.TileNumber[x][y] = TileType;}

  if(!ME.SingleTileMode)
  {

    if(TileType != 250)
    {
      if(LOOP_Editor_Stages_Room_For_Object(TileType, x, y)) // CHECK FOR ANY OF THE OBJECTS WITH THESE DIMENSIONS
      {
        for(El_Width = 0; El_Width < ElementWidth(TileType); El_Width++)
        {
          for(El_Height = 0; El_Height < ElementHeight(TileType); El_Height++)
          {
            ME.TileNumber[x+El_Width][y+El_Height] = TileType+El_Width+((El_Height)*TS.Width); // SET TILES
          }
        }
      }
    }


    // 3x1 (SPLITTABLE!)
    if(TileType == 250) // LAVA (CAN BE SPLIT UP OR INCOMPLETE)
    {
      if(ME.TileNumber[x+0][y+0] == 0){ME.TileNumber[x+0][y+0] = TileType;}
      if(ME.TileNumber[x+1][y+0] == 0){ME.TileNumber[x+1][y+0] = TileType+1;}
      if(ME.TileNumber[x+2][y+0] == 0){ME.TileNumber[x+2][y+0] = TileType+2;}
    }
  }
}

// ##############################################
// ##############################################
// ##############################################

bool LOOP_Editor_Stages_Room_For_Object(int TileType, int x, int y)
{
  bool ReturnValue = false;
  int El_Width, El_Height;

  if(ME.SingleTileMode){ReturnValue = true;}

  if(!ME.SingleTileMode)
  {
    if(TileType != 250)
    {
      int ProblemCounter = 0;
      for(El_Width = 0; El_Width < ElementWidth(TileType); El_Width++)
      {
        for(El_Height = 0; El_Height < ElementHeight(TileType); El_Height++)
        {
          if(ME.TileNumber[x+El_Width][y+El_Height] !=0){ProblemCounter++;} // IF TILE OCCUPIED RAISE PROBLEMCOUNTER
        }
      }
      if(ProblemCounter == 0 && (x+ElementWidth(TileType))<257 && (y+ElementHeight(TileType))<31) // ALL TILES CLEAR AND ELEMENT 100% ON STAGE
      {
        ReturnValue = true;
      }
    }

    // 3x1 (SPLITTABLE!)
    if(TileType == 250) // LAVA (CAN BE SPLIT UP OR INCOMPLETE)
    {
      ReturnValue = true;
    }
  }
  return ReturnValue;
}

// ##############################################
// ##############################################
// ##############################################

void LOOP_Editor_Stages_Delete_Tile(int x, int y)
{
  int El_Width, El_Height;
  int TileNumber = ME.TileNumber[x][y];
  bool DeletedAnEnemy = false;

  // DELETE ENEMY IF ON THIS TILE
  int EnemyX = (int)((MouseX+ME.StagePosX)/TS.Tile_Width);
  int EnemyY = (int)((MouseY+ME.StagePosY)/TS.Tile_Height)+1;

  int i;
  for(i=0; i<MAX_NUM_ENEMIES; i++)
  {
    if(ME.Enemy_PosX[i] == EnemyX &&
       ME.Enemy_PosY[i] == EnemyY &&
       ME.Enemy_InUse[i])
    {ME.Enemy_InUse[i] = false; DeletedAnEnemy = true;}
  }

  // IF NOTHING TO DELETE - SHOW INTERFACE
  if(ME.TileNumber[x][y] == 0 && !DeletedAnEnemy){ME.ShowInterface = true;}

  // DELETE A SINGLE TILE
  if(ME.SingleTileMode && ME.TileNumber[x][y] != 0){ME.TileNumber[x][y] = 0;}

  //DELETE AN ELEMENT
  if(!ME.SingleTileMode && (ElementWidth(TileNumber) > 1 || ElementHeight(TileNumber) > 1)) // && ME.TileNumber[x][y] != 0
  {
    for(El_Width = 0; El_Width < ElementWidth(TileNumber); El_Width++)
    {
      for(El_Height = 0; El_Height < ElementHeight(TileNumber); El_Height++)
      {
        if(ME.TileNumber[x+El_Width][y+El_Height] == TileNumber+El_Width+(El_Height*TS.Width)) {ME.TileNumber[x+El_Width][y+El_Height] = 0;}
      }
    }
  }
}

// ##############################################
// ##############################################
// ##############################################

void LOOP_Editor_Stages_Set_Tile_Check(int TileType, int x, int y)
{
  ME.DontSetATile = false;

  int z;

  // SET START POSITION OR PICK IT
  if(ME.CurrentStartPosition > -1 && ME.CurrentEnemy < 0 && !ME.Platform_StartGrabbed && !ME.Platform_EndGrabbed)
  {
    LOOP_Editor_Stages_Set_StartPosition();
  }
  else
  {
    if(ME.CurrentEnemy < 0)
    {
      if(ME.StartPositionX_Tile[0] == x && ME.StartPositionY_Tile[0] == y){ME.CurrentStartPosition = 0; ME.DontSetATile = true;}
      if(ME.StartPositionX_Tile[1] == x && ME.StartPositionY_Tile[1] == y){ME.CurrentStartPosition = 1; ME.DontSetATile = true;}
      if(ME.StartPositionX_Tile[2] == x && ME.StartPositionY_Tile[2] == y){ME.CurrentStartPosition = 2; ME.DontSetATile = true;}
      if(ME.StartPositionX_Tile[3] == x && ME.StartPositionY_Tile[3] == y){ME.CurrentStartPosition = 3; ME.DontSetATile = true;}
    }
  }


  // SET ENEMY OR PICK IT
  y += 1; //
  if(ME.CurrentStartPosition < 0 && ME.CurrentEnemy > -1 && !ME.Platform_StartGrabbed && !ME.Platform_EndGrabbed)
  {
    int SetEnemyX = (int)((MouseX+ME.StagePosX)/TS.Tile_Width);
    int SetEnemyY = (int)((MouseY+ME.StagePosY)/TS.Tile_Height)+1;
    LOOP_Editor_Stages_Set_Enemy(SetEnemyX, SetEnemyY);
  }
  else
  {
    for(z=0; z<MAX_NUM_ENEMIES; z++)
    {
      if(ME.Enemy_PosX[z] == x && ME.Enemy_PosY[z] == y){ME.CurrentEnemy = z; ME.DontSetATile = true;}
    }
  }


  // SET PLATFORM START POSITION OR PICK IT
  y -= 1; // BECAUSE WE ADDED +1 TO SET ENEMY
  bool PickedPlatform = false;

  if(ME.CurrentStartPosition < 0 && ME.CurrentEnemy < 0)
  {
    if(ME.Platform_End_X == x && ME.Platform_End_Y == y){PickedPlatform = true; ME.Platform_StartGrabbed = false; ME.Platform_EndGrabbed = true; ME.DontSetATile = true;}
    if(ME.Platform_Start_X == x && ME.Platform_Start_Y == y){PickedPlatform = true; ME.Platform_StartGrabbed = true; ME.Platform_EndGrabbed = false; ME.DontSetATile = true;}
    if(!PickedPlatform)
    {
      LOOP_Editor_Stages_SPRITE_Platform_Set(x, y);
    }
  }


}

// ##############################################
// ##############################################
// ##############################################

void LOOP_Editor_Stages_Set_StartPosition()
{
  int x = (int)((MouseX+ME.StagePosX)/TS.Tile_Width);
  int y = (int)((MouseY+ME.StagePosY)/TS.Tile_Height);

  if(ME.CurrentStartPosition > -1)
  {
    ME.StartPositionX_Tile[ME.CurrentStartPosition] = x;
    ME.StartPositionY_Tile[ME.CurrentStartPosition] = y;
  }
  ME.DontSetATile = true;
  ME.CurrentStartPosition = -1;
}

// ##############################################
// ##############################################
// ##############################################
