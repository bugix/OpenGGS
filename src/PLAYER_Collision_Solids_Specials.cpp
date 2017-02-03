#include "globals.h"

// ##############################################
// ##############################################
// ##############################################

void PC_Collision_PowerUpBlock()
{
  int TileX, TileY;
  bool HitAPowerUpBlock = false;

  if(PC.JumpVelocity > 0) // JUMPING UP
  {
    if(TileType[StageC64.TileNumber[(int)(PC.PosX/TS.Tile_Width)][(int)((PC.PosY-PC.ColHeight)/TS.Tile_Height)]].PowerUpBlock)
    {
      TileX = (int)(PC.PosX/TS.Tile_Width);
      TileY = (int)((PC.PosY-PC.ColHeight)/TS.Tile_Height);
      if(!TileType[StageC64.TileNumber[TileX][TileY+1]].Solid){HitAPowerUpBlock = true;}
    }
    if(!HitAPowerUpBlock && TileType[StageC64.TileNumber[(int)((PC.PosX-PC.ColWidthHalf+2)/TS.Tile_Width)][(int)((PC.PosY-PC.ColHeight)/TS.Tile_Height)]].PowerUpBlock)
    {
      TileX = (int)((PC.PosX-PC.ColWidthHalf+2)/TS.Tile_Width);
      TileY = (int)((PC.PosY-PC.ColHeight)/TS.Tile_Height);
      if(!TileType[StageC64.TileNumber[TileX][TileY+1]].Solid){HitAPowerUpBlock = true;}
    }
    if(!HitAPowerUpBlock && TileType[StageC64.TileNumber[(int)((PC.PosX+PC.ColWidthHalf-2)/TS.Tile_Width)][(int)((PC.PosY-PC.ColHeight)/TS.Tile_Height)]].PowerUpBlock)
    {
      TileX = (int)((PC.PosX+PC.ColWidthHalf-2)/TS.Tile_Width);
      TileY = (int)((PC.PosY-PC.ColHeight)/TS.Tile_Height);
      if(!TileType[StageC64.TileNumber[TileX][TileY+1]].Solid){HitAPowerUpBlock = true;}
    }
    if(HitAPowerUpBlock)
    {
       AUDIO_Sound_Play(AUDIO_DING);
      //timecounter_Animation_Tiles_Fast = SDL_GetTicks(); // RESET ANIMATION COUNTER
      if(StageC64.TileNumber[TileX-2][TileY] == StageC64.TileNumber[TileX][TileY]-2 &&
         TileType[StageC64.TileNumber[TileX-2][TileY]].PowerUpBlock)
      {
        StageC64.TileNumber[TileX-2][TileY-1] = 587; StageC64.AnimationCounter[TileX-2][TileY] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX-1][TileY-1] = 588; StageC64.AnimationCounter[TileX-1][TileY] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX][TileY-1] = 589;   StageC64.AnimationCounter[TileX][TileY] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX-2][TileY] = 627;   StageC64.AnimationCounter[TileX-2][TileY-1] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX-1][TileY] = 628;   StageC64.AnimationCounter[TileX-1][TileY-1] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX][TileY] = 629;     StageC64.AnimationCounter[TileX][TileY-1] = World.TileSwitchSpeed;
        HitAPowerUpBlock = false;
        SPRITE_PowerUp_Activate((TileX-1)*TS.Tile_Width, (TileY-2)*TS.Tile_Height);
      }
      if(HitAPowerUpBlock && StageC64.TileNumber[TileX+2][TileY] == StageC64.TileNumber[TileX][TileY]+2 &&
         TileType[StageC64.TileNumber[TileX+2][TileY]].PowerUpBlock)
      {
        StageC64.TileNumber[TileX][TileY-1] = 587;   StageC64.AnimationCounter[TileX][TileY] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX+1][TileY-1] = 588; StageC64.AnimationCounter[TileX+1][TileY] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX+2][TileY-1] = 589; StageC64.AnimationCounter[TileX+2][TileY] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX][TileY] = 627;     StageC64.AnimationCounter[TileX][TileY-1] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX+1][TileY] = 628;   StageC64.AnimationCounter[TileX+1][TileY-1] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX+2][TileY] = 629;   StageC64.AnimationCounter[TileX+2][TileY-1] = World.TileSwitchSpeed;
        HitAPowerUpBlock = false;
        SPRITE_PowerUp_Activate((TileX+1)*TS.Tile_Width, (TileY-2)*TS.Tile_Height);
      }
      if(HitAPowerUpBlock &&
         StageC64.TileNumber[TileX+1][TileY] == StageC64.TileNumber[TileX][TileY]+1 &&
         StageC64.TileNumber[TileX-1][TileY] == StageC64.TileNumber[TileX][TileY]-1 &&
         TileType[StageC64.TileNumber[TileX+1][TileY]].PowerUpBlock &&
         TileType[StageC64.TileNumber[TileX-1][TileY]].PowerUpBlock)
      {
        StageC64.TileNumber[TileX-1][TileY-1] = 587; StageC64.AnimationCounter[TileX-1][TileY] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX][TileY-1] = 588;   StageC64.AnimationCounter[TileX][TileY] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX+1][TileY-1] = 589; StageC64.AnimationCounter[TileX+1][TileY] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX-1][TileY] = 627;   StageC64.AnimationCounter[TileX-1][TileY-1] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX][TileY] = 628;     StageC64.AnimationCounter[TileX][TileY-1] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX+1][TileY] = 629;   StageC64.AnimationCounter[TileX+1][TileY-1] = World.TileSwitchSpeed;
        SPRITE_PowerUp_Activate(TileX*TS.Tile_Width, (TileY-2)*TS.Tile_Height);
      }
    }
  }
}

