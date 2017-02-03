#include "globals.h"

// ##############################################
// ##############################################
// ##############################################

void drawGround(int Colour)
{
  SDL_Rect SrcRect;
  SDL_Rect DstRect;

  int j, i;
  int Height = (int)(GV.Screen_Height/TS.Tile_Height)+1;
  int Width = (int)(GV.Screen_Width/TS.Tile_Width);

  if(Colour == 0) // GRAY
  {
    SrcRect.x = 0*TS.Tile_Width;
    SrcRect.y = 3*TS.Tile_Height;
  }
  if(Colour == 1) // BLACK
  {
    SrcRect.x = 1*TS.Tile_Width;
    SrcRect.y = 3*TS.Tile_Height;
  }
  SrcRect.w = TS.Tile_Width;
  SrcRect.h = TS.Tile_Height;
  DstRect.w = SrcRect.w;
  DstRect.h = SrcRect.h;

  for(j=0;j<Height;j++)
  {
    for(i=0;i<Width;i++)
    {
      DstRect.x = i*TS.Tile_Width;
      DstRect.y = j*TS.Tile_Height;
      SDL_RenderCopyEx(gRenderer, InterfaceTexture, &SrcRect, &DstRect, 0, NULL, SDL_FLIP_NONE );
    }
  }
}

// ##############################################
// ##############################################
// ##############################################

void TILE_Draw(int x, int y, int Number)
{
  SDL_Rect SrcRect;
  SDL_Rect DstRect;

  SrcRect.x = TileType[Number].x;
  SrcRect.y = TileType[Number].y;
  SrcRect.w = TS.Tile_Width;
  SrcRect.h = TS.Tile_Height;
  DstRect.w = SrcRect.w;
  DstRect.h = SrcRect.h;
  DstRect.x = x;
  DstRect.y = y;

  // ANMIATE COIN
  if(TileType[Number].Coin)
  {
    SrcRect.x += (2 * ME.Frame_6 * TS.Tile_Width)-(3 * TS.Tile_Width);
    SrcRect.y += (52 * TS.Tile_Height);
  }

  // ANMIATE COIN BLOCKS
  if(TileType[Number].CoinBlock)
  {
    SrcRect.x += (3 * ME.Frame_6 * TS.Tile_Width);
    SrcRect.y -= (2 * TS.Tile_Height);
  }

  if(TileType[Number].PowerUpBlock)
  {
    SrcRect.x += (3 * ME.Frame_6 * TS.Tile_Width);
  }

  // ANIMATE LITTLE FLAMES
  if(Number > 9 && Number < 14)
  {
    SrcRect.x += (4 * ME.Frame_4 * TS.Tile_Width)+(2 * TS.Tile_Width);
    SrcRect.y += (57 * TS.Tile_Height);
  }

  // ANIMATE BIG FLAMES
  if((Number > 5 && Number < 10) || (Number > 45 && Number < 50))
  {
    SrcRect.x += (4 * ME.Frame_3 * TS.Tile_Width)-(6 * TS.Tile_Width);
    SrcRect.y += (55 * TS.Tile_Height);
  }

  // ANIMATE LAVA
  if(Number > 249 && Number < 253)
  {
    SrcRect.x += (3 * ME.Frame_3 * TS.Tile_Width)-(10 * TS.Tile_Width);
    SrcRect.y += (48 * TS.Tile_Height);
  }

  // CHANGE COLOUR OF TILE IF NECESSARY
  if(GV.Mode == MODE_GAMELOOP && TileType[Number].ColourChanging && StageC64.TileType > 0)
  {
    SrcRect.y += StageC64.TileType*(10 * TS.Tile_Height);
  }

  if(GV.Mode == MODE_EDITOR_STAGES && TileType[Number].ColourChanging && ME.TileType > 0)
  {
    SrcRect.y += ME.TileType*(10 * TS.Tile_Height);
  }

  // IF NOT IN MODE_GAMELOOP DRAW EVERYTHING
  if(GV.Mode != MODE_GAMELOOP)
  {
    SDL_RenderCopyEx(gRenderer, TilesTexture, &SrcRect, &DstRect, 0, NULL, SDL_FLIP_NONE );
  }

  // MAKE SURE NOT TO DRAW HIDDEN STUFF IN MODE_GAMELOOP
  if(GV.Mode == MODE_GAMELOOP && !TileType[Number].WarpStone)
  {
    SDL_RenderCopyEx(gRenderer, TilesTexture, &SrcRect, &DstRect, 0, NULL, SDL_FLIP_NONE );
  }
}

// ##############################################
// ##############################################
// ##############################################
