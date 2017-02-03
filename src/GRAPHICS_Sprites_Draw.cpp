#include "globals.h"

void SPRITE_SmallCoin_Draw(int SmallCoinNumber);
void SPRITE_PowerUp_Draw(int PowerUpNumber);
void SPRITE_Platform_Draw();
void SPRITE_Bullet_Draw();
void SPRITE_Bullet_Explosion_Draw();
void SPRITE_DropStone_Draw(int DropStoneNumber);

// ##############################################
// ##############################################
// ##############################################

void SPRITES_Draw()
{
  int x;
  for (x = 0; x < 10; x++)
  {
    if(Sprite_SmallCoin[x].Active){SPRITE_SmallCoin_Draw(x);}
    if(Sprite_PowerUp[x].Active){SPRITE_PowerUp_Draw(x);}
  }
  if(Platform.inUse){SPRITE_Platform_Draw();}

  for (x = 1; x < 30; x++)
  {
    if(Sprite_DropStone[x].inUse){SPRITE_DropStone_Draw(x);}
  }

  if(Sprite_Bullet.Active){SPRITE_Bullet_Draw();}
  if(Sprite_Bullet.ExplosionAnimation > 0){SPRITE_Bullet_Explosion_Draw();}
}

// ##############################################
// ##############################################
// ##############################################

void SPRITE_PowerUp_Draw(int PowerUpNumber)
{
  SDL_Rect SrcRect;
  SDL_Rect DstRect;

  SrcRect.x = Sprite_PowerUp[PowerUpNumber].x;
  SrcRect.y = Sprite_PowerUp[PowerUpNumber].y;
  SrcRect.w = Sprite_PowerUp[PowerUpNumber].w;
  SrcRect.h = Sprite_PowerUp[PowerUpNumber].h;
  DstRect.w = SrcRect.w;
  DstRect.h = SrcRect.h;
  DstRect.x = Sprite_PowerUp[PowerUpNumber].PosX-PC.StagePosX;
  DstRect.y = Sprite_PowerUp[PowerUpNumber].PosY;

  SDL_RenderCopyEx(gRenderer, PowerUpTexture, &SrcRect, &DstRect, 0, NULL, SDL_FLIP_NONE );
}

// ##############################################
// ##############################################
// ##############################################

void SPRITE_SmallCoin_Draw(int SmallCoinNumber)
{
  SDL_Rect SrcRect;
  SDL_Rect DstRect;

  SrcRect.x = ME.Frame_6 * TS.Tile_Width;
  SrcRect.y = 912;


  SrcRect.w = TS.Tile_Width;
  SrcRect.h = TS.Tile_Height;
  DstRect.w = SrcRect.w;
  DstRect.h = SrcRect.h;
  DstRect.x = Sprite_SmallCoin[SmallCoinNumber].PosX-PC.StagePosX;
  DstRect.y = Sprite_SmallCoin[SmallCoinNumber].PosY;

  if(SmallCoinNumber == 0) // DON'T MESS WITH SMALLCOIN[0] - IT'S USED IN THE INTERFACE
  {
    DstRect.x = Sprite_SmallCoin[SmallCoinNumber].PosX;
    DstRect.y = Sprite_SmallCoin[SmallCoinNumber].PosY;
  }

  SDL_RenderCopyEx(gRenderer, TilesTexture, &SrcRect, &DstRect, 0, NULL, SDL_FLIP_NONE );
}

// ##############################################
// ##############################################
// ##############################################

void SPRITE_Platform_Draw()
{
  if(Platform.PosX - PC.PosX < 640)
  {
    SDL_Rect SrcRect;
    SDL_Rect DstRect;
    SrcRect.x = Platform.x;
    SrcRect.y = Platform.y;
    SrcRect.w = Platform.w;
    SrcRect.h = Platform.h;
    DstRect.w = SrcRect.w;
    DstRect.h = SrcRect.h;
    DstRect.x = (Platform.PosX) - PC.StagePosX;
    DstRect.y = (Platform.PosY);
    SDL_RenderCopyEx(gRenderer, TilesTexture, &SrcRect, &DstRect, 0, NULL, SDL_FLIP_NONE );
  }
}

// ##############################################
// ##############################################
// ##############################################

void SPRITE_Bullet_Draw()
{
  SDL_Rect SrcRect;
  SDL_Rect DstRect;

  SrcRect.x = Sprite_Bullet.x + (ME.Frame_4*Sprite_Bullet.w);
  SrcRect.y = Sprite_Bullet.y;
  SrcRect.w = Sprite_Bullet.w;
  SrcRect.h = Sprite_Bullet.h;
  DstRect.w = SrcRect.w;
  DstRect.h = SrcRect.h;
  DstRect.x = Sprite_Bullet.PosX-PC.StagePosX;
  DstRect.y = Sprite_Bullet.PosY;

  SDL_RenderCopyEx(gRenderer, PowerUpTexture, &SrcRect, &DstRect, 0, NULL, SDL_FLIP_NONE );

}
// ##############################################
// ##############################################
// ##############################################

void SPRITE_Bullet_Explosion_Draw()
{
  SDL_Rect SrcRect;
  SDL_Rect DstRect;

  SrcRect.x = 0;
  if(Sprite_Bullet.ExplosionAnimation < (Sprite_Bullet.ExplosionDuraion/2)){SrcRect.x = 32;}
  SrcRect.y = 272;
  SrcRect.w = 32;
  SrcRect.h = 32;
  DstRect.w = SrcRect.w;
  DstRect.h = SrcRect.h;
  DstRect.x = Sprite_Bullet.ExplosionX-PC.StagePosX;
  DstRect.y = Sprite_Bullet.ExplosionY-(SrcRect.h/2);

  SDL_RenderCopyEx(gRenderer, PowerUpTexture, &SrcRect, &DstRect, 0, NULL, SDL_FLIP_NONE );
}

// ##############################################
// ##############################################
// ##############################################


void SPRITE_DropStone_Draw(int DropStoneNumber)
{
  SDL_Rect SrcRect;
  SDL_Rect DstRect;

  SrcRect.x = Sprite_DropStone[DropStoneNumber].x;
  SrcRect.y = Sprite_DropStone[DropStoneNumber].y + StageC64.TileType*(10 * TS.Tile_Height);;
  SrcRect.w = Sprite_DropStone[DropStoneNumber].w;
  SrcRect.h = Sprite_DropStone[DropStoneNumber].h;
  DstRect.w = SrcRect.w;
  DstRect.h = SrcRect.h;
  DstRect.x = Sprite_DropStone[DropStoneNumber].PosX-PC.StagePosX;
  DstRect.y = Sprite_DropStone[DropStoneNumber].PosY;

  SDL_RenderCopyEx(gRenderer, TilesTexture, &SrcRect, &DstRect, 0, NULL, SDL_FLIP_NONE );
}

// ##############################################
// ##############################################
// ##############################################
