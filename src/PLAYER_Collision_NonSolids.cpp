#include "globals.h"

void Delete_Coin(int x, int y);

// ##############################################
// ##############################################
// ##############################################

void PC_Check_TilecollisionNonSolid()
{
  // CALCULATE PLAYER POSITION
  PC.x1T = (int)((PC.PosX-PC.ColWidthHalf)/TS.Tile_Width);
  PC.x2T = (int)(PC.PosX/TS.Tile_Width);
  PC.x3T = (int)((PC.PosX+PC.ColWidthHalf)/TS.Tile_Width);
  PC.y1T = (int)((PC.PosY-PC.ColHeight)/TS.Tile_Height);
  PC.y2T = (int)((PC.PosY-PC.ColHeightHalf)/TS.Tile_Height);
  PC.y3T = (int)((PC.PosY-1)/TS.Tile_Height);
  PC.x1 = PC.PosX-PC.ColWidthHalf;
  PC.x2 = PC.PosX;
  PC.x3 = PC.PosX+PC.ColWidthHalf;
  PC.y1 = PC.PosY-PC.ColHeight;
  PC.y2 = PC.PosY-PC.ColHeightHalf;
  PC.y3 = PC.PosY-1;

  // CHECK FOR COIN COLLISIONS
  if(TileType[StageC64.TileNumber[PC.x1T][PC.y1T]].Coin){Delete_Coin(PC.x1T, PC.y1T);}
  if(TileType[StageC64.TileNumber[PC.x2T][PC.y1T]].Coin){Delete_Coin(PC.x2T, PC.y1T);}
  if(TileType[StageC64.TileNumber[PC.x3T][PC.y1T]].Coin){Delete_Coin(PC.x3T, PC.y1T);}
  if(TileType[StageC64.TileNumber[PC.x1T][PC.y2T]].Coin){Delete_Coin(PC.x1T, PC.y2T);}
  if(TileType[StageC64.TileNumber[PC.x2T][PC.y2T]].Coin){Delete_Coin(PC.x2T, PC.y2T);}
  if(TileType[StageC64.TileNumber[PC.x3T][PC.y2T]].Coin){Delete_Coin(PC.x3T, PC.y2T);}
  if(TileType[StageC64.TileNumber[PC.x1T][PC.y3T]].Coin){Delete_Coin(PC.x1T, PC.y3T);}
  if(TileType[StageC64.TileNumber[PC.x2T][PC.y3T]].Coin){Delete_Coin(PC.x2T, PC.y3T);}
  if(TileType[StageC64.TileNumber[PC.x3T][PC.y3T]].Coin){Delete_Coin(PC.x3T, PC.y3T);}
  // CHECK FOR COIN COLLISIONS

  // CHECK FOR LETHAL COLLISIONS
  if(PC.PosY > PC.ColHeight && PC.PowerUp < 7)
  {
    if(TileType[StageC64.TileNumber[PC.x1T][PC.y1T]].Lethal){PC.gotKilled = true;}
    if(TileType[StageC64.TileNumber[PC.x2T][PC.y1T]].Lethal){PC.gotKilled = true;}
    if(TileType[StageC64.TileNumber[PC.x3T][PC.y1T]].Lethal){PC.gotKilled = true;}
    if(TileType[StageC64.TileNumber[PC.x1T][PC.y2T]].Lethal){PC.gotKilled = true;}
    if(TileType[StageC64.TileNumber[PC.x2T][PC.y2T]].Lethal){PC.gotKilled = true;}
    if(TileType[StageC64.TileNumber[PC.x3T][PC.y2T]].Lethal){PC.gotKilled = true;}
    if(TileType[StageC64.TileNumber[PC.x1T][PC.y3T]].Lethal){PC.gotKilled = true;}
    if(TileType[StageC64.TileNumber[PC.x2T][PC.y3T]].Lethal){PC.gotKilled = true;}
    if(TileType[StageC64.TileNumber[PC.x3T][PC.y3T]].Lethal){PC.gotKilled = true;}
  }

  if(PC.PosY > PC.ColHeight && PC.PowerUp > 6) // DON'T GET KILLED BY FIRE
  {
    if(TileType[StageC64.TileNumber[PC.x1T][PC.y1T]].Lethal && !TileType[StageC64.TileNumber[PC.x1T][PC.y1T]].Fire){PC.gotKilled = true;}
    if(TileType[StageC64.TileNumber[PC.x2T][PC.y1T]].Lethal && !TileType[StageC64.TileNumber[PC.x2T][PC.y1T]].Fire){PC.gotKilled = true;}
    if(TileType[StageC64.TileNumber[PC.x3T][PC.y1T]].Lethal && !TileType[StageC64.TileNumber[PC.x3T][PC.y1T]].Fire){PC.gotKilled = true;}
    if(TileType[StageC64.TileNumber[PC.x1T][PC.y2T]].Lethal && !TileType[StageC64.TileNumber[PC.x1T][PC.y2T]].Fire){PC.gotKilled = true;}
    if(TileType[StageC64.TileNumber[PC.x2T][PC.y2T]].Lethal && !TileType[StageC64.TileNumber[PC.x2T][PC.y2T]].Fire){PC.gotKilled = true;}
    if(TileType[StageC64.TileNumber[PC.x3T][PC.y2T]].Lethal && !TileType[StageC64.TileNumber[PC.x3T][PC.y2T]].Fire){PC.gotKilled = true;}
    if(TileType[StageC64.TileNumber[PC.x1T][PC.y3T]].Lethal && !TileType[StageC64.TileNumber[PC.x1T][PC.y3T]].Fire){PC.gotKilled = true;}
    if(TileType[StageC64.TileNumber[PC.x2T][PC.y3T]].Lethal && !TileType[StageC64.TileNumber[PC.x2T][PC.y3T]].Fire){PC.gotKilled = true;}
    if(TileType[StageC64.TileNumber[PC.x3T][PC.y3T]].Lethal && !TileType[StageC64.TileNumber[PC.x3T][PC.y3T]].Fire){PC.gotKilled = true;}
  }
  // CHECK FOR LETHAL COLLISIONS

  // CHECK FOR ENTRANCE TO SUB-STAGE
  PC.GotoSubStage = false;
  if(TileType[StageC64.TileNumber[PC.x1T][PC.y1T]].SubStageEntrance){PC.GotoSubStage = true;}
  if(TileType[StageC64.TileNumber[PC.x2T][PC.y1T]].SubStageEntrance){PC.GotoSubStage = true;}
  if(TileType[StageC64.TileNumber[PC.x3T][PC.y1T]].SubStageEntrance){PC.GotoSubStage = true;}
  if(TileType[StageC64.TileNumber[PC.x1T][PC.y2T]].SubStageEntrance){PC.GotoSubStage = true;}
  if(TileType[StageC64.TileNumber[PC.x2T][PC.y2T]].SubStageEntrance){PC.GotoSubStage = true;}
  if(TileType[StageC64.TileNumber[PC.x3T][PC.y2T]].SubStageEntrance){PC.GotoSubStage = true;}
  if(TileType[StageC64.TileNumber[PC.x1T][PC.y3T]].SubStageEntrance){PC.GotoSubStage = true;}
  if(TileType[StageC64.TileNumber[PC.x2T][PC.y3T]].SubStageEntrance){PC.GotoSubStage = true;}
  if(TileType[StageC64.TileNumber[PC.x3T][PC.y3T]].SubStageEntrance){PC.GotoSubStage = true;}
  // CHECK FOR ENTRANCE TO SUB-STAGE
}

