#include "globals.h"

bool ENEMY_Collision_Down(int EnemyNumber);
bool ENEMY_Collision_Left(int EnemyNumber);
bool ENEMY_Collision_Right(int EnemyNumber);

// ##############################################
// ##############################################
// ##############################################

void ENEMY_Check_Tilecollision(int EnemyNumber)
{
  Enemy[EnemyNumber].OnGround = false;

  // CHECK IF ENEMY STANDS ON GROUND
  if(ENEMY_Collision_Down(EnemyNumber))
  {
    Enemy[EnemyNumber].OnGround = true;
    Enemy[EnemyNumber].PosY -= (Enemy[EnemyNumber].PosY % TS.Tile_Height);
  }

  if(Enemy[EnemyNumber].Direction == NPC_LEFT)
  {
    if(ENEMY_Collision_Left(EnemyNumber))
    {
      ENEMY_Change_Direction(EnemyNumber);
    }
  }

  if(Enemy[EnemyNumber].Direction == NPC_RIGHT)
  {
    if(ENEMY_Collision_Right(EnemyNumber))
    {
      ENEMY_Change_Direction(EnemyNumber);
    }
  }

}

// ##############################################
// ##############################################
// ##############################################

bool ENEMY_Collision_Down(int EnemyNumber)
{
  bool ReturnValue = false;

  if(Enemy[EnemyNumber].JumpVelocity < 0)
  {
    if(TileType[StageC64.TileNumber[(int)((Enemy[EnemyNumber].PosX-Enemy_Type[Enemy[EnemyNumber].Type].ColWidthHalf)/TS.Tile_Width)][(int)(Enemy[EnemyNumber].PosY/TS.Tile_Height)]].Solid ||   // CHECK BOTTOM-LEFT
       TileType[StageC64.TileNumber[(int)(Enemy[EnemyNumber].PosX/TS.Tile_Width)]                                               [(int)(Enemy[EnemyNumber].PosY/TS.Tile_Height)]].Solid ||   // CHECK BOTTOM-CENTER
       TileType[StageC64.TileNumber[(int)((Enemy[EnemyNumber].PosX+Enemy_Type[Enemy[EnemyNumber].Type].ColWidthHalf)/TS.Tile_Width)][(int)(Enemy[EnemyNumber].PosY/TS.Tile_Height)]].Solid)   // CHECK BOTTOM-RIGHT
    {
      ReturnValue = true;
    }
  }

  // DON'T STOP JUMPERS!
  if(Enemy_Type[Enemy[EnemyNumber].Type].JumpStrength > 0){ReturnValue = false;}

  return ReturnValue;
}

// ##############################################
// ##############################################
// ##############################################

bool ENEMY_Collision_Left(int EnemyNumber)
{
  bool ReturnValue = false;

  // CHECK FOR CLIFFS
  if(!TileType[StageC64.TileNumber[(int)((Enemy[EnemyNumber].PosX-Enemy_Type[Enemy[EnemyNumber].Type].ColWidthHalf)/TS.Tile_Width)][(int)(Enemy[EnemyNumber].PosY/TS.Tile_Height)]].Solid &&   // CHECK BOTTOM-LEFT
      TileType[StageC64.TileNumber[(int)(Enemy[EnemyNumber].PosX/TS.Tile_Width)]                                               [(int)(Enemy[EnemyNumber].PosY/TS.Tile_Height)]].Solid &&   // CHECK BOTTOM-CENTER
      TileType[StageC64.TileNumber[(int)((Enemy[EnemyNumber].PosX+Enemy_Type[Enemy[EnemyNumber].Type].ColWidthHalf)/TS.Tile_Width)][(int)(Enemy[EnemyNumber].PosY/TS.Tile_Height)]].Solid &&
      Enemy_Type[Enemy[EnemyNumber].Type].Walker &&
     !Enemy_Type[Enemy[EnemyNumber].Type].FallOfCliffs)
  {
    ReturnValue = true;
  }

  // CHECK FOR WALLS
  if(TileType[StageC64.TileNumber[(int)((Enemy[EnemyNumber].PosX-Enemy_Type[Enemy[EnemyNumber].Type].ColWidthHalf-1)/TS.Tile_Width)][(int)((Enemy[EnemyNumber].PosY)/TS.Tile_Height)-1]].Solid)   // CHECK BOTTOM-LEFT
  {
    ReturnValue = true;
  }

  if(TileType[StageC64.TileNumber[(int)((Enemy[EnemyNumber].PosX-Enemy_Type[Enemy[EnemyNumber].Type].ColWidthHalf-1)/TS.Tile_Width)][(int)((Enemy[EnemyNumber].PosY-Enemy_Type[Enemy[EnemyNumber].Type].ColHeight)/TS.Tile_Height)]].Solid)   // CHECK TOP-LEFT
  {
    ReturnValue = true;
  }

  return ReturnValue;
}

// ##############################################
// ##############################################
// ##############################################

bool ENEMY_Collision_Right(int EnemyNumber)
{
  bool ReturnValue = false;

  // CHECK FOR CLIFFS
  if( TileType[StageC64.TileNumber[(int)((Enemy[EnemyNumber].PosX-Enemy_Type[Enemy[EnemyNumber].Type].ColWidthHalf)/TS.Tile_Width)][(int)(Enemy[EnemyNumber].PosY/TS.Tile_Height)]].Solid &&   // CHECK BOTTOM-LEFT
      TileType[StageC64.TileNumber[(int)(Enemy[EnemyNumber].PosX/TS.Tile_Width)]                                               [(int)(Enemy[EnemyNumber].PosY/TS.Tile_Height)]].Solid &&   // CHECK BOTTOM-CENTER
     !TileType[StageC64.TileNumber[(int)((Enemy[EnemyNumber].PosX+Enemy_Type[Enemy[EnemyNumber].Type].ColWidthHalf)/TS.Tile_Width)][(int)(Enemy[EnemyNumber].PosY/TS.Tile_Height)]].Solid &&
      Enemy_Type[Enemy[EnemyNumber].Type].Walker &&
     !Enemy_Type[Enemy[EnemyNumber].Type].FallOfCliffs)
  {
    ReturnValue = true;
  }

  // CHECK FOR WALLS
  if(TileType[StageC64.TileNumber[(int)((Enemy[EnemyNumber].PosX+Enemy_Type[Enemy[EnemyNumber].Type].ColWidthHalf+1)/TS.Tile_Width)][(int)((Enemy[EnemyNumber].PosY)/TS.Tile_Height)-1]].Solid)   // CHECK BOTTOM-LEFT
  {
    ReturnValue = true;
  }

  if(TileType[StageC64.TileNumber[(int)((Enemy[EnemyNumber].PosX+Enemy_Type[Enemy[EnemyNumber].Type].ColWidthHalf+1)/TS.Tile_Width)][(int)((Enemy[EnemyNumber].PosY-Enemy_Type[Enemy[EnemyNumber].Type].ColHeight)/TS.Tile_Height)]].Solid)   // CHECK TOP-LEFT
  {
    ReturnValue = true;
  }

  return ReturnValue;
}

// ##############################################
// ##############################################
// ##############################################
