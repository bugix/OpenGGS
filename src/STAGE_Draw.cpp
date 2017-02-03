#include "globals.h"

void BACKGROUND_ELEMENTS_Outdoors_Draw();
void BACKGROUND_ELEMENTS_Indoors_Draw();
void Background_DrawATube(int x, int y, bool Fire);

// ##############################################
// ##############################################
// ##############################################

void STAGE_Draw()
{
  int x,y;

  if(PC.PosX < GV.Screen_Width/2)   {PC.StagePosX = 0;}
  if(PC.PosX+1 > GV.Screen_Width/2) {PC.StagePosX = PC.PosX-GV.Screen_Width/2;}
  if(PC.PosX+1-(GV.Screen_Width/2) > StageC64.StageWidthPixels-GV.Screen_Width) {PC.StagePosX = StageC64.StageWidthPixels-GV.Screen_Width;}

  //GV.ScreenWidthTiles = (int)(GV.Screen_Width/16);

  // BACKGROUND
  for(y=0; y<StageC64.StageHeight; y++)
  {
    for(x=0; x<GV.ScreenWidthTiles; x++)
    {
      if(StageC64.BackgroundColour == 0){TILE_Draw((x*TS.Tile_Width), y*TS.Tile_Height, 0);}  // BLUE BACKGROUND
      if(StageC64.BackgroundColour == 1){TILE_Draw((x*TS.Tile_Width), y*TS.Tile_Height, 40);} // BLACK BACKGROUND
    }
  }
  // BACKGROUND

  if(StageC64.BackgroundColour == 0){BACKGROUND_ELEMENTS_Outdoors_Draw();}
  if(StageC64.BackgroundColour == 1){BACKGROUND_ELEMENTS_Indoors_Draw();}

  if(TS.NextFrame)
  {
    for(y=0; y<StageC64.StageHeight; y++)
    {
      for(x=0; x<StageC64.StageWidth; x++)
      {
        if(StageC64.TileNumber[x][y] !=0)
        {
          SwitchTileToNextFrame(x, y);
        }
      }
    }
  }
  TS.NextFrame = false;

  for(y=0; y<StageC64.StageHeight; y++)
  {
    for(x=(int)(PC.StagePosX/16); x<(int)(PC.StagePosX/16)+GV.ScreenWidthTiles+1; x++)
    {
      if(StageC64.TileNumber[x][y] !=0)
      {
        TILE_Draw((x*TS.Tile_Width)-PC.StagePosX, y*TS.Tile_Height, StageC64.TileNumber[x][y]);
        if(GV.ShowDebugInfos_Tiles)
        {
          if(TileType[StageC64.TileNumber[x][y]].Exit)   {INTERFACE_Tile_Draw((x*TS.Tile_Width)-PC.StagePosX, y*TS.Tile_Height, INTERFACE_MARK_EXIT);}
          if(TileType[StageC64.TileNumber[x][y]].Lethal) {INTERFACE_Tile_Draw((x*TS.Tile_Width)-PC.StagePosX, y*TS.Tile_Height, INTERFACE_MARK_LETHAL);}
          if(TileType[StageC64.TileNumber[x][y]].Coin)   {INTERFACE_Tile_Draw((x*TS.Tile_Width)-PC.StagePosX, y*TS.Tile_Height, INTERFACE_MARK_COIN);}
        }
      }
    }
  }
}

// ##############################################
// ##############################################
// ##############################################

