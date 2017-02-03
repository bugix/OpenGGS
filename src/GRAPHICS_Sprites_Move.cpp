#include "globals.h"

void Sprite_SmallCoin_Gravity(int SmallCoinNumber);
void Sprite_PowerUp_Gravity(int PowerUpNumber);
void Sprite_Platform_Move();
void SPRITE_DropStone_Gravity(int DropStoneNumber);

bool Sprite_PowerUp_Collision_Down(int PowerUpNumber);
bool Sprite_PowerUp_Collision_Right(int PowerUpNumber);
bool Sprite_PowerUp_Collision_Left(int PowerUpNumber);
void Sprite_PowerUp_Tilecollision(int PowerUpNumber);
void Sprite_PowerUp_Walk(int PowerUpNumber);

// ##############################################
// ##############################################
// ##############################################

void SPRITES_Move()
{
  int i;
  for(i=1; i<20; i++) // DON'T MESS WITH SMALLCOIN[0] - IT'S USED IN THE INTERFACE
  {
    if(Sprite_SmallCoin[i].Active)
    {
      Sprite_SmallCoin_Gravity(i);
    }
  }
  for(i=1; i<10; i++)
  {
    if(Sprite_PowerUp[i].Active)
    {
      Sprite_PowerUp_Tilecollision(i);
      if(Sprite_PowerUp[i].OnGround){Sprite_PowerUp_Walk(i);}
      //Sprite_PowerUp_Walk(i);
      if(!Sprite_PowerUp[i].OnGround){Sprite_PowerUp_Gravity(i);}
      if(Sprite_PowerUp[i].PosY < -300 ||
         Sprite_PowerUp[i].PosY > GV.Screen_Height ||
         Sprite_PowerUp[i].PosX-PC.StagePosX < - 300 ||
         Sprite_PowerUp[i].PosX-PC.StagePosX > GV.Screen_Width + 300)
      {Sprite_PowerUp[i].Active = false;}
    }
  }

  for (i = 1; i < 30; i++)
  {
    if(Sprite_DropStone[i].inUse)
    {
      SPRITE_DropStone_Gravity(i);
      if(Sprite_DropStone[i].PosY < -300 ||
         Sprite_DropStone[i].PosY > GV.Screen_Height)
      {Sprite_DropStone[i].inUse = false;}
    }
  }

  if(Platform.inUse){Sprite_Platform_Move();}

  // CALLING THIS FUNCTION SEVERAL TIMES
  // HACKY WAY TO INCREASE BULLET SPEED...
  if(Sprite_Bullet.Active){SPRITE_Bullet_Move();}
  if(Sprite_Bullet.Active){SPRITE_Bullet_Move();}
  if(Sprite_Bullet.Active){SPRITE_Bullet_Move();}
}

// ##############################################
// ##############################################
// ##############################################

void Sprite_SmallCoin_Gravity(int SmallCoinNumber)
{

  Sprite_SmallCoin[SmallCoinNumber].JumpVelocity -= World.Gravity;

  Sprite_SmallCoin[SmallCoinNumber].PosY -= int(Sprite_SmallCoin[SmallCoinNumber].JumpVelocity/2);

  if(Sprite_SmallCoin[SmallCoinNumber].PosY > GV.Screen_Height){Sprite_SmallCoin[SmallCoinNumber].Active = false;}

  // MOVE SMALCOIN SIDEWAYS
  // IT LOOKS COOLER WITHOUT SIDEWAYS MOVEMENT
  //if(Sprite_SmallCoin[SmallCoinNumber].JumpVelocity < 10){Sprite_SmallCoin[SmallCoinNumber].RunVelocity += 1.5*World.Friction;}
  //if(Sprite_SmallCoin[SmallCoinNumber].RunVelocity > 10){Sprite_SmallCoin[SmallCoinNumber].RunVelocity = 10;}
  //Sprite_SmallCoin[SmallCoinNumber].PosX += int(Sprite_SmallCoin[SmallCoinNumber].RunVelocity/4);

}

// ##############################################
// ##############################################
// ##############################################

void Sprite_PowerUp_Gravity(int PowerUpNumber)
{
  Sprite_PowerUp[PowerUpNumber].JumpVelocity -= World.Gravity;

  Sprite_PowerUp[PowerUpNumber].PosY -= int(Sprite_PowerUp[PowerUpNumber].JumpVelocity/2);

  if(Sprite_PowerUp[PowerUpNumber].JumpVelocity < -World.TerminalVelocity){Sprite_PowerUp[PowerUpNumber].JumpVelocity = -World.TerminalVelocity;}
}

// ##############################################
// ##############################################
// ##############################################