// ##############################################
// ##############################################
// ##############################################

void PC_Collision_CoinBlock()
{
  int TileX, TileY;
  bool HitACoinBlock = false;

  if(PC.JumpVelocity > 0) // JUMPING UP
  {
    if(TileType[StageC64.TileNumber[(int)(PC.PosX/TS.Tile_Width)][(int)((PC.PosY-PC.ColHeight)/TS.Tile_Height)]].CoinBlock)
    {
      TileX = (int)(PC.PosX/TS.Tile_Width);
      TileY = (int)((PC.PosY-PC.ColHeight)/TS.Tile_Height);
      if(!TileType[StageC64.TileNumber[TileX][TileY+1]].Solid){HitACoinBlock = true;}
    }
    if(!HitACoinBlock && TileType[StageC64.TileNumber[(int)((PC.PosX-PC.ColWidthHalf+2)/TS.Tile_Width)][(int)((PC.PosY-PC.ColHeight)/TS.Tile_Height)]].CoinBlock)
    {
      TileX = (int)((PC.PosX-PC.ColWidthHalf+2)/TS.Tile_Width);
      TileY = (int)((PC.PosY-PC.ColHeight)/TS.Tile_Height);
      if(!TileType[StageC64.TileNumber[TileX][TileY+1]].Solid){HitACoinBlock = true;}
    }
    if(!HitACoinBlock && TileType[StageC64.TileNumber[(int)((PC.PosX+PC.ColWidthHalf-2)/TS.Tile_Width)][(int)((PC.PosY-PC.ColHeight)/TS.Tile_Height)]].CoinBlock)
    {
      TileX = (int)((PC.PosX+PC.ColWidthHalf-2)/TS.Tile_Width);
      TileY = (int)((PC.PosY-PC.ColHeight)/TS.Tile_Height);
      if(!TileType[StageC64.TileNumber[TileX][TileY+1]].Solid){HitACoinBlock = true;}
    }
    if(HitACoinBlock)
    {
      AUDIO_Sound_Play(AUDIO_DING);
      //timecounter_Animation_Tiles_Fast = SDL_GetTicks(); // RESET ANIMATION COUNTER
      if(StageC64.TileNumber[TileX-2][TileY] == StageC64.TileNumber[TileX][TileY]-2 &&
         TileType[StageC64.TileNumber[TileX-2][TileY]].CoinBlock)
      {
        StageC64.TileNumber[TileX-2][TileY] += 3;   StageC64.AnimationCounter[TileX-2][TileY] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX-1][TileY] += 3;   StageC64.AnimationCounter[TileX-1][TileY] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX][TileY] += 3;     StageC64.AnimationCounter[TileX][TileY] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX-2][TileY-1] += 3; StageC64.AnimationCounter[TileX-2][TileY-1] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX-1][TileY-1] += 3; StageC64.AnimationCounter[TileX-1][TileY-1] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX][TileY-1] += 3;   StageC64.AnimationCounter[TileX][TileY-1] = World.TileSwitchSpeed;
        HitACoinBlock = false;
        SPRITE_SmallCoin_Activate((TileX-1)*TS.Tile_Width, (TileY-2)*TS.Tile_Height);
      }
      if(HitACoinBlock && StageC64.TileNumber[TileX+2][TileY] == StageC64.TileNumber[TileX][TileY]+2 &&
         TileType[StageC64.TileNumber[TileX+2][TileY]].CoinBlock)
      {
        StageC64.TileNumber[TileX+2][TileY] += 3;   StageC64.AnimationCounter[TileX+2][TileY] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX+1][TileY] += 3;   StageC64.AnimationCounter[TileX+1][TileY] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX][TileY] += 3;     StageC64.AnimationCounter[TileX][TileY] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX+2][TileY-1] += 3; StageC64.AnimationCounter[TileX+2][TileY-1] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX+1][TileY-1] += 3; StageC64.AnimationCounter[TileX+1][TileY-1] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX][TileY-1] += 3;   StageC64.AnimationCounter[TileX][TileY-1] = World.TileSwitchSpeed;
        HitACoinBlock = false;
        SPRITE_SmallCoin_Activate((TileX+1)*TS.Tile_Width, (TileY-2)*TS.Tile_Height);
      }
      if(HitACoinBlock &&
         StageC64.TileNumber[TileX+1][TileY] == StageC64.TileNumber[TileX][TileY]+1 &&
         StageC64.TileNumber[TileX-1][TileY] == StageC64.TileNumber[TileX][TileY]-1 &&
         TileType[StageC64.TileNumber[TileX+1][TileY]].CoinBlock &&
         TileType[StageC64.TileNumber[TileX-1][TileY]].CoinBlock)
      {
        StageC64.TileNumber[TileX-1][TileY] += 3;   StageC64.AnimationCounter[TileX-1][TileY] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX+1][TileY] += 3;   StageC64.AnimationCounter[TileX+1][TileY] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX][TileY] += 3;     StageC64.AnimationCounter[TileX][TileY] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX-1][TileY-1] += 3; StageC64.AnimationCounter[TileX-1][TileY-1] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX+1][TileY-1] += 3; StageC64.AnimationCounter[TileX+1][TileY-1] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX][TileY-1] += 3;   StageC64.AnimationCounter[TileX][TileY-1] = World.TileSwitchSpeed;
        SPRITE_SmallCoin_Activate(TileX*TS.Tile_Width, (TileY-2)*TS.Tile_Height);
      }
    }
  }
}