// ##############################################
// ##############################################
// ##############################################

void Delete_Coin(int x, int y)
{
  // DELETE THE ENTIRE COIN
  if(StageC64.TileNumber[x-1][y] == StageC64.TileNumber[x][y]-1){StageC64.TileNumber[x-1][y] = 0;}
  if(StageC64.TileNumber[x+1][y] == StageC64.TileNumber[x][y]+1){StageC64.TileNumber[x+1][y] = 0;}
  if(StageC64.TileNumber[x][y-1] == StageC64.TileNumber[x][y]-TS.Width){StageC64.TileNumber[x][y-1] = 0;}
  if(StageC64.TileNumber[x][y+1] == StageC64.TileNumber[x][y]+TS.Width){StageC64.TileNumber[x][y+1] = 0;}
  if(StageC64.TileNumber[x-1][y-1] == StageC64.TileNumber[x][y]-TS.Width-1){StageC64.TileNumber[x-1][y-1] = 0;}
  if(StageC64.TileNumber[x+1][y-1] == StageC64.TileNumber[x][y]-TS.Width+1){StageC64.TileNumber[x+1][y-1] = 0;}
  if(StageC64.TileNumber[x-1][y+1] == StageC64.TileNumber[x][y]+TS.Width-1){StageC64.TileNumber[x-1][y+1] = 0;}
  if(StageC64.TileNumber[x+1][y+1] == StageC64.TileNumber[x][y]+TS.Width+1){StageC64.TileNumber[x+1][y+1] = 0;}
  StageC64.TileNumber[x][y] = 0;
  // DELETE THE ENTIRE COIN
  AUDIO_Sound_Play(AUDIO_DING);
  PC.Coins += 1;
  if(PC.Coins > 99){PC.Coins = 0; PC.Lives++;}
}

// ##############################################
// ##############################################
// ##############################################

bool PC_Collision_Exit()
{
  bool ReturnValue = false;
  //PC.Exit_Reached = false;

  if(
     TileType[StageC64.TileNumber[(int)((PC.PosX-PC.ColWidthHalf)/TS.Tile_Width)][(int)((PC.PosY-PC.ColHeight)/TS.Tile_Height)]].Exit ||
     TileType[StageC64.TileNumber[(int)((PC.PosX+PC.ColWidthHalf)/TS.Tile_Width)][(int)((PC.PosY-PC.ColHeight)/TS.Tile_Height)]].Exit ||
     TileType[StageC64.TileNumber[(int)((PC.PosX+PC.ColWidthHalf)/TS.Tile_Width)][(int)((PC.PosY-PC.ColHeightHalf)/TS.Tile_Height)]].Exit ||
     TileType[StageC64.TileNumber[(int)((PC.PosX-PC.ColWidthHalf)/TS.Tile_Width)][(int)((PC.PosY-PC.ColHeightHalf)/TS.Tile_Height)]].Exit ||
     TileType[StageC64.TileNumber[(int)((PC.PosX-PC.ColWidthHalf)/TS.Tile_Width)][(int)((PC.PosY-0)/TS.Tile_Height)]].Exit ||
     TileType[StageC64.TileNumber[(int)((PC.PosX-PC.ColWidthHalf)/TS.Tile_Width)][(int)((PC.PosY-0)/TS.Tile_Height)]].Exit
    )
  {ReturnValue = true;}

  return ReturnValue;
}

// ##############################################
// ##############################################
// ##############################################
