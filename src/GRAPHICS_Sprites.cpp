#include "globals.h"

Sprite_SmallCoinDefinition Sprite_SmallCoin[20];
Sprite_PowerUp_Definition Sprite_PowerUp[10];
Sprite_Bullet_Definition Sprite_Bullet;
Platform_Definition Platform;
DropStone_Definition Sprite_DropStone[30];

// ##############################################
// ##############################################
// ##############################################

void SPRITES_Define()
{
  int i, x;

  for(i=1;i<10;i++) // DON'T MESS WITH SMALLCOIN[0] - IT'S USED IN THE INTERFACE
  {
    Sprite_SmallCoin[i].PosX = -TS.Tile_Width;
    Sprite_SmallCoin[i].PosY = -TS.Tile_Height;
    Sprite_SmallCoin[i].JumpVelocity = 0;
    Sprite_SmallCoin[i].RunVelocity = 0;
    Sprite_SmallCoin[i].Active = false;
  }

  // SMALL COIN USED IN INTERFACE
  Sprite_SmallCoin[0].PosX = HUD.SmallCoinX;
  Sprite_SmallCoin[0].PosY = HUD.SmallCoinY;
  Sprite_SmallCoin[0].JumpVelocity = 0;
  Sprite_SmallCoin[0].RunVelocity = 0;
  Sprite_SmallCoin[0].Active = true;
  // SMALL COIN USED IN INTERFACE

  // LOAD POWERUP DEFINITIONS
  FILE* bonusfile;
  Uint32 temparray[40];  // 15*46
  bonusfile = fopen(FileName.PowerUpDefinition,  "r");
  if (bonusfile == NULL)
  {
    fprintf(stderr,"SPRITE DIMENSIONS NOT FOUND!!!");
  }
  else
  {
    for (x = 0; x < 40; x++){fscanf(bonusfile, "%i,", &temparray[x]);}
    x = 0;

    for(i=1; i<9; i++)
    {
      Sprite_PowerUp[i].x = temparray[x]; x++;
      Sprite_PowerUp[i].y = temparray[x]; x++;
      Sprite_PowerUp[i].w = temparray[x]; x++;
      Sprite_PowerUp[i].h = temparray[x]; x++;
      Sprite_PowerUp[i].PosX = -TS.Tile_Width;
      Sprite_PowerUp[i].PosY = -TS.Tile_Height;
      Sprite_PowerUp[i].JumpVelocity = 0;
      Sprite_PowerUp[i].RunVelocity = 0;
      Sprite_PowerUp[i].Active = false;
      Sprite_PowerUp[i].RunStrength = 10;
      Sprite_PowerUp[i].Direction = NPC_RIGHT;
    }
    Sprite_Bullet.x = temparray[x]; x++;
    Sprite_Bullet.y = temparray[x]; x++;
    Sprite_Bullet.w = temparray[x]; x++;
    Sprite_Bullet.h = temparray[x]; x++;
    Sprite_Bullet.PosX = 100;
    Sprite_Bullet.PosY = 100;
    Sprite_Bullet.Active = false;
    Sprite_Bullet.Direction = NPC_RIGHT;
    Sprite_Bullet.RunVelocity = 0;
    Sprite_Bullet.RunStrength = 25;
    Sprite_Bullet.VerticalDirection = 1;
  }
  fclose(bonusfile);


  Platform.Start_X = 15;
  Platform.Start_Y = 25;
  Platform.End_X = Platform.Start_X;
  Platform.End_Y = 10;
  Platform.PosX = Platform.Start_X*TS.Tile_Width;
  Platform.PosY = Platform.Start_Y*TS.Tile_Height;
  Platform.x = 192;
  Platform.y = 240;
  Platform.w = 144;
  Platform.h = 16;
  Platform.inUse = true;
  Platform.Direction = 1;

  for(i=1; i<30; i++)
  {
    Sprite_DropStone[i].x = 384;
    Sprite_DropStone[i].y = 224;
    Sprite_DropStone[i].w = 48;
    Sprite_DropStone[i].h = 32;
    Sprite_DropStone[i].PosX = 0;
    Sprite_DropStone[i].PosY = 0;
    Sprite_DropStone[i].inUse = false;
    Sprite_DropStone[i].JumpVelocity = 0;
  }
}

// ##############################################
// ##############################################
// ##############################################

void SPRITE_SmallCoin_Activate(int x, int y)
{
  int i;
  for(i=1; i<20; i++) // DON'T MESS WITH SMALLCOIN[0] - IT'S USED IN THE INTERFACE
  {
    if(!Sprite_SmallCoin[i].Active)
    {
      Sprite_SmallCoin[i].Active = true;
      Sprite_SmallCoin[i].PosX = x;
      Sprite_SmallCoin[i].PosY = y;
      Sprite_SmallCoin[i].JumpVelocity = 16;
      i = 20;
      PC.Coins += 1;
      if(PC.Coins > 99){PC.Coins = 0; PC.Lives++;}
    }
  }
}

// ##############################################
// ##############################################
// ##############################################

void SPRITE_PowerUp_Activate(int x, int y)
{
  int i;
  // SET ALL OTHER POWERUP-COINS TO INACTIVE
  for(i=1; i<10; i++)
  {
    Sprite_PowerUp[i].Active = false;
  }

  if(PC.PowerUp==8){i=8;}
  if(PC.PowerUp<8) {i=PC.PowerUp+1;}
  Sprite_PowerUp[i].Active = true;

  Sprite_PowerUp[i].PosX = x-8;
  Sprite_PowerUp[i].PosY = y-16;
  Sprite_PowerUp[i].JumpVelocity = 12;
  Sprite_PowerUp[i].RunVelocity = 0;
  Sprite_PowerUp[i].Direction = NPC_RIGHT;
}

// ##############################################
// ##############################################
// ##############################################