// ##############################################
// ##############################################
// ##############################################

void PC_Collision_CoinBlockHelmet()
{
  int TileX, TileY;
  bool HitACoinBlock = false;

  if(PC.JumpVelocity > 0) // JUMPING UP
  {
    if(TileType[StageC64.TileNumber[(int)(PC.PosX/TS.Tile_Width)][(int)((PC.PosY-PC.ColHeight)/TS.Tile_Height)]].CoinBlockHelmet)
    {
      TileX = (int)(PC.PosX/TS.Tile_Width);
      TileY = (int)((PC.PosY-PC.ColHeight)/TS.Tile_Height);
      if(!TileType[StageC64.TileNumber[TileX][TileY+1]].Solid){HitACoinBlock = true;}
    }
    if(!HitACoinBlock && TileType[StageC64.TileNumber[(int)((PC.PosX-PC.ColWidthHalf+2)/TS.Tile_Width)][(int)((PC.PosY-PC.ColHeight)/TS.Tile_Height)]].CoinBlockHelmet)
    {
      TileX = (int)((PC.PosX-PC.ColWidthHalf+2)/TS.Tile_Width);
      TileY = (int)((PC.PosY-PC.ColHeight)/TS.Tile_Height);
      if(!TileType[StageC64.TileNumber[TileX][TileY+1]].Solid){HitACoinBlock = true;}
    }
    if(!HitACoinBlock && TileType[StageC64.TileNumber[(int)((PC.PosX+PC.ColWidthHalf-2)/TS.Tile_Width)][(int)((PC.PosY-PC.ColHeight)/TS.Tile_Height)]].CoinBlockHelmet)
    {
      TileX = (int)((PC.PosX+PC.ColWidthHalf-2)/TS.Tile_Width);
      TileY = (int)((PC.PosY-PC.ColHeight)/TS.Tile_Height);
      if(!TileType[StageC64.TileNumber[TileX][TileY+1]].Solid){HitACoinBlock = true;}
    }
    if(HitACoinBlock)
    {
       AUDIO_Sound_Play(AUDIO_DING);
      //timecounter_Animation_Tiles_Fast = SDL_GetTicks(); // RESET ANIMATION COUNTER
      if(StageC64.TileNumber[TileX-2][TileY] == StageC64.TileNumber[TileX][TileY]-2 &&
         TileType[StageC64.TileNumber[TileX-2][TileY]].CoinBlockHelmet)
      {
        StageC64.TileNumber[TileX-2][TileY] += 3;   StageC64.AnimationCounter[TileX-2][TileY] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX-1][TileY] += 3;   StageC64.AnimationCounter[TileX-1][TileY] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX][TileY] += 3;     StageC64.AnimationCounter[TileX][TileY] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX-2][TileY-1] += 3; StageC64.AnimationCounter[TileX-2][TileY-1] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX-1][TileY-1] += 3; StageC64.AnimationCounter[TileX-1][TileY-1] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX][TileY-1] += 3;   StageC64.AnimationCounter[TileX][TileY-1] = World.TileSwitchSpeed;
        HitACoinBlock = false;
        SPRITE_SmallCoin_Activate((TileX-1)*TS.Tile_Width, (TileY-2)*TS.Tile_Height);
      }
      if(HitACoinBlock && StageC64.TileNumber[TileX+2][TileY] == StageC64.TileNumber[TileX][TileY]+2 &&
         TileType[StageC64.TileNumber[TileX+2][TileY]].CoinBlockHelmet)
      {
        StageC64.TileNumber[TileX+2][TileY] += 3;   StageC64.AnimationCounter[TileX+2][TileY] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX+1][TileY] += 3;   StageC64.AnimationCounter[TileX+1][TileY] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX][TileY] += 3;     StageC64.AnimationCounter[TileX][TileY] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX+2][TileY-1] += 3; StageC64.AnimationCounter[TileX+2][TileY-1] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX+1][TileY-1] += 3; StageC64.AnimationCounter[TileX+1][TileY-1] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX][TileY-1] += 3;   StageC64.AnimationCounter[TileX][TileY-1] = World.TileSwitchSpeed;
        HitACoinBlock = false;
        SPRITE_SmallCoin_Activate((TileX+1)*TS.Tile_Width, (TileY-2)*TS.Tile_Height);
      }
      if(HitACoinBlock &&
         StageC64.TileNumber[TileX+1][TileY] == StageC64.TileNumber[TileX][TileY]+1 &&
         StageC64.TileNumber[TileX-1][TileY] == StageC64.TileNumber[TileX][TileY]-1 &&
         TileType[StageC64.TileNumber[TileX+1][TileY]].CoinBlockHelmet &&
         TileType[StageC64.TileNumber[TileX-1][TileY]].CoinBlockHelmet)
      {
        StageC64.TileNumber[TileX-1][TileY] += 3;   StageC64.AnimationCounter[TileX-1][TileY] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX+1][TileY] += 3;   StageC64.AnimationCounter[TileX+1][TileY] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX][TileY] += 3;     StageC64.AnimationCounter[TileX][TileY] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX-1][TileY-1] += 3; StageC64.AnimationCounter[TileX-1][TileY-1] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX+1][TileY-1] += 3; StageC64.AnimationCounter[TileX+1][TileY-1] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX][TileY-1] += 3;   StageC64.AnimationCounter[TileX][TileY-1] = World.TileSwitchSpeed;
        SPRITE_SmallCoin_Activate(TileX*TS.Tile_Width, (TileY-2)*TS.Tile_Height);
      }
    }
  }
}