void BACKGROUND_ELEMENTS_Outdoors_Draw()
{
    int TileNumber = 104;
    int x;
    int CPosX;
    int CPosY;

    for(x=0; x<12; x++)
    {
      CPosX = BackGroundElements.CloudPosX[x];
      CPosY = BackGroundElements.CloudPosY[x];
      TILE_Draw(CPosX-int(PC.StagePosX/2)+(0*TS.Tile_Width), CPosY, TileNumber+0);
      TILE_Draw(CPosX-int(PC.StagePosX/2)+(1*TS.Tile_Width), CPosY, TileNumber+1);
      TILE_Draw(CPosX-int(PC.StagePosX/2)+(2*TS.Tile_Width), CPosY, TileNumber+2);
      TILE_Draw(CPosX-int(PC.StagePosX/2)+(3*TS.Tile_Width), CPosY, TileNumber+3);
      TILE_Draw(CPosX-int(PC.StagePosX/2)+(4*TS.Tile_Width), CPosY, TileNumber+4);
      TILE_Draw(CPosX-int(PC.StagePosX/2)+(0*TS.Tile_Width), CPosY+TS.Tile_Height, TileNumber+0+TS.Width);
      TILE_Draw(CPosX-int(PC.StagePosX/2)+(1*TS.Tile_Width), CPosY+TS.Tile_Height, TileNumber+1+TS.Width);
      TILE_Draw(CPosX-int(PC.StagePosX/2)+(2*TS.Tile_Width), CPosY+TS.Tile_Height, TileNumber+2+TS.Width);
      TILE_Draw(CPosX-int(PC.StagePosX/2)+(3*TS.Tile_Width), CPosY+TS.Tile_Height, TileNumber+3+TS.Width);
      TILE_Draw(CPosX-int(PC.StagePosX/2)+(4*TS.Tile_Width), CPosY+TS.Tile_Height, TileNumber+4+TS.Width);
     // PrintInt(CPosX-int(PC.StagePosX/2), CPosY, 1,0, x);
     // PrintInt(400, 10*x, 0,0, CPosX-int(PC.StagePosX/2));
     // PrintInt(480, 10*x, 0,0, BackGroundElements.CloudPosX[x]);
    }

  SDL_SetTextureAlphaMod(TilesTexture,100);
  CPosY = 440;
  CPosX = BackGroundElements.TubePosX[0]; Background_DrawATube(CPosX, CPosY, BackGroundElements.TubeFire[0]);
  CPosX = BackGroundElements.TubePosX[1]; Background_DrawATube(CPosX, CPosY, BackGroundElements.TubeFire[1]);
  CPosX = BackGroundElements.TubePosX[2]; Background_DrawATube(CPosX, CPosY, BackGroundElements.TubeFire[2]);
  CPosX = BackGroundElements.TubePosX[3]; Background_DrawATube(CPosX, CPosY, BackGroundElements.TubeFire[3]);
  SDL_SetTextureAlphaMod(TilesTexture,255);
}

void Background_DrawATube(int x, int y, bool Fire)
{
  int TileNumber = 514; // BIG TUBE
  int TubePosY;
  int z;

  for(z=0; z<2; z++)
  {
    TubePosY = y-(z*48);
    TILE_Draw(x-int(PC.StagePosX/2)+(0*TS.Tile_Width), TubePosY, TileNumber+0);
    TILE_Draw(x-int(PC.StagePosX/2)+(1*TS.Tile_Width), TubePosY, TileNumber+1);
    TILE_Draw(x-int(PC.StagePosX/2)+(2*TS.Tile_Width), TubePosY, TileNumber+2);
    TILE_Draw(x-int(PC.StagePosX/2)+(3*TS.Tile_Width), TubePosY, TileNumber+3);
    TILE_Draw(x-int(PC.StagePosX/2)+(4*TS.Tile_Width), TubePosY, TileNumber+4);
    TILE_Draw(x-int(PC.StagePosX/2)+(5*TS.Tile_Width), TubePosY, TileNumber+5);
    TILE_Draw(x-int(PC.StagePosX/2)+(0*TS.Tile_Width), TubePosY+TS.Tile_Height, TileNumber+0+TS.Width);
    TILE_Draw(x-int(PC.StagePosX/2)+(1*TS.Tile_Width), TubePosY+TS.Tile_Height, TileNumber+1+TS.Width);
    TILE_Draw(x-int(PC.StagePosX/2)+(2*TS.Tile_Width), TubePosY+TS.Tile_Height, TileNumber+2+TS.Width);
    TILE_Draw(x-int(PC.StagePosX/2)+(3*TS.Tile_Width), TubePosY+TS.Tile_Height, TileNumber+3+TS.Width);
    TILE_Draw(x-int(PC.StagePosX/2)+(4*TS.Tile_Width), TubePosY+TS.Tile_Height, TileNumber+4+TS.Width);
    TILE_Draw(x-int(PC.StagePosX/2)+(5*TS.Tile_Width), TubePosY+TS.Tile_Height, TileNumber+5+TS.Width);
    TILE_Draw(x-int(PC.StagePosX/2)+(0*TS.Tile_Width), TubePosY+(2*TS.Tile_Height), TileNumber+0+(2*TS.Width));
    TILE_Draw(x-int(PC.StagePosX/2)+(1*TS.Tile_Width), TubePosY+(2*TS.Tile_Height), TileNumber+1+(2*TS.Width));
    TILE_Draw(x-int(PC.StagePosX/2)+(2*TS.Tile_Width), TubePosY+(2*TS.Tile_Height), TileNumber+2+(2*TS.Width));
    TILE_Draw(x-int(PC.StagePosX/2)+(3*TS.Tile_Width), TubePosY+(2*TS.Tile_Height), TileNumber+3+(2*TS.Width));
    TILE_Draw(x-int(PC.StagePosX/2)+(4*TS.Tile_Width), TubePosY+(2*TS.Tile_Height), TileNumber+4+(2*TS.Width));
    TILE_Draw(x-int(PC.StagePosX/2)+(5*TS.Tile_Width), TubePosY+(2*TS.Tile_Height), TileNumber+5+(2*TS.Width));
  }

  if(Fire)
  {
    TileNumber = 6; // FIRE
    TILE_Draw(x-int(PC.StagePosX/2)+(1*TS.Tile_Width), TubePosY-(2*TS.Tile_Height), TileNumber+0);
    TILE_Draw(x-int(PC.StagePosX/2)+(2*TS.Tile_Width), TubePosY-(2*TS.Tile_Height), TileNumber+1);
    TILE_Draw(x-int(PC.StagePosX/2)+(3*TS.Tile_Width), TubePosY-(2*TS.Tile_Height), TileNumber+2);
    TILE_Draw(x-int(PC.StagePosX/2)+(4*TS.Tile_Width), TubePosY-(2*TS.Tile_Height), TileNumber+3);
    TILE_Draw(x-int(PC.StagePosX/2)+(1*TS.Tile_Width), TubePosY-(1*TS.Tile_Height), TileNumber+0+TS.Width);
    TILE_Draw(x-int(PC.StagePosX/2)+(2*TS.Tile_Width), TubePosY-(1*TS.Tile_Height), TileNumber+1+TS.Width);
    TILE_Draw(x-int(PC.StagePosX/2)+(3*TS.Tile_Width), TubePosY-(1*TS.Tile_Height), TileNumber+2+TS.Width);
    TILE_Draw(x-int(PC.StagePosX/2)+(4*TS.Tile_Width), TubePosY-(1*TS.Tile_Height), TileNumber+3+TS.Width);
  }
}