void Sprite_PowerUp_Tilecollision(int PowerUpNumber)
{
  Sprite_PowerUp[PowerUpNumber].OnGround = false;

  // CHECK IF ENEMY STANDS ON GROUND
  if(Sprite_PowerUp_Collision_Down(PowerUpNumber))
  {
    // BOUNCE POWERUP
    if(Sprite_PowerUp[PowerUpNumber].JumpVelocity <-8){Sprite_PowerUp[PowerUpNumber].JumpVelocity = -Sprite_PowerUp[PowerUpNumber].JumpVelocity-8;}

    Sprite_PowerUp[PowerUpNumber].OnGround = true;

    // PREVENT SINKING INTO TILE
    Sprite_PowerUp[PowerUpNumber].PosY -= ((Sprite_PowerUp[PowerUpNumber].PosY+ Sprite_PowerUp[PowerUpNumber].h) % TS.Tile_Height);
  }

  if(Sprite_PowerUp[PowerUpNumber].Direction == NPC_LEFT)
  {
    if(Sprite_PowerUp_Collision_Left(PowerUpNumber) ||
       Sprite_PowerUp[PowerUpNumber].PosX < 1)
    {
      Sprite_PowerUp[PowerUpNumber].Direction = NPC_RIGHT;
      Sprite_PowerUp[PowerUpNumber].RunVelocity = 0;
    }
  }
  else
  {
    if(Sprite_PowerUp_Collision_Right(PowerUpNumber) ||
       Sprite_PowerUp[PowerUpNumber].PosX > StageC64.StageWidthPixels - Sprite_PowerUp[PowerUpNumber].w)
    {
      Sprite_PowerUp[PowerUpNumber].Direction = NPC_LEFT;
      Sprite_PowerUp[PowerUpNumber].RunVelocity = 0;
    }
  }

}

// ##############################################
// ##############################################
// ##############################################

void Sprite_PowerUp_Walk(int PowerUpNumber)
{

  if(Sprite_PowerUp[PowerUpNumber].Direction == NPC_RIGHT){Sprite_PowerUp[PowerUpNumber].RunVelocity += 1*World.Friction;}
  if(Sprite_PowerUp[PowerUpNumber].Direction == NPC_LEFT) {Sprite_PowerUp[PowerUpNumber].RunVelocity -= 1*World.Friction;}

  // MAX SPEED
  if(Sprite_PowerUp[PowerUpNumber].RunVelocity < -Sprite_PowerUp[PowerUpNumber].RunStrength){Sprite_PowerUp[PowerUpNumber].RunVelocity = -Sprite_PowerUp[PowerUpNumber].RunStrength;} // MAX SPEED
  if(Sprite_PowerUp[PowerUpNumber].RunVelocity > Sprite_PowerUp[PowerUpNumber].RunStrength) {Sprite_PowerUp[PowerUpNumber].RunVelocity = Sprite_PowerUp[PowerUpNumber].RunStrength;}  // MAX SPEED
  // MAX SPEED

  Sprite_PowerUp[PowerUpNumber].PosX += int(Sprite_PowerUp[PowerUpNumber].RunVelocity/4);

/*
  if(Sprite_PowerUp[PowerUpNumber].PosX > StageC64.StageWidthPixels-30 && Sprite_PowerUp[PowerUpNumber].Direction == NPC_RIGHT){ENEMY_Change_Direction(PowerUpNumber);}
  if(Sprite_PowerUp[PowerUpNumber].PosX < 30 && Sprite_PowerUp[PowerUpNumber].Direction == NPC_LEFT){ENEMY_Change_Direction(PowerUpNumber);}
*/
}

// ##############################################
// ##############################################
// ##############################################

bool Sprite_PowerUp_Collision_Down(int PowerUpNumber)
{
  bool ReturnValue = false;

  if(Sprite_PowerUp[PowerUpNumber].JumpVelocity < 0)
  {
    if(TileType[StageC64.TileNumber[(int)(Sprite_PowerUp[PowerUpNumber].PosX/TS.Tile_Width)]                                  [(int)((Sprite_PowerUp[PowerUpNumber].PosY+Sprite_PowerUp[PowerUpNumber].h)/TS.Tile_Height)]].Solid ||   // CHECK BOTTOM-LEFT
       TileType[StageC64.TileNumber[(int)((Sprite_PowerUp[PowerUpNumber].PosX+Sprite_PowerUp[PowerUpNumber].w/2)/TS.Tile_Width)]                                    [(int)((Sprite_PowerUp[PowerUpNumber].PosY+Sprite_PowerUp[PowerUpNumber].h)/TS.Tile_Height)]].Solid ||   // CHECK BOTTOM-CENTER
       TileType[StageC64.TileNumber[(int)((Sprite_PowerUp[PowerUpNumber].PosX+(Sprite_PowerUp[PowerUpNumber].w))/TS.Tile_Width)][(int)((Sprite_PowerUp[PowerUpNumber].PosY+Sprite_PowerUp[PowerUpNumber].h)/TS.Tile_Height)]].Solid)   // CHECK BOTTOM-RIGHT
    {
      ReturnValue = true;
    }
  }

  return ReturnValue;
}

// ##############################################
// ##############################################
// ##############################################