// ##############################################
// ##############################################
// ##############################################

void PC_Collision_Breakable()
{
  int TileX, TileY;
  bool HitABreakable = false;

  if(PC.JumpVelocity > 0) // JUMPING UP
  {
    if(TileType[StageC64.TileNumber[(int)(PC.PosX/TS.Tile_Width)][(int)((PC.PosY-PC.ColHeight)/TS.Tile_Height)]].Breakable)
    {
      TileX = (int)(PC.PosX/TS.Tile_Width);
      TileY = (int)((PC.PosY-PC.ColHeight)/TS.Tile_Height);
      if(!TileType[StageC64.TileNumber[TileX][TileY+1]].Solid){HitABreakable = true;}
    }
    if(!HitABreakable && TileType[StageC64.TileNumber[(int)((PC.PosX-PC.ColWidthHalf+2)/TS.Tile_Width)][(int)((PC.PosY-PC.ColHeight)/TS.Tile_Height)]].Breakable)
    {
      TileX = (int)((PC.PosX-PC.ColWidthHalf+2)/TS.Tile_Width);
      TileY = (int)((PC.PosY-PC.ColHeight)/TS.Tile_Height);
      if(!TileType[StageC64.TileNumber[TileX][TileY+1]].Solid){HitABreakable = true;}
    }
    if(!HitABreakable && TileType[StageC64.TileNumber[(int)((PC.PosX+PC.ColWidthHalf-2)/TS.Tile_Width)][(int)((PC.PosY-PC.ColHeight)/TS.Tile_Height)]].Breakable)
    {
      TileX = (int)((PC.PosX+PC.ColWidthHalf-2)/TS.Tile_Width);
      TileY = (int)((PC.PosY-PC.ColHeight)/TS.Tile_Height);
      if(!TileType[StageC64.TileNumber[TileX][TileY+1]].Solid){HitABreakable = true;}
    }
    if(HitABreakable)
    {
      //timecounter_Animation_Tiles_Fast = SDL_GetTicks(); // RESET ANIMATION COUNTER
      if(StageC64.TileNumber[TileX-2][TileY] == StageC64.TileNumber[TileX][TileY]-2 &&
         TileType[StageC64.TileNumber[TileX-2][TileY]].Breakable)
      {
        StageC64.TileNumber[TileX-2][TileY] += 3;   StageC64.AnimationCounter[TileX-2][TileY] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX-1][TileY] += 3;   StageC64.AnimationCounter[TileX-1][TileY] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX][TileY] += 3;     StageC64.AnimationCounter[TileX][TileY] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX-2][TileY-1] += 3; StageC64.AnimationCounter[TileX-2][TileY-1] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX-1][TileY-1] += 3; StageC64.AnimationCounter[TileX-1][TileY-1] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX][TileY-1] += 3;   StageC64.AnimationCounter[TileX][TileY-1] = World.TileSwitchSpeed;
        HitABreakable = false;
        AUDIO_Sound_Play(AUDIO_CRACK);
      }
      if(HitABreakable && StageC64.TileNumber[TileX+2][TileY] == StageC64.TileNumber[TileX][TileY]+2 &&
         TileType[StageC64.TileNumber[TileX+2][TileY]].Breakable)
      {
        StageC64.TileNumber[TileX+2][TileY] += 3;   StageC64.AnimationCounter[TileX+2][TileY] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX+1][TileY] += 3;   StageC64.AnimationCounter[TileX+1][TileY] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX][TileY] += 3;     StageC64.AnimationCounter[TileX][TileY] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX+2][TileY-1] += 3; StageC64.AnimationCounter[TileX+2][TileY-1] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX+1][TileY-1] += 3; StageC64.AnimationCounter[TileX+1][TileY-1] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX][TileY-1] += 3;   StageC64.AnimationCounter[TileX][TileY-1] = World.TileSwitchSpeed;
        HitABreakable = false;
        AUDIO_Sound_Play(AUDIO_CRACK);
      }
      if(HitABreakable &&
         StageC64.TileNumber[TileX+1][TileY] == StageC64.TileNumber[TileX][TileY]+1 &&
         StageC64.TileNumber[TileX-1][TileY] == StageC64.TileNumber[TileX][TileY]-1 &&
         TileType[StageC64.TileNumber[TileX+1][TileY]].Breakable &&
         TileType[StageC64.TileNumber[TileX-1][TileY]].Breakable)
      {
        StageC64.TileNumber[TileX-1][TileY] += 3;   StageC64.AnimationCounter[TileX-1][TileY] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX+1][TileY] += 3;   StageC64.AnimationCounter[TileX+1][TileY] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX][TileY] += 3;     StageC64.AnimationCounter[TileX][TileY] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX-1][TileY-1] += 3; StageC64.AnimationCounter[TileX-1][TileY-1] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX+1][TileY-1] += 3; StageC64.AnimationCounter[TileX+1][TileY-1] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX][TileY-1] += 3;   StageC64.AnimationCounter[TileX][TileY-1] = World.TileSwitchSpeed;
        AUDIO_Sound_Play(AUDIO_CRACK);
      }
    }
  }
}