// ##############################################
// ##############################################
// ##############################################


void BACKGROUND_ELEMENTS_Indoors_Draw()
{
    int TileNumber = 672;
    int x, y;
    int CPosX = 0;
    int DrawPos;
    SDL_SetTextureAlphaMod(TilesTexture,100);

    for(x=0; x<84; x++)
    {
      DrawPos = CPosX-int(PC.StagePosX/2)+(0*TS.Tile_Width)+(x*2*TS.Tile_Width);
      if(DrawPos > -(2*TS.Tile_Width) && DrawPos < GV.Screen_Width) //ONLY DRAW WHAT'S VISIBLE
      {
        for(y=4; y<15; y++)
        {
          TILE_Draw(CPosX-int(PC.StagePosX/2)+(0*TS.Tile_Width)+(x*2*TS.Tile_Width), y*2*TS.Tile_Height, TileNumber+0);
          TILE_Draw(CPosX-int(PC.StagePosX/2)+(1*TS.Tile_Width)+(x*2*TS.Tile_Width), y*2*TS.Tile_Height, TileNumber+1);
          TILE_Draw(CPosX-int(PC.StagePosX/2)+(0*TS.Tile_Width)+(x*2*TS.Tile_Width), (y*2*TS.Tile_Height)+TS.Tile_Height, TileNumber+0+TS.Width);
          TILE_Draw(CPosX-int(PC.StagePosX/2)+(1*TS.Tile_Width)+(x*2*TS.Tile_Width), (y*2*TS.Tile_Height)+TS.Tile_Height, TileNumber+1+TS.Width);
/*
          TILE_Draw(CPosX-int(PC.StagePosX/2)+(0*TS.Tile_Width)+(x*2*TS.Tile_Width), CPosY, TileNumber+0);
          TILE_Draw(CPosX-int(PC.StagePosX/2)+(1*TS.Tile_Width)+(x*2*TS.Tile_Width), CPosY, TileNumber+1);
          TILE_Draw(CPosX-int(PC.StagePosX/2)+(0*TS.Tile_Width)+(x*2*TS.Tile_Width), CPosY+TS.Tile_Height, TileNumber+0+TS.Width);
          TILE_Draw(CPosX-int(PC.StagePosX/2)+(1*TS.Tile_Width)+(x*2*TS.Tile_Width), CPosY+TS.Tile_Height, TileNumber+1+TS.Width);
*/
        }
      }
    }
    SDL_SetTextureAlphaMod(TilesTexture,255);
}

// ##############################################
// ##############################################
// ##############################################