bool Sprite_PowerUp_Collision_Left(int PowerUpNumber)
{
  bool ReturnValue = false;

  // CHECK FOR WALLS
  if(TileType[StageC64.TileNumber[(int)(Sprite_PowerUp[PowerUpNumber].PosX/TS.Tile_Width)][(int)((Sprite_PowerUp[PowerUpNumber].PosY+Sprite_PowerUp[PowerUpNumber].h)/TS.Tile_Height)-1]].Solid)   // CHECK BOTTOM-LEFT

  {
    ReturnValue = true;
  }

  if(TileType[StageC64.TileNumber[(int)(Sprite_PowerUp[PowerUpNumber].PosX/TS.Tile_Width)][(int)(Sprite_PowerUp[PowerUpNumber].PosY/TS.Tile_Height)]].Solid)   // CHECK TOP-LEFT
  {
    ReturnValue = true;
  }

  return ReturnValue;
}

// ##############################################
// ##############################################
// ##############################################

bool Sprite_PowerUp_Collision_Right(int PowerUpNumber)
{
  bool ReturnValue = false;

  // CHECK FOR WALLS
  if(TileType[StageC64.TileNumber[(int)((Sprite_PowerUp[PowerUpNumber].PosX+Sprite_PowerUp[PowerUpNumber].w)/TS.Tile_Width)][(int)((Sprite_PowerUp[PowerUpNumber].PosY+Sprite_PowerUp[PowerUpNumber].h)/TS.Tile_Height)-1]].Solid)   // CHECK BOTTOM-LEFT

  {
    ReturnValue = true;
  }

  if(TileType[StageC64.TileNumber[(int)((Sprite_PowerUp[PowerUpNumber].PosX+Sprite_PowerUp[PowerUpNumber].w)/TS.Tile_Width)][(int)(Sprite_PowerUp[PowerUpNumber].PosY/TS.Tile_Height)]].Solid)   // CHECK TOP-LEFT
  {
    ReturnValue = true;
  }

  return ReturnValue;
}

// ##############################################
// ##############################################
// ##############################################

void Sprite_Platform_Move()
{
  //if(Platform.PosX - PC.PosX < 640)
  {
    if(Platform.Direction == 1)
    {
      if(Platform.PosY < Platform.End_Y){Platform.PosY++;}
     if(Platform.PosY > Platform.End_Y){Platform.PosY--;}
      if(Platform.PosY == Platform.End_Y){Platform.Direction = 0;}
    }
    if(Platform.Direction == 0)
    {
      if(Platform.PosY < Platform.Start_Y){Platform.PosY++;}
      if(Platform.PosY > Platform.Start_Y){Platform.PosY--;}
      if(Platform.PosY == Platform.Start_Y){Platform.Direction = 1;}
    }
  }
}

// ##############################################
// ##############################################
// ##############################################


void SPRITE_DropStone_Gravity(int DropStoneNumber)
{
  Sprite_DropStone[DropStoneNumber].JumpVelocity -= World.Gravity;

  if(Sprite_DropStone[DropStoneNumber].JumpVelocity < 0)
  {
    if(TileType[StageC64.TileNumber[(int)(Sprite_DropStone[DropStoneNumber].PosX/TS.Tile_Width)]                                      [(int)((Sprite_DropStone[DropStoneNumber].PosY+Sprite_DropStone[DropStoneNumber].h)/TS.Tile_Height)]].Solid ||   // CHECK BOTTOM-LEFT
       TileType[StageC64.TileNumber[(int)((Sprite_DropStone[DropStoneNumber].PosX+Sprite_DropStone[DropStoneNumber].w/2)/TS.Tile_Width)]                                        [(int)((Sprite_DropStone[DropStoneNumber].PosY+Sprite_DropStone[DropStoneNumber].h)/TS.Tile_Height)]].Solid ||   // CHECK BOTTOM-CENTER
       TileType[StageC64.TileNumber[(int)((Sprite_DropStone[DropStoneNumber].PosX+(Sprite_DropStone[DropStoneNumber].w))/TS.Tile_Width)][(int)((Sprite_DropStone[DropStoneNumber].PosY+Sprite_DropStone[DropStoneNumber].h)/TS.Tile_Height)]].Solid)   // CHECK BOTTOM-RIGHT
    {
      Sprite_DropStone[DropStoneNumber].JumpVelocity = 0;
      Sprite_DropStone[DropStoneNumber].PosY -= ((Sprite_DropStone[DropStoneNumber].PosY+ Sprite_DropStone[DropStoneNumber].h) % TS.Tile_Height);
    }
  }

  Sprite_DropStone[DropStoneNumber].PosY -= int(Sprite_DropStone[DropStoneNumber].JumpVelocity/2);

  if(Sprite_DropStone[DropStoneNumber].JumpVelocity < -World.TerminalVelocity){Sprite_DropStone[DropStoneNumber].JumpVelocity = -World.TerminalVelocity;}


}