// ##############################################
// ##############################################
// ##############################################

void PC_Collision_DropStone()
{
  int TileX, TileY;
  bool HitABreakable = false;
  int DropStoneNumber = 0;
  int i;

  if(PC.JumpVelocity > 0) // JUMPING UP
  {
    if(TileType[StageC64.TileNumber[(int)(PC.PosX/TS.Tile_Width)][(int)((PC.PosY-PC.ColHeight)/TS.Tile_Height)]].DropStone)
    {
      TileX = (int)(PC.PosX/TS.Tile_Width);
      TileY = (int)((PC.PosY-PC.ColHeight)/TS.Tile_Height);
      if(!TileType[StageC64.TileNumber[TileX][TileY+1]].Solid){HitABreakable = true;}
    }
    if(!HitABreakable && TileType[StageC64.TileNumber[(int)((PC.PosX-PC.ColWidthHalf+2)/TS.Tile_Width)][(int)((PC.PosY-PC.ColHeight)/TS.Tile_Height)]].DropStone)
    {
      TileX = (int)((PC.PosX-PC.ColWidthHalf+2)/TS.Tile_Width);
      TileY = (int)((PC.PosY-PC.ColHeight)/TS.Tile_Height);
      if(!TileType[StageC64.TileNumber[TileX][TileY+1]].Solid){HitABreakable = true;}
    }
    if(!HitABreakable && TileType[StageC64.TileNumber[(int)((PC.PosX+PC.ColWidthHalf-2)/TS.Tile_Width)][(int)((PC.PosY-PC.ColHeight)/TS.Tile_Height)]].DropStone)
    {
      TileX = (int)((PC.PosX+PC.ColWidthHalf-2)/TS.Tile_Width);
      TileY = (int)((PC.PosY-PC.ColHeight)/TS.Tile_Height);
      if(!TileType[StageC64.TileNumber[TileX][TileY+1]].Solid){HitABreakable = true;}
    }

    if(HitABreakable)
    {
      for(i=1;i<30;i++){if(!Sprite_DropStone[i].inUse){DropStoneNumber = i;}}
      Sprite_DropStone[DropStoneNumber].inUse = true;
    }

    if(HitABreakable && DropStoneNumber > 0 && DropStoneNumber < 30)
    {
      if(StageC64.TileNumber[TileX-2][TileY] == StageC64.TileNumber[TileX][TileY]-2 &&
         TileType[StageC64.TileNumber[TileX-2][TileY]].DropStone)
      {
        Sprite_DropStone[DropStoneNumber].PosX = (TileX-2)*TS.Tile_Width;
        Sprite_DropStone[DropStoneNumber].PosY = (TileY-1)*TS.Tile_Width;

        StageC64.TileNumber[TileX-2][TileY] = 0;   StageC64.AnimationCounter[TileX-2][TileY] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX-1][TileY] = 0;   StageC64.AnimationCounter[TileX-1][TileY] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX][TileY] = 0;     StageC64.AnimationCounter[TileX][TileY] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX-2][TileY-1] = 0; StageC64.AnimationCounter[TileX-2][TileY-1] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX-1][TileY-1] = 0; StageC64.AnimationCounter[TileX-1][TileY-1] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX][TileY-1] = 0;   StageC64.AnimationCounter[TileX][TileY-1] = World.TileSwitchSpeed;
        HitABreakable = false;
        AUDIO_Sound_Play(AUDIO_CRACK);
      }
      if(HitABreakable && StageC64.TileNumber[TileX+2][TileY] == StageC64.TileNumber[TileX][TileY]+2 &&
         TileType[StageC64.TileNumber[TileX+2][TileY]].DropStone)
      {
        Sprite_DropStone[DropStoneNumber].PosX = (TileX)*TS.Tile_Width;
        Sprite_DropStone[DropStoneNumber].PosY = (TileY-1)*TS.Tile_Width;

        StageC64.TileNumber[TileX+2][TileY] = 0;   StageC64.AnimationCounter[TileX+2][TileY] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX+1][TileY] = 0;   StageC64.AnimationCounter[TileX+1][TileY] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX][TileY] = 0;     StageC64.AnimationCounter[TileX][TileY] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX+2][TileY-1] = 0; StageC64.AnimationCounter[TileX+2][TileY-1] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX+1][TileY-1] = 0; StageC64.AnimationCounter[TileX+1][TileY-1] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX][TileY-1] = 0;   StageC64.AnimationCounter[TileX][TileY-1] = World.TileSwitchSpeed;
        HitABreakable = false;
        AUDIO_Sound_Play(AUDIO_CRACK);
      }
      if(HitABreakable &&
         StageC64.TileNumber[TileX+1][TileY] == StageC64.TileNumber[TileX][TileY]+1 &&
         StageC64.TileNumber[TileX-1][TileY] == StageC64.TileNumber[TileX][TileY]-1 &&
         TileType[StageC64.TileNumber[TileX+1][TileY]].DropStone &&
         TileType[StageC64.TileNumber[TileX-1][TileY]].DropStone)
      {
        Sprite_DropStone[DropStoneNumber].PosX = (TileX-1)*TS.Tile_Width;
        Sprite_DropStone[DropStoneNumber].PosY = (TileY-1)*TS.Tile_Width;
        StageC64.TileNumber[TileX-1][TileY] = 0;   StageC64.AnimationCounter[TileX-1][TileY] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX+1][TileY] = 0;   StageC64.AnimationCounter[TileX+1][TileY] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX][TileY] = 0;     StageC64.AnimationCounter[TileX][TileY] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX-1][TileY-1] = 0; StageC64.AnimationCounter[TileX-1][TileY-1] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX+1][TileY-1] = 0; StageC64.AnimationCounter[TileX+1][TileY-1] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX][TileY-1] = 0;   StageC64.AnimationCounter[TileX][TileY-1] = World.TileSwitchSpeed;
        AUDIO_Sound_Play(AUDIO_CRACK);
      }
    }
  }
}

// ##############################################
// ##############################################
// ##############################################

void PC_Collision_WarpStone()
{
  int TileX, TileY;
  bool HitAWarpStone = false;

  if(PC.JumpVelocity > 0) // JUMPING UP
  {
    if(TileType[StageC64.TileNumber[(int)(PC.PosX/TS.Tile_Width)][(int)((PC.PosY-PC.ColHeight)/TS.Tile_Height)]].WarpStone)
    {
      TileX = (int)(PC.PosX/TS.Tile_Width);
      TileY = (int)((PC.PosY-PC.ColHeight)/TS.Tile_Height);
      if(!TileType[StageC64.TileNumber[TileX][TileY+1]].Solid){HitAWarpStone = true;}
    }
    if(!HitAWarpStone && TileType[StageC64.TileNumber[(int)((PC.PosX-PC.ColWidthHalf+2)/TS.Tile_Width)][(int)((PC.PosY-PC.ColHeight)/TS.Tile_Height)]].WarpStone)
    {
      TileX = (int)((PC.PosX-PC.ColWidthHalf+2)/TS.Tile_Width);
      TileY = (int)((PC.PosY-PC.ColHeight)/TS.Tile_Height);
      if(!TileType[StageC64.TileNumber[TileX][TileY+1]].Solid){HitAWarpStone = true;}
    }
    if(!HitAWarpStone && TileType[StageC64.TileNumber[(int)((PC.PosX+PC.ColWidthHalf-2)/TS.Tile_Width)][(int)((PC.PosY-PC.ColHeight)/TS.Tile_Height)]].WarpStone)
    {
      TileX = (int)((PC.PosX+PC.ColWidthHalf-2)/TS.Tile_Width);
      TileY = (int)((PC.PosY-PC.ColHeight)/TS.Tile_Height);
      if(!TileType[StageC64.TileNumber[TileX][TileY+1]].Solid){HitAWarpStone = true;}
    }

    if(HitAWarpStone)
    {
      PC.WarpCounter = PC_MORPHING_DURATION;
      PC.JumpOnGoing = false;
      PC.JumpVelocity = 0;
      PC.RunVelocity = 0;
    }


    if(HitAWarpStone)
    {
      if(StageC64.TileNumber[TileX-2][TileY] == StageC64.TileNumber[TileX][TileY]-2 &&
         TileType[StageC64.TileNumber[TileX-2][TileY]].WarpStone)
      {
        StageC64.TileNumber[TileX-2][TileY] = 603;   StageC64.AnimationCounter[TileX-2][TileY] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX-1][TileY] = 604;   StageC64.AnimationCounter[TileX-1][TileY] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX][TileY] = 605;     StageC64.AnimationCounter[TileX][TileY] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX-2][TileY-1] = 563; StageC64.AnimationCounter[TileX-2][TileY-1] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX-1][TileY-1] = 564; StageC64.AnimationCounter[TileX-1][TileY-1] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX][TileY-1] = 565;   StageC64.AnimationCounter[TileX][TileY-1] = World.TileSwitchSpeed;
        HitAWarpStone = false;
      }
      if(HitAWarpStone && StageC64.TileNumber[TileX+2][TileY] == StageC64.TileNumber[TileX][TileY]+2 &&
         TileType[StageC64.TileNumber[TileX+2][TileY]].WarpStone)
      {
        StageC64.TileNumber[TileX][TileY] = 603;     StageC64.AnimationCounter[TileX][TileY] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX+1][TileY] = 604;   StageC64.AnimationCounter[TileX+1][TileY] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX+2][TileY] = 605;   StageC64.AnimationCounter[TileX+2][TileY] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX][TileY-1] = 563;   StageC64.AnimationCounter[TileX][TileY-1] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX+1][TileY-1] = 564; StageC64.AnimationCounter[TileX+1][TileY-1] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX+2][TileY-1] = 565; StageC64.AnimationCounter[TileX+2][TileY-1] = World.TileSwitchSpeed;
        HitAWarpStone = false;
      }
      if(HitAWarpStone &&
         StageC64.TileNumber[TileX+1][TileY] == StageC64.TileNumber[TileX][TileY]+1 &&
         StageC64.TileNumber[TileX-1][TileY] == StageC64.TileNumber[TileX][TileY]-1 &&
         TileType[StageC64.TileNumber[TileX+1][TileY]].WarpStone &&
         TileType[StageC64.TileNumber[TileX-1][TileY]].WarpStone)
      {
        StageC64.TileNumber[TileX-1][TileY] = 603;   StageC64.AnimationCounter[TileX-1][TileY] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX][TileY] = 604;     StageC64.AnimationCounter[TileX][TileY] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX+1][TileY] = 605;   StageC64.AnimationCounter[TileX+1][TileY] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX-1][TileY-1] = 563; StageC64.AnimationCounter[TileX-1][TileY-1] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX][TileY-1] = 564;   StageC64.AnimationCounter[TileX][TileY-1] = World.TileSwitchSpeed;
        StageC64.TileNumber[TileX+1][TileY-1] = 565; StageC64.AnimationCounter[TileX+1][TileY-1] = World.TileSwitchSpeed;
      }
    }

  }
}

// ##############################################
// ##############################################
// ##############################################
